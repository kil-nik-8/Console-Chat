#pragma once
#include <string>
#include <iostream>
#include "PublicChat.h"

using namespace std;

class PrivateChat : public PublicChat
{
	int _userID1;
	int _userID2; 
	int _chatID;
	string _messages;

public:
	PrivateChat();
	PrivateChat(int, int); 
	PrivateChat(int, int , string);

	void setChatID(int);
	int getChatID() const;

	void setUserID1(int);
	int getUserID1() const;

	void setUserID2(int);
	int getUserID2() const;

	//void addMessage(string, int);
	//void showChat() override; 

};
