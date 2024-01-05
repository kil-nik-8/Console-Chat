#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "User.h"
#include "PrivateChat.h"
#include "PublicChat.h"

using namespace std;

int Chats_Count(int n)																	// �������, ������� ������� ���������� ������������ ����� ��� ��������� ���������� �������������
{				
	int Ans = 1;
	n--;
	for (n; n > 1; n--)
		Ans += n;

	return Ans;
}

int ID_Number;																			// ���������� ����������, ������������ ID ���������� ������ ������������
int CHAT_ID;																			// ���������� ����������, ������������ ID ���������� ������ ����

int main()
{
	ID_Number = 0;																		// ��������� ������������ ����� ������ (������� ID)
	CHAT_ID = 1;																		// ��������� ��� ����� ������ (public - 0, private - 1,2,3...)
	char input, open_file[400];
	int a = -1, userID = 0, i, index, chatID = 0, b = -1;
	bool bool1, bool2, access = false;
	string message = "", login, password, name;
	vector<User> users;																	// ��������� ��� ���� �������������
	User user;																			// ��������������� ���������� ���� ������ �������������
	vector<PrivateChat> chats;															// ��������� ���� ��������� �����
	PublicChat publicChat;
	PrivateChat chat;																	// ��������������� ���������� ������ ��������� �����
	fstream file;

	file.open("LOGINS.txt");															// ��������� ���� �� ����� ��������
	if (!file.is_open())																// �� ������ ������� � ������ ���
	{																					// ���� ��� ����� �, ��������������, �� ������� ��� �������
		file.close();																	
		ofstream{ "LOGINS.txt" };														// �� ������� ���
		file.open("LOGINS.txt");														// � ���������
	}
		
	file.seekg(0, ios_base::end);														// ���������� ��������� � ����� �����
	if (file.tellg())																	// ���������, �� ������ �� ����
	{
		file.seekg(0, ios_base::beg);													// ���������� ��������� � ������ �����
		while (!file.eof())																// ���� �� ������ �� ����� �����
		{
			user.erase();																// ������� ��������������� ����������
			file.getline(open_file, 400);												// ��������� �� ����� ������
			if (string(open_file) != "")												// ���� ������� �� ������
			{
				user.setLogin(open_file);												// ���������� �����
				user.setID(ID_Number);													// ���������� ID ������������
				users.push_back(user);													// ���������� � ��������� ������������
				ID_Number++;
			}
		}
	}	
	file.close();																		// ��������� ����

	file.open("PASSWORDS.txt");															// ��������� ���� �� ����� ��������
	if (!file.is_open())																// �� ������ ������� � ������ ��� (���������� � ��������)
	{	
		file.close();
		ofstream{ "PASSWORDS.txt" };
		file.open("PASSWORDS.txt");
	}
	for (i = 0; i < ID_Number; i++)														// �������� �� ���� ������������������ �������������
	{
		file.getline(open_file, 400);													// ��������� �� ����� ������
		users[i].setPassword(open_file);												// ���������� ������ ��������������� ������������� � ���������
	}
	file.close();																		// ��������� ����

	file.open("USERNAMES.txt");															// ��������� ���� �� ����� ����������
	if (!file.is_open())																// �� ������ ������� � ������ ��� (���������� � ��������)
	{
		file.close();
		ofstream{ "USERNAMES.txt" };
		file.open("USERNAMES.txt");
	}
	for (i = 0; i < ID_Number; i++)														// �������� �� ���� ������������������ �������������
	{
		file.getline(open_file, 400);													// ��������� �� ����� ������
		users[i].setName(open_file);													// ���������� �������� ��������������� ������������� � ���������
	}
	file.close();																		// ��������� ����

	file.open("Public_Chat.txt");														// ��������� ���� � ����������� ���������� ����
	if (!file.is_open())																// �� ������ ������� � ������ ��� (���������� � ��������)
	{
		file.close();
		ofstream{ "Public_Chat.txt" };
		file.open("Public_Chat.txt");
	}
	file.seekg(0, ios_base::end);														// ���������� ��������� � ����� �����
	if (file.tellg())																	// ���������, �� ������ �� ����
	{
		file.seekg(0, ios_base::beg);													// ���������� ��������� � ������ �����
		while (!file.eof())																// ���� �� ������ �� ����� �����
		{
			file.getline(open_file, 400);												// ��������� �� ����� ������
			publicChat.SetMessages(string(open_file));									// ���������� ��������� ������������� ���������� ���� � ���������� ������ PublicChat
		}
	}
	file.close();																		// ��������� ����
	i = Chats_Count(ID_Number);															// ���������� ���������� �����
	for (i; i >= 1; i--)																// �������� �� ���� ��������� �����
	{																					// ������ ��� ������ � ����� ������� ���������� ���� - ��� ID ������������� � ���� ��������
		name = "Private_Chat_" + to_string(i) + ".txt";									// ��������� �������� ��� �������� ����� ����������� ���������� ����
		file.open(name);																// ��������� ����
		file.seekg(0, ios_base::end);													// ���������� ��������� � ����� �����
		
		if (file.tellg() && file.is_open())												// ���������, �� ������ �� ���� � ������� �� ��� �������
		{
			file.seekg(ios_base::beg);													// ���������� ��������� � ������ �����
			chat.setChatID(i);															// ����������� ���� ID
			file >> a;																	// ��������� ID ������� ������������ � ����
			chat.setUserID1(a);															// ���������� ID ������� ������������ � ����
			file >> a;																	// ��������� ID ������� ������������ � ����
			chat.setUserID2(a);															// ���������� ID ������� ������������ � ����
			while (!file.eof())															// ���� �� ����� �� ����� �����
			{
				file.getline(open_file, 400);											// ��������� ������ �� �����
				chat.SetMessages(string(open_file));									// ���������� ������ ������
			}
			chats.insert(chats.begin(), chat);											// �������� ������ ��� � ��������� ��������� �����
			chat.erase();																// ������� ��������������� ����������
			CHAT_ID++;
		}
		file.close();																	// ��������� ����
	}

	a = -1;
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
						access = true;																								
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
				access = true;
				
				user.setLogin(login);													// ����������� ��������������� ���������� �����
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
					user.setID(ID_Number);												// ������������� ID ������������

					file.open("LOGINS.txt", ios::app);									// ��������� ���� � �������� �������������
					ID_Number == 0 ? file << login : file << "\n" << login;				// ���������� ����� ������ ������������ � ����� �����
					file.close();														// ��������� ����

					cout << "Set password: ";
					cin >> password;													// ������ ������
					file.open("PASSWORDS.txt", ios::app);								// ��������� ���� � �������� �������������
					ID_Number == 0 ? file << password : file << "\n" << password;		// ���������� ������ ������ ������������ � ����� �����
					file.close();														// ��������� ����
					user.setPassword(password);											// ������������� ������ � ��������������� ���������� ������������

					cout << "Set your UserName: ";
					cin >> name;														// ������ �������
					file.open("USERNAMES.txt", ios::app);								// ��������� ���� � ���������� �������������
					ID_Number == 0 ? file << name : file << "\n" << name;				// ���������� ������� ������ ������������ � ����� �����
					file.close();														// ��������� ����
					user.setName(name);													// ������������� ������� � ��������������� ���������� ������������

					ID_Number++;
					index = ID_Number - 1;												// ���������� ������ ������������, ����� ������ �������� � ���������� �������������
					users.push_back(user);												// ��������� ���������� ������������ � ������ ���� ������������ �������������								
					user.erase();														// ������� ��������������� ����������
				}
				break;

			case 'q':																	// �����
				cout << "Are you sure you want to close the Console Chat?" << endl;		// ����������, ��� ������������ ����� ����� �� ����������� ����
				cout << "0 - No" << endl;
				cout << "1 - Yes" << endl;
				cin >> a;
				if (a == 0)
					input = 'f';														// ������ �������� ���������� input, ����� �� ����� �� �����															
				break;																	// �����, �� ������ � ������� �� ����

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
					cout << "0 - public chat" << endl;									// ����� �� ������� ���� ������������ ����� (������� �����) ��������� � �� ID
					for (i = 0; i < chats.size(); i++)									// �������� �� ���� ��������� �����
					{
						if (chats[i].getUserID1() == users[index].getID())				// ��������� ���� �� � ���� �������������� ������������
						{
							cout << chats[i].getChatID() << " - chat with user "
								<< users[chats[i].getUserID2()].getName() << endl;		
						}
						else if (chats[i].getUserID2() == users[index].getID())			// ��������� ���� �� � ���� �������������� ������������
						{
							cout << chats[i].getChatID() << " - chat with user "
								<< users[chats[i].getUserID1()].getName() << endl;
						}
					}

					cout << "Choose chat: ";											
					cin >> chatID;															// ����� ���� �� ��� ID
					message = "";
					if (chatID == 0)														// ������ ��������� ���
					{
						file.open("Public_Chat.txt", ios::app);								// ��������� ���� � ����������� ���������� ����
						while (message != "CLOSE")											// ���� ������������ �� ������� "CLOSE", ��� �� ���������
						{
							system("cls");													// ������� ������ �������
							cout << "CLOSE - close chat" << endl;							// ���������� ����� �����������, ����� ����� ����� ������ ��� ������ �� ����
							cout << "--------------------------------" 
								<< "-------------------------------" << endl;
							publicChat.showChat();											// ����� ���� ��������� �� ������� ���� �� �������
							cout << "Message: ";
							getline(cin, message);											// ���� ���������, ���� "CLOSE", ����� ������� ������ ���
							while (message[0] == ' ')										// ������� ������� �� ������ ���������
									message.erase(0, 1);
							if (message != "CLOSE")
							{
								publicChat.addMessage(message, users[index].getName());		// �������� ��������� � ���, ����������� ��� � ������ ����
								if (message.size() > 0)
									file << users[index].getName() + ": " + message + "\n"; // ���������� ����� ��������� � ����
							}
						}
						file.close();														// ��������� ����
					}
					else																	// ���� ������ �� ��������� ���
					{
						for (i = 0; i < chats.size(); i++)									// �������� �� ���� ��������� �����
						{
							bool2 = chats[i].getChatID() == chatID;							// ������� ��� � ��������� ������������� ID
							if (bool2)
							{
								bool1 = chats[i].getUserID1() == users[index].getID() || chats[i].getUserID2() == users[index].getID();
								if (bool1)													// ���������, ������������� �� �������������� ������������ ���� � ������ ����
								{
									name = "Private_Chat_" + to_string(chatID) + ".txt";	// ��������� ��� ��� �������� ����� ������� ���������� ����
									file.open(name, ios::app);								// ��������� ���� � ������ ��������� �����
									while (message != "CLOSE")								// ���� ������������ �� ������� "CLOSE", ��� �� ���������
									{
										system("cls");										// ������� ������ �������
										cout << "CLOSE - close chat" << endl;				// ���������� ����� �����������, ����� ����� ����� ������ ��� ������ �� ����
										cout << "--------------------------------"
											<< "-------------------------------" << endl;
										chats[chatID - 1].showChat();						// ����� ���� ��������� �� ������� ���� �� �������
										cout << "Message: ";
										getline(cin, message);								// ���� ���������, ���� "CLOSE", ����� ������� ������ ���
										while (message[0] == ' ')							// ������� ������� �� ������ ���������
											message.erase(0, 1);
										if (message != "CLOSE")
										{
											chats[chatID - 1].addMessage(message, users[index].getName());	// �������� ��������� � ���, ����������� ��� � ������ ����
											if (message.size() > 0)
												file << users[index].getName() + ": " + message + "\n";	// ���������� ����� ��������� � ����
										}
									}
									file.close();											// ��������� ����
								}
								else														// ����� ��������� � ������ �������� ������������ ������
								{
									cout << "Incorrect data." << endl;					
									message = "CLOSE";
									system("pause");
								}
							}
						}
					}
					break;

				case 2:																		// �������� ������ ���������� ����
					a = 0;
					for (i = 0; i < users.size(); i++)										// �������� �� ���� ������������������ �������������
					{
						access = true;
						if (i != index)														// ������������ �������� ���� � ����� �����
						{
							for (int j = 0; j < chats.size(); j++)							// �������� �� ���� ��������� �����
							{
								bool1 = chats[j].isUserIn(users[i].getID());				
								bool2 = chats[j].isUserIn(users[index].getID());
								if (bool1 * bool2)											// ��������, ���� �� ��� � �������������� � ��������� �������������� 
								{
									j = chats.size();										// ����� �� �����
									access = false;											
								}
							}
							if (access)														// ���� ��� ���������� ������ ���� �� �������
							{
								cout << "User ID: " << users[i].getID()
									<< " - " << users[i].getName() << endl;					// ����� �� �������, ��� � ������ ������������� ����� ������� ����� ��������� ���
								a = 1;
							}
						}
					}
					if (a == 0)																// ���� ������� ��� ������ (��� ����������)
					{
						cout << "Impossible to create new chat."
							<< " Chats for all users have been already created." << endl;	// ����� ���������� �� �������
						system("pause");
						access = true;														// ������������� �������� true, ����� �� ����� �� ������������
					}
					else																	// ���� ������� ����� ��� �����
					{
						cout << endl << "Enter user ID: " << endl;
						cin >> userID;														// ������ ID ������������, ���� ����� ��������
						for (i = 0; i < users.size(); i++)									// �������� �� ���� �������������
						{
							if (users[i].getID() == userID)									// �������� �� ������������� ������������ � ����� ID
							{
								system("cls");												// ������� ������ �������					
								chat.setUserID1(users[index].getID());						// ���������� ID ������� ������������ � ���� 
								chat.setUserID2(userID);									// ���������� ID ������� ������������ � ����
								chat.setChatID(CHAT_ID);									// ���������� ID ����
								chatID = CHAT_ID;											// �������� ID ���� � �������������, � �������� ID - UserID
								name = "Private_Chat_" + to_string(CHAT_ID) + ".txt";		// ��������� �������� ��� �������� ������ ����� ��� ������ ����
								ofstream{ name };											// ������� ���� � ������ ���������
								CHAT_ID++;
								chats.push_back(chat);										// ��������� ����� ��� � ��������� ���� ��������� �����

								file.open(name, ios::app);									// ��������� ���� ��� ������
								file.clear();												// ���������� ����� ������ ��� ������������ ������ �����
								file << to_string(chat.getUserID1()) << endl;				// ���������� ID ������� ������������ � ����
								file << to_string(chat.getUserID2()) << endl;				// ���������� ID ������� ������������ � ����
								message = "";

								while (message != "CLOSE")									// ���� ������������ �� ������� "CLOSE", ��� �� ���������
								{
									system("cls");											// ������� ������ �������
									cout << "CLOSE - close chat" << endl;					// ���������� ����� �����������, ����� ����� ����� ������ ��� ������ �� ����
									cout << "--------------------------------"
										<< "-------------------------------" << endl;
									chats[chatID - 1].showChat();							// ����� ���� ��������� �� ������� ���� �� �������
									cout << "Message: ";
									getline(cin, message);									// ���� ���������, ���� "CLOSE", ����� ������� ������ ���
									while (message[0] == ' ')										// ������� ������� �� ������ ���������
										message.erase(0, 1);
									if (message != "CLOSE")
									{
										chats[chatID - 1].addMessage(message, users[index].getName());	// �������� ��������� � ���, ����������� ��� � ������ ����
										if (message.size() > 0)
											file << users[index].getName() + ": " + message + "\n";	// ���������� ����� ��������� � ����
									}
								}
								file.close();												// ��������� ����
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
