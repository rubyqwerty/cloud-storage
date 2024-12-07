using System.Text;
using System.Text.Json;
using NuGet.Frameworks;

class Handler<T, T2>
{

    public Handler(string serviceUrl, string token = "")
    {
        _serviceUrl = serviceUrl;
    }

    public async Task<List<T>> GetAll()
    {
        var response = await _client.GetAsync(_serviceUrl);
        if (response.IsSuccessStatusCode)
        {
            string responseContent = await response.Content.ReadAsStringAsync();

            return JsonSerializer.Deserialize<List<T>>(responseContent);
        }

        throw new Exception(response.StatusCode.ToString());
    }

    public async Task<T> GetOne(string key)
    {
        var response = await _client.GetAsync(_serviceUrl + '/' + key);
        if (response.IsSuccessStatusCode)
        {
            string responseContent = await response.Content.ReadAsStringAsync();

            return JsonSerializer.Deserialize<T>(responseContent);
        }

        throw new Exception(response.StatusCode.ToString());
    }


    public async Task Delete(string key)
    {
        var response = await _client.DeleteAsync(_serviceUrl + "/" + key);

        if (!response.IsSuccessStatusCode)
        {
            throw new Exception("Ошибка удаления объекта");
        }
    }

    public async Task<T> Put(T2 obj)
    {
        var content = new StringContent(JsonSerializer.Serialize(obj), Encoding.UTF8, "application/json");

        var response = await _client.PostAsync(_serviceUrl, content);

        if (!response.IsSuccessStatusCode)
        {
            throw new Exception("Ошибка удаления объекта");
        }

        string responseContent = await response.Content.ReadAsStringAsync();

        return JsonSerializer.Deserialize<T>(responseContent);
    }

    public void SetAccesToken(string token)
    {
        _client.DefaultRequestHeaders.Authorization =
                new System.Net.Http.Headers.AuthenticationHeaderValue("Bearer", token);
    }

    private HttpClient _client { get; set; } = new HttpClient();
    private string _serviceUrl { get; set; }

}