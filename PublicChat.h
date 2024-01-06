#pragma once
#include <iostream>

using namespace std;

class PublicChat
{
public:
	PublicChat(); // Конструктор

	// Геттеры и Сеттеры
	void SetMessages(string);

	// Дополнительный функционал
	void showChat(); // Вывод сообщений чата на экран консоли
	void addMessage(string, string); // добавление сообщения в чат
private:
	string _messages;	// Все сообщения чата
};

