using System;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Security.Cryptography;
using System.Text;
using Microsoft.IdentityModel.Tokens;

public class TokenService
{
    private const string SecretKey = @"-----BEGIN PRIVATE KEY-----
MIIBVAIBADANBgkqhkiG9w0BAQEFAASCAT4wggE6AgEAAkEAvGrcto+z58wBHjmI
123tRTXxV7/wcn6zz69CjhD4AoQbM2Q1jonTSEes+bC0NdRkNsUP3Rf8GHTEArTt
/HNdKwIDAQABAkBcV2caVe1O4g1+OaZWJnrNm7VPUzNNeck4NOXCaJCT8kA9h07x
nJmpWcm8/5p0rx48xo46x3ITKGygYxLSnyvpAiEA9GHTOyDjLduW2Z7NxqmeMJo7
OQj0O2KCxje20sJzDFUCIQDFX++99z82cAz2VrD5W4QnANK6Y0QZAGaA+oWySo5D
fwIgX+lY1pb0slXBYY2C41pEnHybi6no+LmT66mIFjV8o7UCIHrn1LhsgDZ76/Zx
4V5FuLM49gAO1FblQu9KEXsGpjQtAiEA9BKuLGZYBbv7bf0+dvlbaETsKrI7NWmY
wQjYq0wD0Mw=
-----END PRIVATE KEY-----
";
    private const string Issuer = "localhost";
    private const string Audience = "CloudStorage";

    public string GenerateToken(string userLogin)
    {
        var claims = new[]
        {
            new Claim(JwtRegisteredClaimNames.Sub, userLogin),
            new Claim(JwtRegisteredClaimNames.Jti, Guid.NewGuid().ToString()),
        };

        var rsa = RSA.Create();
        rsa.ImportFromPem(SecretKey);

        var creds = new SigningCredentials(new RsaSecurityKey(rsa), SecurityAlgorithms.RsaSha256);

        var token = new JwtSecurityToken(
            issuer: Issuer,
            audience: Audience,
            claims: claims,
            expires: DateTime.Now.AddHours(1),
            signingCredentials: creds
        );

        return new JwtSecurityTokenHandler().WriteToken(token);
    }
}
