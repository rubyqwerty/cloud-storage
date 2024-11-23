/**
 *
 *  api_Kafka.cc
 *
 */

#include "api_Kafka.h"
#include <functional>
#include <memory>
#include <string>
#include <trantor/utils/Logger.h>
#include <utility>

using namespace drogon;
using namespace api;

void Kafka::initAndStart(const Json::Value &config)
{
    auto broker{config["broker"].asString()};

    auto consumer_topic{config["write_topic"].asString()};
    auto producer_topic{config["read_topic"].asString()};

    producer_ = std::make_unique<Producer>(broker, producer_topic);
    consumer_ = std::make_unique<Consumer>(broker, consumer_topic, "test");

    run_ = true;

    wait_messages_thread = std::thread(&Kafka::Loop, this);

    LOG_DEBUG << "Служба обработки сообщений Kafka запущена";
}

void Kafka::SendMessage(std::string &message) { producer_->SendMessage(message); }

void Kafka::Loop()
{
    LOG_DEBUG << "Запущен поток обработки сообщений Kafka";
    while (run_)
    {
        auto message{consumer_->GetMessage()};
        if (message.has_value())
        {
            LOG_TRACE << fmt::format("Kafka получено сообщение: {}", message.value());
            callback_(message.value());

            continue;
        }

        LOG_TRACE << fmt::format("Kafka буффер пуст");
    }
    LOG_DEBUG << "Поток обработки сообщений Kafka остановлен";
}

void Kafka::SetCallback(std::function<void(std::string)> callback)
{
    LOG_DEBUG << "Установлен callback для обработки сообщений Kafka";
    callback_ = std::move(callback);
}

void Kafka::shutdown()
{
    run_ = false;
    wait_messages_thread.join();
}
