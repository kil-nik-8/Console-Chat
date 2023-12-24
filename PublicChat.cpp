#include "PublicChat.h"
#include <string>

PublicChat::PublicChat() : _userCount(0), _messages("") {}

void PublicChat::showChat()
{
	std::cout << _messages << endl;
}

void PublicChat::addMessage(string message, int userID)
{
	_messages += to_string(userID) + ": " + message + "\n";
}