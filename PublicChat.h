#pragma once
#include <iostream>

using namespace std;

class PublicChat
{
public:
	PublicChat(); // Конструктор

	// Геттеры и Сеттеры
	int getChatID() const;
	void SetMessages(string);
	string GetMessages() const;

	// Дополнительный функционал
	void showChat(); // Вывод сообщений чата на экран консоли
	void addMessage(string, string); // добавление сообщения в чат
private:
	int _chatID;		// ID публичного чата (всегда 0)
	string _messages;	// Все сообщения чата
};

