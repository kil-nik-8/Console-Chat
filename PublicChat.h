#pragma once
#include <iostream>

using namespace std;

class PublicChat
{
public:
	PublicChat(); // Конструктор
	~PublicChat() = default; // Деструктор
	void showChat(); // Вывод сообщений чата на экран консоли
	void addMessage(string, string); // добавление сообщения в чат
	int getChatID() const;

private:
	int _chatID;
	string _messages;
};

