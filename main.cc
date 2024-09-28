
#include <drogon/drogon.h>

void AddHeader(const drogon::HttpRequestPtr &req, const drogon::HttpResponsePtr &res)
{
    res->addHeader("Access-Control-Allow-Origin", "*");
    LOG_INFO << "New request: " << req->getMethodString() << " " << req->getOriginalPath();
}

int main()
{
    drogon::app().loadConfigFile("/app/configs/config.json");
    drogon::app().registerPostHandlingAdvice(AddHeader);
    drogon::app().run();
    return 0;
}
