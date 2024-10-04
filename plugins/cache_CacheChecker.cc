/**
 *
 *  cache_CacheChecker.cc
 *
 */

#include "cache_CacheChecker.h"
#include <drogon/HttpAppFramework.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/drogon.h>
#include <drogon/nosql/RedisException.h>
#include <trantor/utils/Logger.h>

using namespace drogon;
using namespace cache;

void CacheChecker::initAndStart(const Json::Value &config)
{
    if (config["cache"].asBool())
    {
        drogon::app().registerPreHandlingAdvice(CheckCachedData);
        drogon::app().registerPostHandlingAdvice(AddCacheData);
    }
}

void CacheChecker::shutdown()
{
    /// Shutdown the plugin
}

void CacheChecker::CheckCachedData(const drogon::HttpRequestPtr &req, drogon::AdviceCallback &&callback,
                                   drogon::AdviceChainCallback &&next_advice)
{
    if (req->method() != drogon::HttpMethod::Get)
    {
        next_advice();
        return;
    }

    auto redis_client{drogon::app().getRedisClient()};

    redis_client->execCommandAsync(
        [callback = std::move(callback), next_advice = std::move(next_advice)](const drogon::nosql::RedisResult &res)
        {
            if (res.isNil())
            {
                next_advice();
                return;
            }

            auto cached_data{res.asString()};

            auto response{
                drogon::HttpResponse::newHttpResponse(HttpStatusCode::k200OK, ContentType::CT_APPLICATION_JSON)};

            response->setBody(cached_data);

            callback(response);
        },
        [](const std::exception &err) { LOG_ERROR << "something failed!!! " << err.what(); }, "get %s",
        req->path().c_str());

    return;
}

void CacheChecker::AddCacheData(const drogon::HttpRequestPtr &req, const drogon::HttpResponsePtr &resp)
{

    auto redis_client{drogon::app().getRedisClient()};

    if (resp->statusCode() != HttpStatusCode::k200OK || req->method() != drogon::HttpMethod::Get)
    {

        redis_client->execCommandAsync([](const drogon::nosql::RedisResult &res) {}, [](const std::exception &err)
                                       { LOG_ERROR << "something failed!!! " << err.what(); }, "flushall");

        return;
    }

    auto key{req->path()};

    Json::StreamWriterBuilder builder;
    auto value{Json::writeString(builder, *resp->getJsonObject())};

    redis_client->execCommandAsync([](const drogon::nosql::RedisResult &res) {},
                                   [](const std::exception &err) { LOG_ERROR << "something failed!!! " << err.what(); },
                                   "set %s %s", key.c_str(), value.c_str());
}
