#include "kafka_client/api_Kafka.h"
#include <chrono>
#include <ctime>
#include <drogon/HttpAppFramework.h>
#include <drogon/drogon.h>
#include <iomanip>
#include <json/reader.h>
#include <json/value.h>
#include <optional>
#include <sstream>
#include <string>
#include <trantor/utils/Logger.h>

namespace verify
{
    inline std::optional<Json::Value> GetJson(const std::string &value)
    {
        Json::Value json_value;
        Json::CharReaderBuilder builder;
        std::string errstr;

        std::stringstream json_stream{value};
        auto status = Json::parseFromStream(builder, json_stream, &json_value, &errstr);

        if (!status)
        {
            LOG_WARN << fmt::format("Ошибка преобразования в json: {}", value);
            return {};
        }

        return json_value;
    }

    inline void VerifyFile(const std::string &message)
    {
        auto status{GetJson(message)};

        if (!status.has_value())
            return;

        auto file = status.value();
        auto id_user{file["verified_user"].asString()};
        // TODO проверить наличие пользователя
        auto id_file{file["id"].asString()};

        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);

        std::stringstream verify_time_stream;
        verify_time_stream << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");

        std::string verify_status{verify_time_stream.str()};

        Json::Value response{};
        response["id"] = id_file;
        response["status"] = verify_status;

        Json::StreamWriterBuilder builder;
        auto string_response{Json::writeString(builder, response)};

        drogon::app().getPlugin<api::Kafka>()->SendMessage(string_response);

        LOG_DEBUG << fmt::format("Для запроса {} отправлено подтверждение {}", message, string_response);
    }

}
