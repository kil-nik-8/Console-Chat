#include "User.h"

User::User() : _userid(0), _login(""), _password("")
{
}

User::User(string login, string pass) :_login(login), _password(pass)
{
	
}

string User::setLogin(string login)
{
	_login = login;
	return _login;

}
string User::setPassword(string password)
{
	_password = password;
	return _password;
}

int User::setID(int ID_Number)
{
	_userid = ID_Number;
	return -1;
}

string User::getLogin()
{
	return _login;
}
string User::getPassword()
{
	return _password;
}
int User::getID() const
{
	return _userid;
}