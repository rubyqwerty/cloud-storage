using System.Diagnostics;

namespace int_test;

[Collection("Sequential Tests")]
public class FileServiceTests
{
    private readonly Handler<File, FileWithoutId> fileHandler;
    private readonly string fileName = "FileToTestName" + Process.GetCurrentProcess().Id.ToString();

    public FileServiceTests()
    {
        var file_service_url = TestConfig.Configuration["file_service_host"];

        fileHandler = new(file_service_url);
    }

    [Fact]
    public async void PutFile()
    {
        const int countFile = 20;

        List<File> files = new();

        for (int i = 0; i < countFile; ++i)
        {
            FileWithoutId file = new();
            file.file_name = fileName + i.ToString();

            File created_file = new();
            var exception = await Record.ExceptionAsync(async () => created_file = await fileHandler.Put(file));
            Assert.Null(exception);

            files.Add(created_file);
        }

        foreach (var file in files)
        {
            File created_file = new();
            var exception = await Record.ExceptionAsync(async () => created_file = await fileHandler.GetOne(file.id.ToString()));
            Assert.Equal(created_file.file_name, file.file_name);
        }
    }

    [Fact]
    public void GetAllFile()
    {
        List<File> files = new List<File>();

        var exception = Record.Exception(() => files = fileHandler.GetAll().Result);

        Assert.Null(exception);
    }

    [Fact]
    public async void DeleteAllFile()
    {

        var files = fileHandler.GetAll().Result;

        foreach (var file in files)
        {
            var exception = await Record.ExceptionAsync(async () => await fileHandler.Delete(file.id.ToString()));

            Assert.Null(exception);
        }

        files = fileHandler.GetAll().Result;

        Assert.Empty(files);
    }

    [Fact]
    public async void FailGet()
    {

        var exception = await Record.ExceptionAsync(async () => await fileHandler.GetOne("unknowFile"));

        Assert.NotNull(exception);

        FileWithoutId file = new FileWithoutId { file_name = fileName + "FileToDeleteAndGet" };

        File created_file = new();

        exception = await Record.ExceptionAsync(async () => created_file = await fileHandler.Put(file));
        Assert.Null(exception);

        File addedFile = new();
        exception = await Record.ExceptionAsync(async () => addedFile = await fileHandler.GetOne(created_file.id.ToString()));
        Assert.Null(exception);

        Assert.Equal(addedFile.file_name, file.file_name);

        exception = await Record.ExceptionAsync(async () => await fileHandler.Delete(addedFile.id.ToString()));
        Assert.Null(exception);

        exception = await Record.ExceptionAsync(async () => addedFile = await fileHandler.GetOne(created_file.id.ToString()));
        Assert.NotNull(exception);
    }
}

