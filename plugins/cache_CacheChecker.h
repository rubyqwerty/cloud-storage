/**
 *
 *  cache_CacheChecker.h
 *
 */

#pragma once

#include <drogon/HttpRequest.h>
#include <drogon/drogon_callbacks.h>
#include <drogon/plugins/Plugin.h>

namespace cache
{

    class CacheChecker : public drogon::Plugin<CacheChecker>
    {
    public:
        CacheChecker() {}
        /// This method must be called by drogon to initialize and start the plugin.
        /// It must be implemented by the user.
        void initAndStart(const Json::Value &config) override;

        /// This method must be called by drogon to shutdown the plugin.
        /// It must be implemented by the user.
        void shutdown() override;

    private:
        static void CheckCachedData(const drogon::HttpRequestPtr &req, drogon::AdviceCallback &&callback,
                                    drogon::AdviceChainCallback &&next_advice);

        static void AddCacheData(const drogon::HttpRequestPtr &req, const drogon::HttpResponsePtr &resp);
    };

}
