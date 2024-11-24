#include <ctime>
#include <drogon/HttpAppFramework.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/drogon.h>
#include <thread>
#include <trantor/utils/Logger.h>

#include "verify/verify.hpp"

void AddHeader(const drogon::HttpRequestPtr &req, const drogon::HttpResponsePtr &res)
{
    res->addHeader("Access-Control-Allow-Origin", "*");
}

int main()
{

    auto config{getenv("USER_SERVICE_CONFIG")};
    std::string path{"config.json"};
    if (config)
    {
        path = config;
    }

    LOG_DEBUG << fmt::format("Используется конфиг: {}", path);

    drogon::app().loadConfigFile(path);
    drogon::app().registerPostHandlingAdvice(AddHeader);

    auto t{std::thread([&]() { drogon::app().run(); })};
    using namespace std::chrono;
    std::this_thread::sleep_for(1s);
    drogon::app().getPlugin<api::Kafka>()->SetCallback(verify::VerifyFile);
    t.join();
    return 0;
}
