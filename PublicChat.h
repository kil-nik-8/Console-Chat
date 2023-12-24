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

private:
	int _userCount;
	string _messages;
};

