#pragma once
#include <string>
#include <vector>
#include "PublicChat.h"
using namespace std;

class User
{
	int _userid;
	string _login;
	string _password;

public:
	User();
	User(string username, string pass);
	string setLogin(string login);
	string setPassword(string password);
	int setID(int ID_Number);
	string getLogin();
	string getPassword();
	int getID() const;
};