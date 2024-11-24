using System.Text;
using System.Text.Json;

namespace authentication_service.Api;

public interface IUserHandler
{
    public User? GetUserByLogin(string login);
}

public class ExternalUserHandler : IUserHandler
{
    public ExternalUserHandler()
    {
        var variable = Environment.GetEnvironmentVariable("USER_SERVICE_HOST");
        if (variable != null)
        {
            user_service_url = variable;
        }
        Console.WriteLine(user_service_url);
    }
    public User? GetUserByLogin(string login)
    {
        var user = GetUserRequest(login);
        return user.Result;
    }

    async Task<User?> GetUserRequest(string email)
    {
        HttpResponseMessage response = await client.GetAsync(user_service_url + "/" + email);

        if (response.IsSuccessStatusCode)
        {
            string responseContent = await response.Content.ReadAsStringAsync();
            Console.WriteLine($"Response: {responseContent}");

            return JsonSerializer.Deserialize<User>(responseContent);
        }
        else
        {
            Console.WriteLine($"Error: {response.StatusCode}");

            return null;
        }
    }

    private HttpClient client { get; set; } = new HttpClient();
    private string user_service_url { get; set; } = "http://localhost:5555/user";
};



