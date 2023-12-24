#pragma once
#include <iostream>

using namespace std;

class PublicChat
{
public:
	PublicChat(); // �����������
	~PublicChat() = default; // ����������
	void showChat(); // ����� ��������� ���� �� ����� �������
	void addMessage(string, int); // ���������� ��������� � ���
	int getChatID() const;

private:
	int _chatID;
	string _messages;
};
