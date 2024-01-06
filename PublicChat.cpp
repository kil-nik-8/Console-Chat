#include "PublicChat.h"
#include <string>

PublicChat::PublicChat() : _messages("") {}

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

void PublicChat::SetMessages(string message)
{
	if (message.size() > 0)
	_messages += message + "\n";
}