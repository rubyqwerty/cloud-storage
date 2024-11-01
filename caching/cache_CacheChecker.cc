/**
 *
 *  cache_CacheManager.cc
 *
 */

#include "cache_CacheChecker.h"
#include <drogon/HttpAppFramework.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/drogon.h>
#include <drogon/nosql/RedisException.h>
#include <drogon/nosql/RedisResult.h>
#include <optional>
#include <regex>
#include <trantor/utils/Logger.h>

using namespace drogon;
using namespace cache;

void CacheManager::initAndStart(const Json::Value &config) { LOG_DEBUG << "Служба кеширования запущена"; }

void CacheManager::shutdown() {}

void CacheManager::AddCache(const std::string &key, const std::string &value)
{
    drogon::app().getRedisClient()->execCommandAsync(
        [](const drogon::nosql::RedisResult &res) {}, [](const std::exception &err)
        { LOG_ERROR << "something failed!!! " << err.what(); }, "set %s %s EX 120", key.c_str(), value.c_str());
}

std::optional<std::string> CacheManager::GetCache(const std::string &key)
{

    return drogon::app().getRedisClient()->execCommandSync(
        [](const nosql::RedisResult &res) -> std::optional<std::string>
        {
            if (res.isNil())
                return {};
            return res.asString();
        },
        "get %s", key.data());
}
