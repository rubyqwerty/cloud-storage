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
#include <fmt/format.h>
#include <optional>
#include <regex>
#include <trantor/utils/Logger.h>

using namespace drogon;
using namespace cache;

void CacheManager::initAndStart(const Json::Value &config)
{

    is_cached_ = config["cache"].asBool();
    if (is_cached_)
    {
        LOG_DEBUG << "Служба кеширования запущена";
    }
    else
    {
        LOG_DEBUG << "Служба кеширования не активна ";
    }
}

void CacheManager::shutdown() {}

void CacheManager::AddCache(const std::string &key, const std::string &value)
{
    if (!is_cached_)
        return;

    drogon::app().getRedisClient()->execCommandAsync(
        [](const drogon::nosql::RedisResult &res) {}, [](const std::exception &err)
        { LOG_ERROR << "something failed!!! " << err.what(); }, "set %s %s EX 120", key.c_str(), value.c_str());

    LOG_DEBUG << fmt::format("Для пути {} добавлен кеш {}", key, value);
}

std::optional<std::string> CacheManager::GetCache(const std::string &key)
{
    if (!is_cached_)
        return {};

    return drogon::app().getRedisClient()->execCommandSync(
        [key](const nosql::RedisResult &res) -> std::optional<std::string>
        {
            if (res.isNil())
                return {};

            LOG_DEBUG << fmt::format("По запросу: {}\nВернулись кешированные данные: {}", key, res.asString());
            return res.asString();
        },
        "get %s", key.data());
}
