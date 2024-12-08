using System.Diagnostics;
using Microsoft.VisualStudio.TestPlatform.ObjectModel.Client;
using Xunit.Abstractions;

namespace int_test;

[Collection("Sequential Tests")]
public class AuthentificationTest
{
    private readonly Handler<User, User> userHandler;
    private readonly Handler<User, User> userHandlerGateway;
    private readonly LoginHandler loginHandler;
    private readonly string testLogin = "bob123" + Process.GetCurrentProcess().Id;
    private readonly string testPassword = "1234567989";
    private readonly User user;

    public AuthentificationTest()
    {
        var user_service_url = TestConfig.Configuration["user_service_host"];
        var gateway_service_url = TestConfig.Configuration["gateway_service_host"];
        var login_service_url = TestConfig.Configuration["login_service_host"];

        userHandler = new(user_service_url);
        userHandlerGateway = new(gateway_service_url);
        loginHandler = new(login_service_url);

        user = new();
        user.login = testLogin;
        user.password = testPassword;
    }

    [Fact]
    public async void Login()
    {
        await userHandler.Put(user);

        var exception = Record.Exception(() => loginHandler.Login(testLogin, testPassword).Result);

        await userHandler.Delete(user.login);

        Assert.Null(exception);
    }

    [Fact]
    public async void FailLogin()
    {
        await userHandler.Put(user);

        var exception = Record.Exception(() => loginHandler.Login("fake", testPassword).Result);

        await userHandler.Delete(user.login);

        Assert.NotNull(exception);
    }

    [Fact]
    public async void Auth()
    {
        var exception = Record.Exception(() => userHandlerGateway.GetAll().Result);
        Assert.NotNull(exception);

        await userHandler.Put(user);

        var token = loginHandler.Login(testLogin, testPassword).Result;

        userHandlerGateway.SetAccesToken(token);

        exception = Record.Exception(() => userHandlerGateway.GetAll().Result);

        await userHandler.Delete(user.login);

        Assert.Null(exception);
    }




}