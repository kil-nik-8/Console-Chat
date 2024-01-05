#pragma once
#include <string>
#include <iostream>

using namespace std;

class PrivateChat
{
	int _userID1;	// ID ������� ������������ � ����
	int _userID2;	// ID ������� ������������ � ����
	int _chatID;	// ID ����
	string _messages;	// ��� ��������� ����

public:
	// ������������
	PrivateChat();
	PrivateChat(int, int); 
	PrivateChat(int, int , string);

	// ������� � �������
	void setChatID(int);
	int getChatID() const;
	void setUserID1(int);
	int getUserID1() const;
	void setUserID2(int);
	int getUserID2() const;
	void SetMessages(string);

	// �������������� ����������
	bool isUserIn(int); // ��������, ���� �� ������������ � ������ ���� � ����� ID
	void erase();		// ������� ����� ������
	void showChat();	// ����� ��������� �� �������
	void addMessage(string, string); // ���������� ��������� � ���
};
