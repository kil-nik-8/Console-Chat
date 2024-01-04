#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "PrivateChat.h"
#include "PublicChat.h"

using namespace std;

int ID_Number;																			// ���������� ����������, ������������ ID ���������� ������ ������������
int CHAT_ID;

int main()
{
	ID_Number = 1;																		// ��������� ������������ ����� ������
	CHAT_ID = 1;
	char input;
	int a = -1, userID = 0, i, index, chatID = 0, b = -1;
	bool bool1, bool2;
	string message = "", login, password, name;
	vector<User> users;																	// ��������� ��� ���� �������������
	User user;																			// ��������������� ���������� ���� ������ �������������
	vector<PrivateChat> chats;
	PublicChat publicChat;
	PrivateChat chatick;

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
					cout << "Create your username: ";
					cin >> name;
					user.setName(name);
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
					cout << "0 - public chat" << endl;									// ����� �� ������� ���� ������������ ����� (������� �����) ��������� � �� ID � ����������� ������������� ���������
					for (i = 0; i < chats.size(); i++)									
					{
						if (chats[i].getUserID1() == users[index].getID())
						{
							cout << chats[i].getChatID() << " - chat with user " << users[chats[i].getUserID2() - 1].getName() << endl;
						}
						else if (chats[i].getUserID2() == users[index].getID())
						{
							cout << chats[i].getChatID() << " - chat with user " << users[chats[i].getUserID2() - 1].getName() << endl;
						}
					}

					cout << "Choose chat: ";											
					cin >> chatID;															// ����� ���� �� ��� ID
					message = "";
					if (chatID == 0)
					{
						message = "";
						while (message != "CLOSE")											// ���� ������������ �� ������� "CLOSE", ��� �� ���������
						{
							system("cls");													// ������� ������ �������
							cout << "CLOSE - close chat" << endl;							// ���������� ����� �����������, ����� ����� ����� ������ ��� ������ �� ����
							cout << "---------------------------------------------------------------" << endl;
							publicChat.showChat();											// ����� ���� ��������� �� ������� ���� �� �������
							cout << "Message: ";
							getline(cin, message);											// ���� ���������, ���� "CLOSE", ����� ������� ������ ���
							if (message != "CLOSE")
							{
								publicChat.addMessage(message, users[index].getName());		// �������� ��������� � ���, ����������� ��� � ������ ����
							}
						}
					}
					else
					{
						for (i = 0; i < chats.size(); i++)
						{
							bool1 = chats[i].getUserID1() == users[index].getID() || chats[i].getUserID2() == users[index].getID();
							bool2 = chats[i].getChatID() == chatID;

							if (!(bool2 * bool1))
							{
								cout << "Incorrect data." << endl;
								message = "CLOSE";
								system("pause");
							}
						}

						while (message != "CLOSE")											// ���� ������������ �� ������� "CLOSE", ��� �� ���������
						{
							system("cls");													// ������� ������ �������
							cout << "CLOSE - close chat" << endl;							// ���������� ����� �����������, ����� ����� ����� ������ ��� ������ �� ����
							cout << "---------------------------------------------------------------" << endl;
							chats[chatID - 1].showChat();									// ����� ���� ��������� �� ������� ���� �� �������
							cout << "Message: ";
							getline(cin, message);											// ���� ���������, ���� "CLOSE", ����� ������� ������ ���
							if (message != "CLOSE")
							{
								chats[chatID - 1].addMessage(message, users[index].getName());		// �������� ��������� � ���, ����������� ��� � ������ ����
							}
						}
					}
					break;

				case 2:																		// �������� ������ ���������� ����
					for (i = 0; i < users.size(); i++)
					{
						access = true;
						if (i != index)
						{
							for (int j = 0; j < chats.size(); j++)
							{
								bool1 = chats[j].isUserIn(users[i].getID());
								bool2 = chats[j].isUserIn(users[index].getID());
								if (bool1 * bool2)
								{
									j = chats.size();
									access = false;
								}
							}
							if (access)
								cout << "User ID: " << users[i].getID() << " - " << users[i].getName() << endl;
						}
					}
					cout << endl << "Enter user ID: " << endl;
					cin >> userID;															// ������ ID ������������, ���� ����� ��������
					for (i = 0; i < users.size(); i++)										// �������� �� ���� �������������
					{
						if (users[i].getID() == userID)										// �������� �� ������������� ������������ � ����� ID
						{
							system("cls");													// ������� ������ �������					
							chatick.setUserID1(users[index].getID());						// �������� ������ �������� ������ ����� 
							chatick.setUserID2(userID);
							chatick.setChatID(CHAT_ID);
							chatID = CHAT_ID;												// �������� ID ���� � �������������, � �������� ID - UserID
							CHAT_ID++;
							chats.push_back(chatick);
							
							while (message != "CLOSE")											// ���� ������������ �� ������� "CLOSE", ��� �� ���������
							{
								system("cls");													// ������� ������ �������
								cout << "CLOSE - close chat" << endl;							// ���������� ����� �����������, ����� ����� ����� ������ ��� ������ �� ����
								cout << "---------------------------------------------------------------" << endl;
								chats[chatID - 1].showChat();									// ����� ���� ��������� �� ������� ���� �� �������
								cout << "Message: ";
								getline(cin, message);											// ���� ���������, ���� "CLOSE", ����� ������� ������ ���
								if (message != "CLOSE")
								{
									chats[chatID - 1].addMessage(message, users[index].getName());		// �������� ��������� � ���, ����������� ��� � ������ ����
								}
							}
						}
					}
					break;

				default:
					cout << "Incorrect data." << endl;										// ������� ���������, ���� ��������� ������ �� ������������� ������������ ������. ������� ������ ���� ���������� ������
				}
			} while (access);
			
		}
		
	} while (input != 'q');
	
	return 0;
}
