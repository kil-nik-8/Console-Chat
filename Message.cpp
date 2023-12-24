#include "Message.h"

int Message::num = 0;
int Message::messageCounter = 0;
//сообщение в чат
Message::Message() : _chatID(num), _sender(""), _addressID(0), _message("")
{
}
Message::Message(std::string writer, std::string message) : _chatID(++num), _sender(writer), _addressID(-1), _message(message)
{
    messageCounter++;
}
//личное сообщение
Message::Message(std::string writer, int target, std::string message) : _chatID(++num), _sender(writer), _addressID(target), _message(message)
{
    messageCounter++;
}

bool Message::searchByTarget(int n) const 
{
    return (_addressID == n);
}

std::string Message::getSender() const 
{
    return _sender;
}

int Message::getAddress() const 
{
    return _addressID;
}

std::string Message::getMessage() const
{
    return _message;
}

int Message::getChatID() const
{
    return _chatID;
}

void Message::getChatList() const
{
    
}

std::string Message::showChat() const
{
    
}
