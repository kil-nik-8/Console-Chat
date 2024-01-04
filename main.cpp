#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "PrivateChat.h"
#include "PublicChat.h"

using namespace std;

int ID_Number;																			// Глобальная переменная, определяющая ID следующего нового пользователя
int CHAT_ID;

int main()
{
	ID_Number = 1;																		// Следующий пользователь будет первым
	CHAT_ID = 1;
	char input;
	int a = -1, userID = 0, i, index, chatID = 0, b = -1;
	bool bool1, bool2;
	string message = "", login, password, name;
	vector<User> users;																	// Контейнер для всех пользователей
	User user;																			// Вспомогательная переменная типа класса пользователей
	vector<PrivateChat> chats;
	PublicChat publicChat;
	PrivateChat chatick;

	bool access = false;

	do
	{
		system("cls");																	// Очистка экрана консоли
		cout << "0 - log in" << endl;													// Авторизация
		cout << "1 - sign up" << endl;													// Регистрация
		cout << "q - close Console Chat" << endl;										// Выход

		cin >> input;																	// Выбираем нужную опцию

		switch (input)
		{
			case '0':																	// АВТОРИЗАЦИЯ
				cout << "login: ";													
				cin >> login;															// Вводим логин
				for (i = 0; i < users.size(); i++)										// Проходим по всем существующим пользователям
				{
					if (login == users[i].getLogin())									// Поиск пользователя с введенным логином
					{
						access = true;
						index = i;														// Запоминаем индекс пользователя, чтобы дальше работать с конкретным пользователем
					}
				}
				if (access)
				{
					access = false;
					cout << "password: ";
					cin >> password;													// Вводим пароль

					if (password == users[index].getPassword())							// Проверка на совпадение пароля
					{
						access = true;																								
					}
					else
					{
						cout << "Incorrect password." << endl;							// Введен неверный пароль
						system("pause");
					}
				}
				else
				{
					cout << "Incorrect login." << endl;									// Введен неверный логин
					system("pause");
				}
				break;

			case '1':																	// РЕГИСТРАЦИЯ				
				cout << "Set login: ";
				cin >> login;															// Вводим логин
				user.setLogin(login);													// Присваиваем вспомогательной переменной логин
				access = true;
				for (i = 0; i < users.size(); i++)										// Проходим по всем существующим пользователям
				{
					if (login == users[i].getLogin())									// Проверка - есть ли такой логин
					{
						cout << "This login is already taken." << endl;
						access = false;
						i = users.size();												// Выходим из цикла
						system("pause");
					}
				}
				if (access)																// В случае, если такого логина нет
				{
					cout << "Set password: ";
					cin >> password;													// Вводим пароль

					user.setPassword(password);											// Устанавливаем пароль
					user.setID(ID_Number);												// Устанавливаем ID
					ID_Number++;
					cout << "Create your username: ";
					cin >> name;
					user.setName(name);
					users.push_back(user);												// Добавляем информацию пользователя в вектор всех существующих пользователей
					index = users.size() - 1;											// Запоминаем индекс пользователя, чтобы дальше работать с конкретным пользователем
				}
				break;

			case 'q':																	// ВЫХОД
				cout << "Are you sure you want to close the Console Chat?" << endl;		// Убеждаемся, что пользователь хочет выйти из консольного чата
				cout << "0 - No" << endl;
				cout << "1 - Yes" << endl;
				cin >> a;
				if (a == 0)
					input = 'f';														// Меняем значение переменной input, чтобы не выйти из цикла
																						// Иначе, не меняем и выходим из чата
				break;

			default:																
				cout << "Incorrect data." << endl;										// Выводим сообщение, если введенные данные не соответствуют предложенным опциям. Процесс входа начинается заново
				system("pause");
		}
		
		if (input != 'q' && access)														// В случае успешной авторизации или регистрации
		{
			access = true;
			do
			{
				system("cls");															// Очистка экрана консоли
				cout << "0 - exit" << endl;												// Выход
				cout << "1 - to choose chat" << endl;									// Выбор существующих чатов
				cout << "2 - to start new chat" << endl;								// Создать новый приватный чат
				
				cin >> a;																// Выбираем нужную опцию
				switch (a)
				{
				case 0:																	// ВЫХОД
					cout << "Are you sure you want to exit?" << endl;					// Убеждаемся, что пользователь хочет выйти из консольного чата
					cout << "0 - No" << endl;
					cout << "1 - Yes" << endl;
					cin >> b;
					if (b == 1)															// Меняем значение переменной access, чтобы выйти из цикла
						access = false;													// Иначе, не меняем и остаемся в чате
					break;

				case 1:																	// ВЫБОР ЧАТА
					cout << "0 - public chat" << endl;									// Вывод на консоль всех существующих чатов (сначала общий) совместно с их ID и количеством непрочитанных сообщений
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
					cin >> chatID;															// Выбор чата по его ID
					message = "";
					if (chatID == 0)
					{
						message = "";
						while (message != "CLOSE")											// Пока пользователь не напишет "CLOSE", чат не закроется
						{
							system("cls");													// Очистка экрана консоли
							cout << "CLOSE - close chat" << endl;							// Постоянный вывод напоминания, какое слово нужно ввести для выхода из чата
							cout << "---------------------------------------------------------------" << endl;
							publicChat.showChat();											// Вывод всех сообщений из данного чата на консоль
							cout << "Message: ";
							getline(cin, message);											// Ввод сообщения, либо "CLOSE", чтобы закрыть данный чат
							if (message != "CLOSE")
							{
								publicChat.addMessage(message, users[index].getName());		// Отправка сообщения в чат, закрепление его в данном чате
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

						while (message != "CLOSE")											// Пока пользователь не напишет "CLOSE", чат не закроется
						{
							system("cls");													// Очистка экрана консоли
							cout << "CLOSE - close chat" << endl;							// Постоянный вывод напоминания, какое слово нужно ввести для выхода из чата
							cout << "---------------------------------------------------------------" << endl;
							chats[chatID - 1].showChat();									// Вывод всех сообщений из данного чата на консоль
							cout << "Message: ";
							getline(cin, message);											// Ввод сообщения, либо "CLOSE", чтобы закрыть данный чат
							if (message != "CLOSE")
							{
								chats[chatID - 1].addMessage(message, users[index].getName());		// Отправка сообщения в чат, закрепление его в данном чате
							}
						}
					}
					break;

				case 2:																		// СОЗДАНИЕ НОВОГО ПРИВАТНОГО ЧАТА
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
					cin >> userID;															// Вводим ID пользователя, кому хотим написать
					for (i = 0; i < users.size(); i++)										// Проходим по всем пользователям
					{
						if (users[i].getID() == userID)										// Проверка на существования пользователя с таким ID
						{
							system("cls");													// Очистка экрана консоли					
							chatick.setUserID1(users[index].getID());						// Создание нового элемента класса чатов 
							chatick.setUserID2(userID);
							chatick.setChatID(CHAT_ID);
							chatID = CHAT_ID;												// Получаем ID чата с пользователем, у которого ID - UserID
							CHAT_ID++;
							chats.push_back(chatick);
							
							while (message != "CLOSE")											// Пока пользователь не напишет "CLOSE", чат не закроется
							{
								system("cls");													// Очистка экрана консоли
								cout << "CLOSE - close chat" << endl;							// Постоянный вывод напоминания, какое слово нужно ввести для выхода из чата
								cout << "---------------------------------------------------------------" << endl;
								chats[chatID - 1].showChat();									// Вывод всех сообщений из данного чата на консоль
								cout << "Message: ";
								getline(cin, message);											// Ввод сообщения, либо "CLOSE", чтобы закрыть данный чат
								if (message != "CLOSE")
								{
									chats[chatID - 1].addMessage(message, users[index].getName());		// Отправка сообщения в чат, закрепление его в данном чате
								}
							}
						}
					}
					break;

				default:
					cout << "Incorrect data." << endl;										// Выводим сообщение, если введенные данные не соответствуют предложенным опциям. Процесс выбора чата начинается заново
				}
			} while (access);
			
		}
		
	} while (input != 'q');
	
	return 0;
}
