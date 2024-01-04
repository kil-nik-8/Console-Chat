#include "PublicChat.h"
#include <string>

PublicChat::PublicChat() : _chatID(0), _messages("") {}

void PublicChat::showChat()
{
	if (_messages.size() > 0 && _messages[_messages.size() - 3] != ':')
		std::cout << _messages << endl;
}

void PublicChat::addMessage(string message, string username)
{
	if (message.size() > 0)
	_messages += username + ": " + message + "\n";
}

int PublicChat::getChatID() const
{
	return _chatID;
}