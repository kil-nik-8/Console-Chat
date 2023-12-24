#pragma once
#include <string>
#include <iostream>
using namespace std;
	class Message
{
	static int num;		// уникальный номер, который получает chatID
	static int messageCounter; // счетчик сообщений
	int _chatID; //
	std::string _sender; // отправитель
	int _senderID;
	int _addressID; // ID получателя
	string _message; // сообщения
public:
	Message();
	Message(std::string writer, std::string message); //сообщение в общий чат
	Message(std::string writer, int target, std::string message); // личное сообщение

	bool searchByTarget(int) const; // Проверка получателя
	std::string getSender() const; 
	int getAddress() const; 
	int getChatID() const;
	std::string getMessage() const;
	
	void getChatList() const; // ID лист чатов
	std::string showChat() const; // вывод сообщений в чате

};
