
#include "caching/cache_CacheChecker.h"
#include "kafka_client/api_Kafka.h"
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

    auto is_docker{getenv("DOCKER")};
    std::string path{};
    if (is_docker)
    {
        path = "/app/user_service/configs/config.docker.json";
    }
    else
    {
        path = "../../user_service/configs/config.json";
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
