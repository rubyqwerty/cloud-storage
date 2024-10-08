/**
 *
 *  Category.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Category.h"
#include "File.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::cloud_storage;

const std::string Category::Cols::_id = "id";
const std::string Category::Cols::_title = "title";
const std::string Category::Cols::_file_id = "file_id";
const std::string Category::primaryKeyName = "id";
const bool Category::hasPrimaryKey = true;
const std::string Category::tableName = "category";

const std::vector<typename Category::MetaData> Category::metaData_={
{"id","int32_t","int",4,1,1,1},
{"title","std::string","varchar(30)",30,0,0,1},
{"file_id","int32_t","int",4,0,0,1}
};
const std::string &Category::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Category::Category(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["title"].isNull())
        {
            title_=std::make_shared<std::string>(r["title"].as<std::string>());
        }
        if(!r["file_id"].isNull())
        {
            fileId_=std::make_shared<int32_t>(r["file_id"].as<int32_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 3 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            title_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            fileId_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
    }

}

Category::Category(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            title_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            fileId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
}

Category::Category(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("title"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["title"].isNull())
        {
            title_=std::make_shared<std::string>(pJson["title"].asString());
        }
    }
    if(pJson.isMember("file_id"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["file_id"].isNull())
        {
            fileId_=std::make_shared<int32_t>((int32_t)pJson["file_id"].asInt64());
        }
    }
}

void Category::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            title_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            fileId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
}

void Category::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("title"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["title"].isNull())
        {
            title_=std::make_shared<std::string>(pJson["title"].asString());
        }
    }
    if(pJson.isMember("file_id"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["file_id"].isNull())
        {
            fileId_=std::make_shared<int32_t>((int32_t)pJson["file_id"].asInt64());
        }
    }
}

const int32_t &Category::getValueOfId() const noexcept
{
    static const int32_t defaultValue = int32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Category::getId() const noexcept
{
    return id_;
}
void Category::setId(const int32_t &pId) noexcept
{
    id_ = std::make_shared<int32_t>(pId);
    dirtyFlag_[0] = true;
}
const typename Category::PrimaryKeyType & Category::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Category::getValueOfTitle() const noexcept
{
    static const std::string defaultValue = std::string();
    if(title_)
        return *title_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Category::getTitle() const noexcept
{
    return title_;
}
void Category::setTitle(const std::string &pTitle) noexcept
{
    title_ = std::make_shared<std::string>(pTitle);
    dirtyFlag_[1] = true;
}
void Category::setTitle(std::string &&pTitle) noexcept
{
    title_ = std::make_shared<std::string>(std::move(pTitle));
    dirtyFlag_[1] = true;
}

const int32_t &Category::getValueOfFileId() const noexcept
{
    static const int32_t defaultValue = int32_t();
    if(fileId_)
        return *fileId_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Category::getFileId() const noexcept
{
    return fileId_;
}
void Category::setFileId(const int32_t &pFileId) noexcept
{
    fileId_ = std::make_shared<int32_t>(pFileId);
    dirtyFlag_[2] = true;
}

void Category::updateId(const uint64_t id)
{
    id_ = std::make_shared<int32_t>(static_cast<int32_t>(id));
}

const std::vector<std::string> &Category::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "title",
        "file_id"
    };
    return inCols;
}

void Category::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getTitle())
        {
            binder << getValueOfTitle();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getFileId())
        {
            binder << getValueOfFileId();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Category::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    return ret;
}

void Category::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getTitle())
        {
            binder << getValueOfTitle();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getFileId())
        {
            binder << getValueOfFileId();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Category::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getTitle())
    {
        ret["title"]=getValueOfTitle();
    }
    else
    {
        ret["title"]=Json::Value();
    }
    if(getFileId())
    {
        ret["file_id"]=getValueOfFileId();
    }
    else
    {
        ret["file_id"]=Json::Value();
    }
    return ret;
}

Json::Value Category::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 3)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getTitle())
            {
                ret[pMasqueradingVector[1]]=getValueOfTitle();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getFileId())
            {
                ret[pMasqueradingVector[2]]=getValueOfFileId();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getTitle())
    {
        ret["title"]=getValueOfTitle();
    }
    else
    {
        ret["title"]=Json::Value();
    }
    if(getFileId())
    {
        ret["file_id"]=getValueOfFileId();
    }
    else
    {
        ret["file_id"]=Json::Value();
    }
    return ret;
}

bool Category::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("title"))
    {
        if(!validJsonOfField(1, "title", pJson["title"], err, true))
            return false;
    }
    else
    {
        err="The title column cannot be null";
        return false;
    }
    if(pJson.isMember("file_id"))
    {
        if(!validJsonOfField(2, "file_id", pJson["file_id"], err, true))
            return false;
    }
    else
    {
        err="The file_id column cannot be null";
        return false;
    }
    return true;
}
bool Category::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                  const std::vector<std::string> &pMasqueradingVector,
                                                  std::string &err)
{
    if(pMasqueradingVector.size() != 3)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[2] + " column cannot be null";
            return false;
        }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Category::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("title"))
    {
        if(!validJsonOfField(1, "title", pJson["title"], err, false))
            return false;
    }
    if(pJson.isMember("file_id"))
    {
        if(!validJsonOfField(2, "file_id", pJson["file_id"], err, false))
            return false;
    }
    return true;
}
bool Category::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                std::string &err)
{
    if(pMasqueradingVector.size() != 3)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Category::validJsonOfField(size_t index,
                                const std::string &fieldName,
                                const Json::Value &pJson,
                                std::string &err,
                                bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            if(pJson.isString() && std::strlen(pJson.asCString()) > 30)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 30)";
                return false;
            }

            break;
        case 2:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
    }
    return true;
}
File Category::getFile(const DbClientPtr &clientPtr) const {
    static const std::string sql = "select * from file where id = ?";
    Result r(nullptr);
    {
        auto binder = *clientPtr << sql;
        binder << *fileId_ << Mode::Blocking >>
            [&r](const Result &result) { r = result; };
        binder.exec();
    }
    if (r.size() == 0)
    {
        throw UnexpectedRows("0 rows found");
    }
    else if (r.size() > 1)
    {
        throw UnexpectedRows("Found more than one row");
    }
    return File(r[0]);
}

void Category::getFile(const DbClientPtr &clientPtr,
                       const std::function<void(File)> &rcb,
                       const ExceptionCallback &ecb) const
{
    static const std::string sql = "select * from file where id = ?";
    *clientPtr << sql
               << *fileId_
               >> [rcb = std::move(rcb), ecb](const Result &r){
                    if (r.size() == 0)
                    {
                        ecb(UnexpectedRows("0 rows found"));
                    }
                    else if (r.size() > 1)
                    {
                        ecb(UnexpectedRows("Found more than one row"));
                    }
                    else
                    {
                        rcb(File(r[0]));
                    }
               }
               >> ecb;
}
