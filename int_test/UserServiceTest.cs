using System.Diagnostics;

namespace int_test;

[CollectionDefinition("Sequential Tests", DisableParallelization = true)]
public class UserServiceTests
{
    private readonly Handler<User, User> userHandler;
    private readonly string userLogin = "UserToTestName" + Process.GetCurrentProcess().Id.ToString();

    public UserServiceTests()
    {
        var user_service_url = TestConfig.Configuration["user_service_host"];

        userHandler = new(user_service_url);
    }

    [Fact]
    public async void PutUsers()
    {
        const int countUser = 20;

        List<User> users = new();

        for (int i = 0; i < countUser; ++i)
        {
            User user = new();
            user.login = userLogin + i.ToString();

            User created_user = new();
            var exception = await Record.ExceptionAsync(async () => created_user = await userHandler.Put(user));
            Assert.Null(exception);

            users.Add(created_user);
        }

        foreach (var user in users)
        {
            User created_user = new();
            var exception = await Record.ExceptionAsync(async () => created_user = await userHandler.GetOne(user.login));
            Assert.Equal(created_user.login, user.login);
        }
    }

    [Fact]
    public void GetAllUsers()
    {

        List<User> users = new();

        var exception = Record.Exception(() => users = userHandler.GetAll().Result);

        Assert.Null(exception);
    }

    [Fact]
    public async void DeleteAllUsers()
    {

        var users = await userHandler.GetAll();

        foreach (var user in users)
        {
            var exception = await Record.ExceptionAsync(async () => await userHandler.Delete(user.login));

            Assert.Null(exception);
        }

        users = userHandler.GetAll().Result;

        Assert.Equal(users.Count(), 0);
    }

    [Fact]
    public async void FailGet()
    {

        var exception = await Record.ExceptionAsync(async () => await userHandler.GetOne("unknowuser"));

        Assert.NotNull(exception);

        User user = new User { login = userLogin + "userToDeleteAndGet" };

        exception = await Record.ExceptionAsync(async () => await userHandler.Put(user));
        Assert.Null(exception);

        User addedUser = new();
        exception = await Record.ExceptionAsync(async () => addedUser = await userHandler.GetOne(user.login));
        Assert.Null(exception);

        Assert.Equal(addedUser.login, user.login);

        exception = await Record.ExceptionAsync(async () => await userHandler.Delete(addedUser.login));
        Assert.Null(exception);

        exception = await Record.ExceptionAsync(async () => addedUser = await userHandler.GetOne(user.login));
        Assert.NotNull(exception);
    }
}

