#include "User.h"

User::User() : _userid(-1), _login(""), _password(""), _username("")
{
}

User::User(int userid, string login, string pass, string username) : _userid(userid), _login(login), _password(pass), _username(username)
{
	
}

void User::setLogin(string login)
{
	_login = login;
}

void User::setPassword(string password)
{
	_password = password;
}

void User::setID(int ID_Number)
{
	_userid = ID_Number;
}

string User::getLogin() const
{
	return _login;
}
string User::getPassword() const
{
	return _password;
}
int User::getID() const
{
	return _userid;
}

void User::setName(string name)
{
	_username = name;
}

string User::getName() const
{
	return _username;
}

void User::erase()
{
	_userid = -1;
	_login = "";
	_username = "";
	_password = "";
}