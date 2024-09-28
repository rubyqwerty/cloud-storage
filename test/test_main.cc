#include <array>
#include <drogon/HttpClient.h>
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <json/forwards.h>
#include <json/reader.h>
#include <sstream>
#include <string>
#include <vector>
#define DROGON_TEST_MAIN
#include "models/User.h"
#include <drogon/drogon.h>
#include <drogon/drogon_test.h>

using namespace drogon;

using namespace drogon_model::cloud_storage;

HttpClientPtr GetClient()
{
    static auto client{HttpClient::newHttpClient("http://127.0.0.1:5555")};
    return client;
}

std::vector<User> GetUsers()
{
    auto client{GetClient()};
    auto req = HttpRequest::newHttpRequest();
    req->setMethod(drogon::Get);
    req->setPath("/user");

    auto result{
        std::async([&]()
                   { return client->sendRequest(req); })};

    auto [status, response]{result.get()};
    auto body{response->getJsonObject()};

    std::vector<User> users{};
    for (auto json_user : (*body))
    {
        users.push_back(User{json_user});
    }

    return users;
}

Json::Value GetJsonUser(int number)
{
    Json::Value juser;
    juser["login"] = "Bob" + std::to_string(number);
    juser["phone"] = "8234" + std::to_string(number * 10 + number * 2345);
    return juser;
}

void PutUsers(int count = 10)
{
    auto client{GetClient()};
    std::string user;

    for (int i = 0; i < count; ++i)
    {
        auto req = HttpRequest::newHttpJsonRequest(GetJsonUser(i));
        req->setMethod(drogon::Post);
        req->setPath("/user");
        auto result{std::async([&]()
                               { return client->sendRequest(req); })};
        auto [status, response]{result.get()};
    }
}

void DeleteUsers()
{
    auto client{GetClient()};
    auto users{GetUsers()};

    auto count_users{users.size()};

    for (const auto &user : users)
    {
        auto req = HttpRequest::newHttpRequest();
        req->setMethod(drogon::Delete);
        req->setPath("/user/" + std::to_string(*user.getId()));
        auto result{std::async([&]()
                               { return client->sendRequest(req); })};
        auto [status, response]{result.get()};
    }
}

DROGON_TEST(CheckPutDelete)
{
    DeleteUsers();
    auto users{GetUsers()};
    CHECK(users.size() == 0);

    PutUsers(100);
    users = GetUsers();
    CHECK(users.size() == 100);

    PutUsers(200);
    users = GetUsers();
    CHECK(users.size() == 300);

    DeleteUsers();
    users = GetUsers();
    CHECK(users.size() == 0);
}

int main(int argc, char **argv)
{
    std::promise<void> p1;
    std::future<void> f1 = p1.get_future();

    // Start the main loop on another thread
    std::thread thr([&]()
                    {
        // Queues the promise to be fulfilled after starting the loop
        app().getLoop()->queueInLoop([&p1]() { p1.set_value(); });
        app().run(); });

    // The future is only satisfied after the event loop started
    f1.get();
    int status = test::run(argc, argv);

    // Ask the event loop to shutdown and wait
    app().getLoop()->queueInLoop([]()
                                 { app().quit(); });
    thr.join();
    return status;
}
