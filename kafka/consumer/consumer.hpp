#include <librdkafka/rdkafkacpp.h>
#include <memory>
#include <optional>
#include <string>
#include <vector>

using ConsumerPtr = std::unique_ptr<RdKafka::KafkaConsumer>;
using ConfPtr = std::unique_ptr<RdKafka::Conf>;
using MessagePtr = std::unique_ptr<RdKafka::Message>;

class Consumer
{
public:
    Consumer(const std::string &broker, const std::vector<std::string> &topics, std::string group_id);

    std::optional<std::string> GetMessage();

    ~Consumer() { consumer_->close(); }

private:
    void MakeConfig();
    void CheckStatus(const RdKafka::Conf::ConfResult &status, const std::string &errstr);
    void CheckStatus(const RdKafka::ErrorCode &code);

    RdKafka::KafkaConsumer *GetConsumer();

private:
    ConsumerPtr consumer_{};
    ConfPtr conf_{};

    std::string broker_{};
    std::vector<std::string> topics_{};
    std::string group_id_{};
};