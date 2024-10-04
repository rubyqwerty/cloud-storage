
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

    auto is_docker{getenv("DOCKER")};
    std::string path{};
    if (is_docker)
    {
        path = "/app/configs/config.docker.json";
    }
    else
    {
        path = "../configs/config.json";
    }
    LOG_DEBUG << path;
    drogon::app().loadConfigFile(path);
    drogon::app().registerPostHandlingAdvice(AddHeader);
    drogon::app().run();
    return 0;
}
