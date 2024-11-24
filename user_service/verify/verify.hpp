#include "kafka_service/api_Kafka.h"
#include <chrono>
#include <ctime>
#include <drogon/HttpAppFramework.h>
#include <drogon/drogon.h>
#include <exception>
#include <fmt/format.h>
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

    inline bool CheckUser(const std::string &login)
    try
    {
        LOG_DEBUG << fmt::format("Проверка пользователя...");

        auto sql_command{fmt::format(R"(select (login) from user where login = "{}")", login)};

        auto status = drogon::app().getDbClient()->execSqlSync(sql_command);

        return status.size();
    }
    catch (const std::exception &ex)
    {
        LOG_WARN << fmt::format("Ошибка проверки пользователя: {}", ex.what());
        return false;
    }

    inline void VerifyFile(const std::string &message)
    {
        auto status{GetJson(message)};

        if (!status.has_value())
            return;

        auto file = status.value();
        auto login_user{file["verified_user"].asString()};
        auto check_status{CheckUser(login_user)};

        if (!check_status)
        {
            LOG_WARN << fmt::format("Файл не может быть верифицирован: отсутствует пользователь с login: {}",
                                    login_user);

            return;
        }
        auto id_file{file["id"].asString()};

        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);

        std::stringstream verify_time_stream;
        verify_time_stream << "Verified: " << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");

        Json::Value response{};
        response["id"] = id_file;
        response["status"] = verify_time_stream.str();

        Json::StreamWriterBuilder builder;
        auto string_response{Json::writeString(builder, response)};

        drogon::app().getPlugin<api::Kafka>()->SendMessage(string_response);

        LOG_DEBUG << fmt::format("Файл с id: {} верифицирован, отправлено подтверждение {}", id_file, string_response);
    }

}
