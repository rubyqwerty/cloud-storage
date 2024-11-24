/**
 *
 *  User.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "User.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::sqlite3;

const std::string User::Cols::_login = "login";
const std::string User::Cols::_password = "password";
const std::string User::Cols::_phone = "phone";
const std::string User::Cols::_file_count = "file_count";
const std::string User::primaryKeyName = "login";
const bool User::hasPrimaryKey = true;
const std::string User::tableName = "user";

const std::vector<typename User::MetaData> User::metaData_={
{"login","std::string","text",0,0,1,0},
{"password","std::string","text",0,0,0,1},
{"phone","std::string","text",0,0,0,0},
{"file_count","int64_t","integer",8,0,0,0}
};
const std::string &User::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
User::User(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["login"].isNull())
        {
            login_=std::make_shared<std::string>(r["login"].as<std::string>());
        }
        if(!r["password"].isNull())
        {
            password_=std::make_shared<std::string>(r["password"].as<std::string>());
        }
        if(!r["phone"].isNull())
        {
            phone_=std::make_shared<std::string>(r["phone"].as<std::string>());
        }
        if(!r["file_count"].isNull())
        {
            fileCount_=std::make_shared<int64_t>(r["file_count"].as<int64_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 4 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            login_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            password_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            phone_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            fileCount_=std::make_shared<int64_t>(r[index].as<int64_t>());
        }
    }

}

User::User(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            login_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            password_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            phone_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            fileCount_=std::make_shared<int64_t>((int64_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}

User::User(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("login"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["login"].isNull())
        {
            login_=std::make_shared<std::string>(pJson["login"].asString());
        }
    }
    if(pJson.isMember("password"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["password"].isNull())
        {
            password_=std::make_shared<std::string>(pJson["password"].asString());
        }
    }
    if(pJson.isMember("phone"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["phone"].isNull())
        {
            phone_=std::make_shared<std::string>(pJson["phone"].asString());
        }
    }
    if(pJson.isMember("file_count"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["file_count"].isNull())
        {
            fileCount_=std::make_shared<int64_t>((int64_t)pJson["file_count"].asInt64());
        }
    }
}

void User::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            login_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            password_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            phone_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            fileCount_=std::make_shared<int64_t>((int64_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}

void User::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("login"))
    {
        if(!pJson["login"].isNull())
        {
            login_=std::make_shared<std::string>(pJson["login"].asString());
        }
    }
    if(pJson.isMember("password"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["password"].isNull())
        {
            password_=std::make_shared<std::string>(pJson["password"].asString());
        }
    }
    if(pJson.isMember("phone"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["phone"].isNull())
        {
            phone_=std::make_shared<std::string>(pJson["phone"].asString());
        }
    }
    if(pJson.isMember("file_count"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["file_count"].isNull())
        {
            fileCount_=std::make_shared<int64_t>((int64_t)pJson["file_count"].asInt64());
        }
    }
}

const std::string &User::getValueOfLogin() const noexcept
{
    static const std::string defaultValue = std::string();
    if(login_)
        return *login_;
    return defaultValue;
}
const std::shared_ptr<std::string> &User::getLogin() const noexcept
{
    return login_;
}
void User::setLogin(const std::string &pLogin) noexcept
{
    login_ = std::make_shared<std::string>(pLogin);
    dirtyFlag_[0] = true;
}
void User::setLogin(std::string &&pLogin) noexcept
{
    login_ = std::make_shared<std::string>(std::move(pLogin));
    dirtyFlag_[0] = true;
}
void User::setLoginToNull() noexcept
{
    login_.reset();
    dirtyFlag_[0] = true;
}
const typename User::PrimaryKeyType & User::getPrimaryKey() const
{
    assert(login_);
    return *login_;
}

const std::string &User::getValueOfPassword() const noexcept
{
    static const std::string defaultValue = std::string();
    if(password_)
        return *password_;
    return defaultValue;
}
const std::shared_ptr<std::string> &User::getPassword() const noexcept
{
    return password_;
}
void User::setPassword(const std::string &pPassword) noexcept
{
    password_ = std::make_shared<std::string>(pPassword);
    dirtyFlag_[1] = true;
}
void User::setPassword(std::string &&pPassword) noexcept
{
    password_ = std::make_shared<std::string>(std::move(pPassword));
    dirtyFlag_[1] = true;
}

const std::string &User::getValueOfPhone() const noexcept
{
    static const std::string defaultValue = std::string();
    if(phone_)
        return *phone_;
    return defaultValue;
}
const std::shared_ptr<std::string> &User::getPhone() const noexcept
{
    return phone_;
}
void User::setPhone(const std::string &pPhone) noexcept
{
    phone_ = std::make_shared<std::string>(pPhone);
    dirtyFlag_[2] = true;
}
void User::setPhone(std::string &&pPhone) noexcept
{
    phone_ = std::make_shared<std::string>(std::move(pPhone));
    dirtyFlag_[2] = true;
}
void User::setPhoneToNull() noexcept
{
    phone_.reset();
    dirtyFlag_[2] = true;
}

const int64_t &User::getValueOfFileCount() const noexcept
{
    static const int64_t defaultValue = int64_t();
    if(fileCount_)
        return *fileCount_;
    return defaultValue;
}
const std::shared_ptr<int64_t> &User::getFileCount() const noexcept
{
    return fileCount_;
}
void User::setFileCount(const int64_t &pFileCount) noexcept
{
    fileCount_ = std::make_shared<int64_t>(pFileCount);
    dirtyFlag_[3] = true;
}
void User::setFileCountToNull() noexcept
{
    fileCount_.reset();
    dirtyFlag_[3] = true;
}

void User::updateId(const uint64_t id)
{
}

const std::vector<std::string> &User::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "login",
        "password",
        "phone",
        "file_count"
    };
    return inCols;
}

void User::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getLogin())
        {
            binder << getValueOfLogin();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getPassword())
        {
            binder << getValueOfPassword();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getPhone())
        {
            binder << getValueOfPhone();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getFileCount())
        {
            binder << getValueOfFileCount();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> User::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[0])
    {
        ret.push_back(getColumnName(0));
    }
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
    return ret;
}

void User::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getLogin())
        {
            binder << getValueOfLogin();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getPassword())
        {
            binder << getValueOfPassword();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getPhone())
        {
            binder << getValueOfPhone();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getFileCount())
        {
            binder << getValueOfFileCount();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value User::toJson() const
{
    Json::Value ret;
    if(getLogin())
    {
        ret["login"]=getValueOfLogin();
    }
    else
    {
        ret["login"]=Json::Value();
    }
    if(getPassword())
    {
        ret["password"]=getValueOfPassword();
    }
    else
    {
        ret["password"]=Json::Value();
    }
    if(getPhone())
    {
        ret["phone"]=getValueOfPhone();
    }
    else
    {
        ret["phone"]=Json::Value();
    }
    if(getFileCount())
    {
        ret["file_count"]=(Json::Int64)getValueOfFileCount();
    }
    else
    {
        ret["file_count"]=Json::Value();
    }
    return ret;
}

Json::Value User::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 4)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getLogin())
            {
                ret[pMasqueradingVector[0]]=getValueOfLogin();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getPassword())
            {
                ret[pMasqueradingVector[1]]=getValueOfPassword();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getPhone())
            {
                ret[pMasqueradingVector[2]]=getValueOfPhone();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getFileCount())
            {
                ret[pMasqueradingVector[3]]=(Json::Int64)getValueOfFileCount();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getLogin())
    {
        ret["login"]=getValueOfLogin();
    }
    else
    {
        ret["login"]=Json::Value();
    }
    if(getPassword())
    {
        ret["password"]=getValueOfPassword();
    }
    else
    {
        ret["password"]=Json::Value();
    }
    if(getPhone())
    {
        ret["phone"]=getValueOfPhone();
    }
    else
    {
        ret["phone"]=Json::Value();
    }
    if(getFileCount())
    {
        ret["file_count"]=(Json::Int64)getValueOfFileCount();
    }
    else
    {
        ret["file_count"]=Json::Value();
    }
    return ret;
}

bool User::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("login"))
    {
        if(!validJsonOfField(0, "login", pJson["login"], err, true))
            return false;
    }
    if(pJson.isMember("password"))
    {
        if(!validJsonOfField(1, "password", pJson["password"], err, true))
            return false;
    }
    else
    {
        err="The password column cannot be null";
        return false;
    }
    if(pJson.isMember("phone"))
    {
        if(!validJsonOfField(2, "phone", pJson["phone"], err, true))
            return false;
    }
    if(pJson.isMember("file_count"))
    {
        if(!validJsonOfField(3, "file_count", pJson["file_count"], err, true))
            return false;
    }
    return true;
}
bool User::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                              const std::vector<std::string> &pMasqueradingVector,
                                              std::string &err)
{
    if(pMasqueradingVector.size() != 4)
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
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
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
bool User::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("login"))
    {
        if(!validJsonOfField(0, "login", pJson["login"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("password"))
    {
        if(!validJsonOfField(1, "password", pJson["password"], err, false))
            return false;
    }
    if(pJson.isMember("phone"))
    {
        if(!validJsonOfField(2, "phone", pJson["phone"], err, false))
            return false;
    }
    if(pJson.isMember("file_count"))
    {
        if(!validJsonOfField(3, "file_count", pJson["file_count"], err, false))
            return false;
    }
    return true;
}
bool User::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector,
                                            std::string &err)
{
    if(pMasqueradingVector.size() != 4)
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
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool User::validJsonOfField(size_t index,
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
                return true;
            }
            if(!pJson.isString())
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
                return true;
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
            if(!pJson.isInt64())
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
