#include <iostream>
#include <vector>
#include "User.h"
#include "Message.h"

using namespace std;

int ID_Number;																			// ���������� ����������, ������������ ID ���������� ������ ������������

int main()
{
	ID_Number = 1;																		// ��������� ������������ ����� ������
	char input;
	int a = -1, userID = 0, i, index, chatID = 0, b = -1;
	string message = "", login, password;
	vector<User> users;																	// ��������� ��� ���� �������������
	User user;																			// ��������������� ���������� ���� ������ �������������
	vector<Message> chats;
	bool access = false;

	do
	{
		system("cls");																	// ������� ������ �������
		cout << "0 - log in" << endl;													// �����������
		cout << "1 - sign up" << endl;													// �����������
		cout << "q - close Console Chat" << endl;										// �����

		cin >> input;																	// �������� ������ �����

		switch (input)
		{
			case '0':																	// �����������
				cout << "login: ";													
				cin >> login;															// ������ �����
				for (i = 0; i < users.size(); i++)										// �������� �� ���� ������������ �������������
				{
					if (login == users[i].getLogin())									// ����� ������������ � ��������� �������
					{
						access = true;
						index = i;														// ���������� ������ ������������, ����� ������ �������� � ���������� �������������
					}
				}
				if (access)
				{
					access = false;
					cout << "password: ";
					cin >> password;													// ������ ������

					if (password == users[index].getPassword())							// �������� �� ���������� ������
					{
						access = true;																								
					}
					else
					{
						cout << "Incorrect password." << endl;							// ������ �������� ������
						system("pause");
					}
				}
				else
				{
					cout << "Incorrect login." << endl;									// ������ �������� �����
					system("pause");
				}
				break;

			case '1':																	// �����������				
				cout << "Set login: ";
				cin >> login;															// ������ �����
				user.setLogin(login);													// ����������� ��������������� ���������� �����
				access = true;
				for (i = 0; i < users.size(); i++)										// �������� �� ���� ������������ �������������
				{
					if (login == users[i].getLogin())									// �������� - ���� �� ����� �����
					{
						cout << "This login is already taken." << endl;
						access = false;
						i = users.size();												// ������� �� �����
						system("pause");
					}
				}
				if (access)																// � ������, ���� ������ ������ ���
				{
					cout << "Set password: ";
					cin >> password;													// ������ ������

					user.setPassword(password);											// ������������� ������
					user.setID(ID_Number);												// ������������� ID
					ID_Number++;
					users.push_back(user);												// ��������� ���������� ������������ � ������ ���� ������������ �������������
					index = users.size() - 1;											// ���������� ������ ������������, ����� ������ �������� � ���������� �������������
				}
				break;

			case 'q':																	// �����
				cout << "Are you sure you want to close the Console Chat?" << endl;		// ����������, ��� ������������ ����� ����� �� ����������� ����
				cout << "0 - No" << endl;
				cout << "1 - Yes" << endl;
				cin >> a;
				if (a == 0)
					input = 'f';														// ������ �������� ���������� input, ����� �� ����� �� �����
																						// �����, �� ������ � ������� �� ����
				break;

			default:																
				cout << "Incorrect data." << endl;										// ������� ���������, ���� ��������� ������ �� ������������� ������������ ������. ������� ����� ���������� ������
				system("pause");
		}
		
		if (input != 'q' && access)														// � ������ �������� ����������� ��� �����������
		{
			access = true;
			do
			{
				system("cls");															// ������� ������ �������
				cout << "0 - exit" << endl;												// �����
				cout << "1 - to choose chat" << endl;									// ����� ������������ �����
				cout << "2 - to start new chat" << endl;								// ������� ����� ��������� ���
				cout << "4 - change user" << endl;
				
				cin >> a;																// �������� ������ �����
				switch (a)
				{
				case 0:																	// �����
					cout << "Are you sure you want to exit?" << endl;					// ����������, ��� ������������ ����� ����� �� ����������� ����
					cout << "0 - No" << endl;
					cout << "1 - Yes" << endl;
					cin >> b;
					if (b == 1)															// ������ �������� ���������� access, ����� ����� �� �����
						access = false;													// �����, �� ������ � �������� � ����
					break;

				case 1:																	// ����� ����
					users[index].getChatList();											// ����� �� ������� ���� ������������ ����� (������� �����) ��������� � �� ID � ����������� ������������� ���������
					cout << "Choose chat: ";											
					cin >> chatID;														// ����� ���� �� ��� ID
					message = "";
					while (message != "CLOSE")											// ���� ������������ �� ������� "CLOSE", ��� �� ���������
					{
						system("cls");													// ������� ������ �������
						cout << "CLOSE - close chat" << endl;							// ���������� ����� �����������, ����� ����� ����� ������ ��� ������ �� ����
						cout << "---------------------------------------------------------------" << endl;
						users[index].showChat(chatID);									// ����� ���� ��������� �� ������� ���� �� �������
						cout << "Message: ";
						cin >> message;													// ���� ���������, ���� "CLOSE", ����� ������� ������ ���
						if (message != "CLOSE")
						{
							message += "\n";
							users[index].sendMessage(chatID, message);					// �������� ��������� � ���, ����������� ��� � ������ ����
						}
					}
					break;

				case 2:																	// �������� ������ ���������� ����
					cout << "Enter user ID: " << endl;
					cin >> userID;														// ������ ID ������������, ���� ����� ��������
					for (i = 0; i < users.size(); i++)									// �������� �� ���� �������������
					{
						if (users[i].getID() == userID)									// �������� �� ������������� ������������ � ����� ID
						{
							system("cls");												// ������� ������ �������
							users[index].startChatWith(userID);							// �������� ������ �������� ������ ����� 
							{
								Message AB;
								AB._senderID = users[index].getID();
								AB._addressID = userID;
								-----
									users[index].addChat(AB);
								users[userID].addChat(AB);
								
							}
							chatID = (users[index]._chats).getChatID(userID);			// �������� ID ���� � �������������, � �������� ID - UserID
							cout << "Message: ";
							cin >> message;												// ���� ���������
							users[index].sendMessage(chatID, message);					// �������� ��������� � ���, ����������� ��� � ������ ����
						}
					}
					break;

				default:
					cout << "Incorrect data." << endl;									// ������� ���������, ���� ��������� ������ �� ������������� ������������ ������. ������� ������ ���� ���������� ������
				}
			} while (access);
			
		}
		
	} while (input != 'q');
	
	return 0;
}
