/**
 *
 *  api_Kafka.h
 *
 */

#pragma once

#include "kafka/consumer/consumer.hpp"
#include "kafka/producer/producer.cpp"
#include <atomic>
#include <drogon/plugins/Plugin.h>
#include <functional>
#include <string>
#include <thread>

namespace api
{
    class Kafka : public drogon::Plugin<Kafka>
    {
    public:
        Kafka() {}
        /// This method must be called by drogon to initialize and start the plugin.
        /// It must be implemented by the user.
        void initAndStart(const Json::Value &config) override;

        /// This method must be called by drogon to shutdown the plugin.
        /// It must be implemented by the user.
        void shutdown() override;

        void SendMessage(std::string &message);

        void SetCallback(std::function<void(std::string)>);

    private:
        void Loop();

        std::atomic_bool run_{false};
        std::unique_ptr<Producer> producer_{};
        std::unique_ptr<Consumer> consumer_{};
        std::thread wait_messages_thread{};

        std::function<void(std::string)> callback_{};
    };

}
