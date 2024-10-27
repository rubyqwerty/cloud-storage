#include "../kafka-exception.hpp"
#include <librdkafka/rdkafkacpp.h>
#include <memory>

using ProduserPtr = std::unique_ptr<RdKafka::Producer>;
using ConfPtr = std::unique_ptr<RdKafka::Conf>;

class Producer
{
public:
    Producer() = default;
    Producer(const std::string &broker, const std::string &topic) : topic_(topic)
    {
        ConfPtr conf{RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL)};

        std::string errstr{};
        conf->set("bootstrap.servers", broker, errstr);

        producer_.reset(RdKafka::Producer::create(conf.get(), errstr));

        if (!producer_)
        {
            throw KafkaException("Ошибка создания потребителя: {}", errstr);
        }
    };

    RdKafka::ErrorCode SendMessage(std::string &message)
    {
        return producer_->produce(topic_, RdKafka::Topic::PARTITION_UA, RdKafka::Producer::RK_MSG_COPY, message.data(),
                                  message.size(), NULL, 0, 0, NULL, NULL);
    }

    ~Producer() { producer_->flush(1000); }

private:
    ProduserPtr producer_{};

    std::string topic_{};
};
