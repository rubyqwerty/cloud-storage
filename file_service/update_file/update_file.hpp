#include "kafka_client/api_Kafka.h"
#include <drogon/HttpAppFramework.h>
#include <drogon/drogon.h>
#include <fmt/format.h>
#include <json/value.h>
#include <thread>
#include <trantor/utils/Logger.h>

namespace update_file
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

    inline void UpdateFileBeforeVerify(const std::string &message)
    {
        LOG_DEBUG << fmt::format("Получено подтверждение файла: {}", message);

        auto status{GetJson(message)};
        if (!status.has_value())
            return;

        auto verification{status.value()};

        auto id{verification["id"].asString()};
        auto verification_status{verification["status"].asString()};

        auto sql_command{
            fmt::format(R"(update file set verification_status="{}" where id={})", verification_status, id)};

        LOG_TRACE << fmt::format("SQL комманда для обновления файла: {}", sql_command);

        drogon::app().getDbClient()->execSqlAsync(
            sql_command,
            [id, verification_status](const drogon::orm::Result &result)
            {
                LOG_DEBUG << fmt::format("Поле <verification_status> у файла с id: <{}> было обновлено: {}", id,
                                         verification_status);
            },
            [](const drogon::orm::DrogonDbException &e) { LOG_ERROR << "error:" << e.base().what(); });
    }
}