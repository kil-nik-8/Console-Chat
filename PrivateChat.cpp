#include "PrivateChat.h"

PrivateChat::PrivateChat() : _chatID(1), _userID1(0), _userID2(0), _messages("") {}

PrivateChat::PrivateChat(int userID1, int userID2) : _chatID(1), _userID1(userID1), _userID2(userID2), _messages("") {}

PrivateChat::PrivateChat(int userID1, int userID2, string message) : _chatID(1), _userID1(userID1), _userID2(userID2), _messages(message) {}

void PrivateChat::setChatID(int chatID)
{
	_chatID = chatID;
}

int PrivateChat::getChatID() const
{
	return _chatID;
}

void PrivateChat::setUserID1(int userID1)
{
	_userID1 = userID1;
}

int PrivateChat::getUserID1() const
{
	return _userID1;
}

void PrivateChat::setUserID2(int userID2)
{
	_userID2 = userID2;
}

int PrivateChat::getUserID2() const
{
	return _userID2;
}

bool PrivateChat::isUserIn(int userid)
{
	if (userid == _userID1 || userid == _userID2)
		return true;
	else
		return false;
}

/*void PrivateChat::addMessage(string message, int userID)
{
	_messages += to_string(userID) + ": " + message + "\n";
}*/