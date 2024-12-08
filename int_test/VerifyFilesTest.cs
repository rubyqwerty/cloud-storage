using System.Diagnostics;

namespace int_test;

[Collection("Sequential Tests")]
public class VerifyFilesTests
{
    private readonly Handler<User, User> userHandler;
    private readonly Handler<File, FileWithoutId> fileHandler;
    private readonly string testLogin = "VerifyUserBob" + Process.GetCurrentProcess().Id;
    private readonly string testPassword = "1234567989";
    private readonly User user;
    private readonly FileWithoutId file;

    public VerifyFilesTests()
    {
        var user_service_url = TestConfig.Configuration["user_service_host"];
        var file_service_url = TestConfig.Configuration["file_service_host"];

        userHandler = new(user_service_url);
        fileHandler = new(file_service_url);

        user = new();
        user.login = testLogin;
        user.password = testPassword;

        file = new();
        file.verified_user = testLogin;
    }

    [Fact]
    public async void Verify()
    {
        var exception = await Record.ExceptionAsync(async () => await userHandler.Put(user));
        Assert.Null(exception);

        File created_file = new();

        exception = await Record.ExceptionAsync(async () => created_file = await fileHandler.Put(file));
        Assert.Null(exception);

        Thread.Sleep(2000);

        File verified_file = new();

        exception = await Record.ExceptionAsync(async () => verified_file = await fileHandler.GetOne(created_file.id.ToString()));
        Assert.Null(exception);

        var is_verify = verified_file.verification_status.Contains("Verified");

        Assert.True(is_verify);

        await fileHandler.Delete(created_file.id.ToString());
    }

    [Fact]
    public async void FailVerify()
    {
        File created_file = new();

        var exception = await Record.ExceptionAsync(async () => created_file = await fileHandler.Put(file));
        Assert.Null(exception);

        Thread.Sleep(2000);

        File verified_file = new();

        exception = await Record.ExceptionAsync(async () => verified_file = await fileHandler.GetOne(created_file.id.ToString()));
        Assert.Null(exception);

        var is_verify = verified_file.verification_status.Contains("Verified");

        Assert.False(is_verify);
    }
}