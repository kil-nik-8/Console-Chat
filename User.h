#pragma once
#include <string>
#include <vector>
#include "PublicChat.h"

using namespace std;

class User
{
	int _userid; // ID пользователя
	string _login; // логин пользователя
	string _username; // никнейм пользователя
	string _password; // пароль пользователя

public:
	// Конструкторы
	User();
	User(int userid, string login, string pass, string username);

	// Геттеры и Сеттеры
	void setLogin(string login);
	void setPassword(string password);
	void setID(int ID_Number);
	void setName(string);
	string getLogin() const;
	string getPassword() const;
	string getName() const;
	int getID() const;

	void erase(); // Очистка полей класса
};