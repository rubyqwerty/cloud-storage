#include "kafka_service/api_Kafka.h"
#include "update_file/update_file.hpp"
#include <drogon/HttpAppFramework.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/drogon.h>
#include <drogon/nosql/RedisClient.h>
#include <drogon/nosql/RedisResult.h>
#include <iterator>
#include <json/value.h>
#include <trantor/utils/Logger.h>

void AddHeader(const drogon::HttpRequestPtr &req, const drogon::HttpResponsePtr &res)
{
    res->addHeader("Access-Control-Allow-Origin", "*");
}

int main()
{

    auto config{getenv("FILE_SERVICE_CONFIG")};
    std::string path{"config.json"};
    if (config)
    {
        path = config;
    }

    LOG_DEBUG << fmt::format("Используется конфиг: {}", path);

    drogon::app().loadConfigFile(path);
    auto t{std::thread([&]() { drogon::app().run(); })};
    using namespace std::chrono;
    std::this_thread::sleep_for(1s);
    drogon::app().getPlugin<api::Kafka>()->SetCallback(update_file::UpdateFileBeforeVerify);
    t.join();
    return 0;
    return 0;
}
