/**
 *
 *  cache_CacheChecker.h
 *
 */

#pragma once

#include <drogon/HttpRequest.h>
#include <drogon/HttpTypes.h>
#include <drogon/drogon_callbacks.h>
#include <drogon/plugins/Plugin.h>
#include <optional>

namespace cache
{

    class CacheManager : public drogon::Plugin<CacheManager>
    {
    public:
        CacheManager() {}
        /// This method must be called by drogon to initialize and start the plugin.
        /// It must be implemented by the user.
        void initAndStart(const Json::Value &config) override;

        /// This method must be called by drogon to shutdown the plugin.
        /// It must be implemented by the user.
        void shutdown() override;

        void AddCache(const std::string &key, const std::string &value);

        std::optional<std::string> GetCache(const std::string &key);

    private:
        bool is_cached_;
    };

}
