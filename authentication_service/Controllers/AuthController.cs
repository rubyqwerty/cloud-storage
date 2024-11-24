using authentication_service;
using authentication_service.Api;
using Microsoft.AspNetCore.Identity.Data;
using Microsoft.AspNetCore.Mvc;

[ApiController]
[Route("api/[controller]")]
public class AuthController : ControllerBase
{
    private readonly TokenService _tokenService;
    private readonly IUserHandler _userHandler;

    public AuthController()
    {
        _tokenService = new TokenService();
        _userHandler = new ExternalUserHandler();
    }

    [HttpPost("login")]
    public IActionResult Login([FromBody] LoginRequest request)
    {
        if (IsValidUser(request.Email, request.Password))
        {
            var token = _tokenService.GenerateToken(request.Email);
            return Ok(new { token });
        }

        return Unauthorized();
    }

    private bool IsValidUser(string login, string password)
    {
        var user = _userHandler.GetUserByLogin(login);

        if (user == null) return false;

        return user.IsValidUser(login, password);
    }
}
