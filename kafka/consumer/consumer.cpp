#include "consumer.hpp"
#include "kafka-exception.hpp"

Consumer::Consumer(const std::string &broker, const std::vector<std::string> &topics, std::string group_id)
    : broker_(broker), topics_(topics), group_id_(group_id)
{
    MakeConfig();
    consumer_.reset(GetConsumer());

    auto status = consumer_->subscribe(topics_);
    CheckStatus(status);
};

std::optional<std::string> Consumer::GetMessage()
{

    MessagePtr message{consumer_->consume(100000)};
    if (message->err() == RdKafka::ERR_NO_ERROR)
    {
        int len = static_cast<int>(message->len());
        if (len > 0)
        {
            return std::string(static_cast<const char *>(message->payload()), len);
        }
    }

    return {};
}

void Consumer::MakeConfig()
{
    conf_.reset(RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL));
    std::string errstr{};

    auto status = conf_->set("bootstrap.servers", broker_, errstr);
    CheckStatus(status, errstr);
    status = conf_->set("group.id", group_id_, errstr);
    CheckStatus(status, errstr);
}

void Consumer::CheckStatus(const RdKafka::Conf::ConfResult &status, const std::string &errstr)
{
    if (status != RdKafka::Conf::CONF_OK)
    {
        throw KafkaException("Kafka configuration exception: {}", errstr);
    }
}

void Consumer::CheckStatus(const RdKafka::ErrorCode &code)
{
    if (code != RdKafka::ErrorCode::ERR_NO_ERROR)
    {
        throw KafkaException("Kafka exception: {}", RdKafka::err2str(code));
    }
}

RdKafka::KafkaConsumer *Consumer::GetConsumer()
{
    std::string errstr{};
    const auto consumer{RdKafka::KafkaConsumer::create(conf_.get(), errstr)};
    if (!consumer)
    {
        throw KafkaException("Ошибка создания потребителя: {}", errstr);
    }
    return consumer;
}