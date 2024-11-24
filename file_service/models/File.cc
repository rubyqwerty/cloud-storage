/**
 *
 *  File.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "File.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::sqlite3;

const std::string File::Cols::_id = "id";
const std::string File::Cols::_file_name = "file_name";
const std::string File::Cols::_file_path = "file_path";
const std::string File::Cols::_verified_user = "verified_user";
const std::string File::Cols::_verification_status = "verification_status";
const std::string File::primaryKeyName = "id";
const bool File::hasPrimaryKey = true;
const std::string File::tableName = "file";

const std::vector<typename File::MetaData> File::metaData_={
{"id","int64_t","integer",8,1,1,0},
{"file_name","std::string","text",0,0,0,1},
{"file_path","std::string","text",0,0,0,1},
{"verified_user","std::string","text",0,0,0,0},
{"verification_status","std::string","text",0,0,0,0}
};
const std::string &File::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
File::File(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int64_t>(r["id"].as<int64_t>());
        }
        if(!r["file_name"].isNull())
        {
            fileName_=std::make_shared<std::string>(r["file_name"].as<std::string>());
        }
        if(!r["file_path"].isNull())
        {
            filePath_=std::make_shared<std::string>(r["file_path"].as<std::string>());
        }
        if(!r["verified_user"].isNull())
        {
            verifiedUser_=std::make_shared<std::string>(r["verified_user"].as<std::string>());
        }
        if(!r["verification_status"].isNull())
        {
            verificationStatus_=std::make_shared<std::string>(r["verification_status"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 5 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<int64_t>(r[index].as<int64_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            fileName_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            filePath_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            verifiedUser_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            verificationStatus_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

File::File(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 5)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int64_t>((int64_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            fileName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            filePath_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            verifiedUser_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            verificationStatus_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
}

File::File(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int64_t>((int64_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("file_name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["file_name"].isNull())
        {
            fileName_=std::make_shared<std::string>(pJson["file_name"].asString());
        }
    }
    if(pJson.isMember("file_path"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["file_path"].isNull())
        {
            filePath_=std::make_shared<std::string>(pJson["file_path"].asString());
        }
    }
    if(pJson.isMember("verified_user"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["verified_user"].isNull())
        {
            verifiedUser_=std::make_shared<std::string>(pJson["verified_user"].asString());
        }
    }
    if(pJson.isMember("verification_status"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["verification_status"].isNull())
        {
            verificationStatus_=std::make_shared<std::string>(pJson["verification_status"].asString());
        }
    }
}

void File::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 5)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int64_t>((int64_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            fileName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            filePath_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            verifiedUser_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            verificationStatus_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
}

void File::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int64_t>((int64_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("file_name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["file_name"].isNull())
        {
            fileName_=std::make_shared<std::string>(pJson["file_name"].asString());
        }
    }
    if(pJson.isMember("file_path"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["file_path"].isNull())
        {
            filePath_=std::make_shared<std::string>(pJson["file_path"].asString());
        }
    }
    if(pJson.isMember("verified_user"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["verified_user"].isNull())
        {
            verifiedUser_=std::make_shared<std::string>(pJson["verified_user"].asString());
        }
    }
    if(pJson.isMember("verification_status"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["verification_status"].isNull())
        {
            verificationStatus_=std::make_shared<std::string>(pJson["verification_status"].asString());
        }
    }
}

const int64_t &File::getValueOfId() const noexcept
{
    static const int64_t defaultValue = int64_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int64_t> &File::getId() const noexcept
{
    return id_;
}
void File::setId(const int64_t &pId) noexcept
{
    id_ = std::make_shared<int64_t>(pId);
    dirtyFlag_[0] = true;
}
void File::setIdToNull() noexcept
{
    id_.reset();
    dirtyFlag_[0] = true;
}
const typename File::PrimaryKeyType & File::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &File::getValueOfFileName() const noexcept
{
    static const std::string defaultValue = std::string();
    if(fileName_)
        return *fileName_;
    return defaultValue;
}
const std::shared_ptr<std::string> &File::getFileName() const noexcept
{
    return fileName_;
}
void File::setFileName(const std::string &pFileName) noexcept
{
    fileName_ = std::make_shared<std::string>(pFileName);
    dirtyFlag_[1] = true;
}
void File::setFileName(std::string &&pFileName) noexcept
{
    fileName_ = std::make_shared<std::string>(std::move(pFileName));
    dirtyFlag_[1] = true;
}

const std::string &File::getValueOfFilePath() const noexcept
{
    static const std::string defaultValue = std::string();
    if(filePath_)
        return *filePath_;
    return defaultValue;
}
const std::shared_ptr<std::string> &File::getFilePath() const noexcept
{
    return filePath_;
}
void File::setFilePath(const std::string &pFilePath) noexcept
{
    filePath_ = std::make_shared<std::string>(pFilePath);
    dirtyFlag_[2] = true;
}
void File::setFilePath(std::string &&pFilePath) noexcept
{
    filePath_ = std::make_shared<std::string>(std::move(pFilePath));
    dirtyFlag_[2] = true;
}

const std::string &File::getValueOfVerifiedUser() const noexcept
{
    static const std::string defaultValue = std::string();
    if(verifiedUser_)
        return *verifiedUser_;
    return defaultValue;
}
const std::shared_ptr<std::string> &File::getVerifiedUser() const noexcept
{
    return verifiedUser_;
}
void File::setVerifiedUser(const std::string &pVerifiedUser) noexcept
{
    verifiedUser_ = std::make_shared<std::string>(pVerifiedUser);
    dirtyFlag_[3] = true;
}
void File::setVerifiedUser(std::string &&pVerifiedUser) noexcept
{
    verifiedUser_ = std::make_shared<std::string>(std::move(pVerifiedUser));
    dirtyFlag_[3] = true;
}
void File::setVerifiedUserToNull() noexcept
{
    verifiedUser_.reset();
    dirtyFlag_[3] = true;
}

const std::string &File::getValueOfVerificationStatus() const noexcept
{
    static const std::string defaultValue = std::string();
    if(verificationStatus_)
        return *verificationStatus_;
    return defaultValue;
}
const std::shared_ptr<std::string> &File::getVerificationStatus() const noexcept
{
    return verificationStatus_;
}
void File::setVerificationStatus(const std::string &pVerificationStatus) noexcept
{
    verificationStatus_ = std::make_shared<std::string>(pVerificationStatus);
    dirtyFlag_[4] = true;
}
void File::setVerificationStatus(std::string &&pVerificationStatus) noexcept
{
    verificationStatus_ = std::make_shared<std::string>(std::move(pVerificationStatus));
    dirtyFlag_[4] = true;
}
void File::setVerificationStatusToNull() noexcept
{
    verificationStatus_.reset();
    dirtyFlag_[4] = true;
}

void File::updateId(const uint64_t id)
{
    id_ = std::make_shared<int64_t>(static_cast<int64_t>(id));
}

const std::vector<std::string> &File::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "file_name",
        "file_path",
        "verified_user",
        "verification_status"
    };
    return inCols;
}

void File::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getFileName())
        {
            binder << getValueOfFileName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getFilePath())
        {
            binder << getValueOfFilePath();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getVerifiedUser())
        {
            binder << getValueOfVerifiedUser();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getVerificationStatus())
        {
            binder << getValueOfVerificationStatus();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> File::updateColumns() const
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
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    if(dirtyFlag_[4])
    {
        ret.push_back(getColumnName(4));
    }
    return ret;
}

void File::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getFileName())
        {
            binder << getValueOfFileName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getFilePath())
        {
            binder << getValueOfFilePath();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getVerifiedUser())
        {
            binder << getValueOfVerifiedUser();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getVerificationStatus())
        {
            binder << getValueOfVerificationStatus();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value File::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=(Json::Int64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getFileName())
    {
        ret["file_name"]=getValueOfFileName();
    }
    else
    {
        ret["file_name"]=Json::Value();
    }
    if(getFilePath())
    {
        ret["file_path"]=getValueOfFilePath();
    }
    else
    {
        ret["file_path"]=Json::Value();
    }
    if(getVerifiedUser())
    {
        ret["verified_user"]=getValueOfVerifiedUser();
    }
    else
    {
        ret["verified_user"]=Json::Value();
    }
    if(getVerificationStatus())
    {
        ret["verification_status"]=getValueOfVerificationStatus();
    }
    else
    {
        ret["verification_status"]=Json::Value();
    }
    return ret;
}

Json::Value File::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 5)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=(Json::Int64)getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getFileName())
            {
                ret[pMasqueradingVector[1]]=getValueOfFileName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getFilePath())
            {
                ret[pMasqueradingVector[2]]=getValueOfFilePath();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getVerifiedUser())
            {
                ret[pMasqueradingVector[3]]=getValueOfVerifiedUser();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getVerificationStatus())
            {
                ret[pMasqueradingVector[4]]=getValueOfVerificationStatus();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=(Json::Int64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getFileName())
    {
        ret["file_name"]=getValueOfFileName();
    }
    else
    {
        ret["file_name"]=Json::Value();
    }
    if(getFilePath())
    {
        ret["file_path"]=getValueOfFilePath();
    }
    else
    {
        ret["file_path"]=Json::Value();
    }
    if(getVerifiedUser())
    {
        ret["verified_user"]=getValueOfVerifiedUser();
    }
    else
    {
        ret["verified_user"]=Json::Value();
    }
    if(getVerificationStatus())
    {
        ret["verification_status"]=getValueOfVerificationStatus();
    }
    else
    {
        ret["verification_status"]=Json::Value();
    }
    return ret;
}

bool File::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("file_name"))
    {
        if(!validJsonOfField(1, "file_name", pJson["file_name"], err, true))
            return false;
    }
    else
    {
        err="The file_name column cannot be null";
        return false;
    }
    if(pJson.isMember("file_path"))
    {
        if(!validJsonOfField(2, "file_path", pJson["file_path"], err, true))
            return false;
    }
    else
    {
        err="The file_path column cannot be null";
        return false;
    }
    if(pJson.isMember("verified_user"))
    {
        if(!validJsonOfField(3, "verified_user", pJson["verified_user"], err, true))
            return false;
    }
    if(pJson.isMember("verification_status"))
    {
        if(!validJsonOfField(4, "verification_status", pJson["verification_status"], err, true))
            return false;
    }
    return true;
}
bool File::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                              const std::vector<std::string> &pMasqueradingVector,
                                              std::string &err)
{
    if(pMasqueradingVector.size() != 5)
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
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[4].empty())
      {
          if(pJson.isMember(pMasqueradingVector[4]))
          {
              if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
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
bool File::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
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
    if(pJson.isMember("file_name"))
    {
        if(!validJsonOfField(1, "file_name", pJson["file_name"], err, false))
            return false;
    }
    if(pJson.isMember("file_path"))
    {
        if(!validJsonOfField(2, "file_path", pJson["file_path"], err, false))
            return false;
    }
    if(pJson.isMember("verified_user"))
    {
        if(!validJsonOfField(3, "verified_user", pJson["verified_user"], err, false))
            return false;
    }
    if(pJson.isMember("verification_status"))
    {
        if(!validJsonOfField(4, "verification_status", pJson["verification_status"], err, false))
            return false;
    }
    return true;
}
bool File::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector,
                                            std::string &err)
{
    if(pMasqueradingVector.size() != 5)
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
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
      if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
      {
          if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
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
bool File::validJsonOfField(size_t index,
                            const std::string &fieldName,
                            const Json::Value &pJson,
                            std::string &err,
                            bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isInt64())
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
            break;
        case 2:
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
            break;
        case 3:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 4:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
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
