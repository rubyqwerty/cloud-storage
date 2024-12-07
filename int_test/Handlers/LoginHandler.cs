using System.Text;
using System.Text.Json;

public class TokenInfo
{
    public string token { get; set; }
}

class LoginHandler
{
    public LoginHandler(string url)
    {
        _serviceUrl = url;
    }
    public async Task<string> Login(string login, string password)
    {
        var dataForLogin = new
        {
            Email = login,
            Password = password
        };

        var content = new StringContent(JsonSerializer.Serialize(dataForLogin), Encoding.UTF8, "application/json");

        var response = await _client.PostAsync(_serviceUrl, content);

        if (!response.IsSuccessStatusCode)
        {
            throw new Exception("Ошибка аутентификации пользователя");
        }

        var token = JsonSerializer.Deserialize<TokenInfo>(await response.Content.ReadAsStringAsync());

        return token.token;
    }
    private HttpClient _client { get; set; } = new HttpClient();
    private string _serviceUrl { get; set; }
}