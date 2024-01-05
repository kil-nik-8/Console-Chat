#pragma once
#include <string>
#include <iostream>

using namespace std;

class PrivateChat
{
	int _userID1;	// ID первого пользователя в чате
	int _userID2;	// ID второго пользователя в чате
	int _chatID;	// ID чата
	string _messages;	// Все сообщения чата

public:
	// Конструкторы
	PrivateChat();
	PrivateChat(int, int); 
	PrivateChat(int, int , string);

	// Геттеры и Сеттеры
	void setChatID(int);
	int getChatID() const;
	void setUserID1(int);
	int getUserID1() const;
	void setUserID2(int);
	int getUserID2() const;
	void SetMessages(string);

	// Дополнительный функционал
	bool isUserIn(int); // Проверка, есть ли пользователь в данном чате с таким ID
	void erase();		// Очистка полей класса
	void showChat();	// Вывод сообщений на консоль
	void addMessage(string, string); // добавление сообщения в чат
};
