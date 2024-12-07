using Microsoft.Extensions.Configuration;

public class TestConfig
{
    public static IConfiguration Configuration { get; }

    static TestConfig()
    {
        Configuration = new ConfigurationBuilder()
            .AddJsonFile("appsettings.json")
            .Build();
    }
}
