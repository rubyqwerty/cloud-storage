public class User
{
    public string? login { get; set; }
    public string? phone { get; set; }
    public int? file_count { get; set; }
    public string? password { get; set; }

    public bool IsValidUser(string login_, string password_)
    {
        return login == login_ && password == password_;
    }
}