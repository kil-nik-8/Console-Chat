#pragma once
#include <iostream>

using namespace std;

class PublicChat
{
public:
	PublicChat(); // �����������

	// ������� � �������
	void SetMessages(string);

	// �������������� ����������
	void showChat(); // ����� ��������� ���� �� ����� �������
	void addMessage(string, string); // ���������� ��������� � ���
private:
	string _messages;	// ��� ��������� ����
};

