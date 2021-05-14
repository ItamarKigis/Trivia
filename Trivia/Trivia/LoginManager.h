#include <vector>
#include "LoggedUser.h"
class LoginManager
{
public:
	void signup(std::string username, std::string password, std::string email);
	void login(std::string username, std::string login);
	void logout(std::string );
private:
	std::vector<LoggedUser> m_loggedUsers;
};