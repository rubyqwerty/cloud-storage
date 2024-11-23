/**
 *
 *  FileController.h
 *  This file is generated by drogon_ctl
 *
 */

#pragma once

#include "FileControllerBase.h"
#include "kafka_service/api_Kafka.h"
#include <drogon/HttpAppFramework.h>
#include <drogon/HttpController.h>
#include <drogon/plugins/Plugin.h>
#include <json/value.h>
#include <trantor/utils/Logger.h>

#include "File.h"
using namespace drogon;
using namespace drogon_model::sqlite3;
/**
 * @brief this class is created by the drogon_ctl command.
 * this class is a restful API controller for reading and writing the file table.
 */

class FileController : public drogon::HttpController<FileController>, public FileControllerBase
{
public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(FileController::getOne, "/file/{1}", Get, Options);
    ADD_METHOD_TO(FileController::updateOne, "/file/{1}", Put, Options);
    ADD_METHOD_TO(FileController::deleteOne, "/file/{1}", Delete, Options);
    ADD_METHOD_TO(FileController::get, "/file", Get, Options);
    ADD_METHOD_TO(FileController::create, "/file", Post, Options);
    // ADD_METHOD_TO(FileController::update,"/file",Put,Options);
    METHOD_LIST_END

    void getOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                File::PrimaryKeyType &&id);
    void updateOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                   File::PrimaryKeyType &&id);
    void deleteOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,
                   File::PrimaryKeyType &&id);
    void get(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
    void create(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);

    static void VerifyFile(const Json::Value &file)
    {
        auto client = drogon::app().getPlugin<api::Kafka>();

        Json::StreamWriterBuilder builder;
        auto value{Json::writeString(builder, file)};

        LOG_DEBUG << fmt::format("Verify file: {}", value);

        client->SendMessage(value);
    }
};
