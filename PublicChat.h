#pragma once
#include <iostream>

using namespace std;

class PublicChat
{
public:
	PublicChat(); // Конструктор
	~PublicChat() = default; // Деструктор
	void showChat(); // Вывод сообщений чата на экран консоли
	void addMessage(string, int); // добавление сообщения в чат

private:
	int _userCount;
	string _messages;
};

