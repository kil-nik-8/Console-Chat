#pragma once
#include <string>
#include <vector>
#include "PublicChat.h"
using namespace std;

class User
{
	int _userid;
	string _login;
	string _username;
	string _password;

public:
	User();
	User(string username, string pass);
	void setLogin(string login);
	void setPassword(string password);
	void setID(int ID_Number);
	void setName(string);
	string getLogin() const;
	string getPassword() const;
	string getName() const;
	int getID() const;
};