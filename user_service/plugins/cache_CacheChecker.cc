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
#include <regex>
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
    if (!IsCached(req))
    {
        next_advice();
        return;
    }

    drogon::app().getRedisClient()->execCommandAsync(
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

    if (resp->statusCode() != HttpStatusCode::k200OK || !IsCached(req))
    {
        return;
    }

    Json::StreamWriterBuilder builder;
    auto value{Json::writeString(builder, *resp->getJsonObject())};

    std::string key{req->path()};

    drogon::app().getRedisClient()->execCommandAsync(
        [](const drogon::nosql::RedisResult &res) {}, [](const std::exception &err)
        { LOG_ERROR << "something failed!!! " << err.what(); }, "set %s %s EX 120", key.c_str(), value.c_str());
}

bool CacheChecker::IsCached(const drogon::HttpRequestPtr &req)
{
    auto reg{std::regex(".*/user/[0-9]{1,5}")};

    auto key{req->path()};

    if (std::regex_match(key, reg) && req->method() == drogon::HttpMethod::Get)
    {
        return true;
    }

    return false;
}
