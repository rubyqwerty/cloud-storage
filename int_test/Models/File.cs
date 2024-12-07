public struct File
{
    public File() { }
    public int id { get; set; } = 0;
    public string file_name { get; set; } = "";
    public string file_path { get; set; } = "";
    public string verified_user { get; set; } = "";
    public string verification_status { get; set; } = "";
}

public struct FileWithoutId
{
    public FileWithoutId() { }
    public string file_name { get; set; } = "";
    public string file_path { get; set; } = "";
    public string verified_user { get; set; } = "";
    public string verification_status { get; set; } = "";
}