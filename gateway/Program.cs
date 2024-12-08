using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.IdentityModel.Tokens;
using Ocelot.DependencyInjection;
using Ocelot.Middleware;
using System.Security.Cryptography;
using System.Text;

var builder = WebApplication.CreateBuilder(args);

var routingConfigPath = Environment.GetEnvironmentVariable("ROUTING_CONFIG");
if (routingConfigPath == null)
{
    routingConfigPath = "Properties/routing.json";
}

builder.Configuration.AddJsonFile(routingConfigPath);


var publicKey = @"-----BEGIN PUBLIC KEY-----
MFwwDQYJKoZIhvcNAQEBBQADSwAwSAJBALxq3LaPs+fMAR45iNdt7UU18Ve/8HJ+
s8+vQo4Q+AKEGzNkNY6J00hHrPmwtDXUZDbFD90X/Bh0xAK07fxzXSsCAwEAAQ==
-----END PUBLIC KEY-----
";

var rsa = RSA.Create();
rsa.ImportFromPem(publicKey);

builder.Services.AddAuthentication(options =>
{
    options.DefaultScheme = JwtBearerDefaults.AuthenticationScheme;
})
.AddJwtBearer("JwtBearer", options =>
{
    options.TokenValidationParameters = new TokenValidationParameters
    {
        ValidateIssuer = true,
        ValidateAudience = true,
        ValidateLifetime = true,
        IssuerSigningKey = new RsaSecurityKey(rsa),
        ValidIssuer = "localhost",
        ValidAudience = "CloudStorage"
    };
});

builder.Services.AddOcelot();

var app = builder.Build();

app.UseAuthentication();
app.UseAuthorization();
app.UseOcelot().Wait();

app.MapControllers();

app.Run();
