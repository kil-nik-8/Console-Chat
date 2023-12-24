#pragma once
#include <string>
#include <iostream>
using namespace std;
	class Message
{
	static int num;		// ���������� �����, ������� �������� chatID
	static int messageCounter; // ������� ���������
	int _chatID; //
	std::string _sender; // �����������
	int _senderID;
	int _addressID; // ID ����������
	string _message; // ���������
public:
	Message();
	Message(std::string writer, std::string message); //��������� � ����� ���
	Message(std::string writer, int target, std::string message); // ������ ���������

	bool searchByTarget(int) const; // �������� ����������
	std::string getSender() const; 
	int getAddress() const; 
	int getChatID() const;
	std::string getMessage() const;
	
	void getChatList() const; // ID ���� �����
	std::string showChat() const; // ����� ��������� � ����

};
