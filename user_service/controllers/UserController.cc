/**
 *
 *  UserController.cc
 *  This file is generated by drogon_ctl
 *
 */

#include "UserController.h"
#include <string>


void UserController::getOne(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback,
                            User::PrimaryKeyType &&id)
{
    UserControllerBase::getOne(req, std::move(callback), std::move(id));
}


void UserController::updateOne(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback,
                               User::PrimaryKeyType &&id)
{
    UserControllerBase::updateOne(req, std::move(callback), std::move(id));
}


void UserController::deleteOne(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback,
                               User::PrimaryKeyType &&id)
{
    UserControllerBase::deleteOne(req, std::move(callback), std::move(id));
}

void UserController::get(const HttpRequestPtr &req,
                         std::function<void(const HttpResponsePtr &)> &&callback)
{
    UserControllerBase::get(req, std::move(callback));
}

void UserController::create(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback)
{
    UserControllerBase::create(req, std::move(callback));
}