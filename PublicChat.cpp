#include "PublicChat.h"
#include <string>

PublicChat::PublicChat() : _chatID(0), _messages("") {}

void PublicChat::showChat()
{
	std::cout << _messages << endl;
}

void PublicChat::addMessage(string message, int userID)
{
	_messages += to_string(userID) + ": " + message + "\n";
}

int PublicChat::getChatID() const
{
	return _chatID;
}