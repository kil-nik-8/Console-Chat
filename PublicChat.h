#pragma once
#include <iostream>

using namespace std;

class PublicChat
{
public:
	PublicChat(); // �����������

	// ������� � �������
	int getChatID() const;
	void SetMessages(string);
	string GetMessages() const;

	// �������������� ����������
	void showChat(); // ����� ��������� ���� �� ����� �������
	void addMessage(string, string); // ���������� ��������� � ���
private:
	int _chatID;		// ID ���������� ���� (������ 0)
	string _messages;	// ��� ��������� ����
};

