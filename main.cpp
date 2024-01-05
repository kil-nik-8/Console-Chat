#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "User.h"
#include "PrivateChat.h"
#include "PublicChat.h"

using namespace std;

int Chats_Count(int n)																	// Функция, которая считает количество всевозможных чатов для заданного количества пользователей
{				
	int Ans = 1;
	n--;
	for (n; n > 1; n--)
		Ans += n;

	return Ans;
}

int ID_Number;																			// Глобальная переменная, определяющая ID следующего нового пользователя
int CHAT_ID;																			// Глобальная переменная, определяющая ID следующего нового чата

int main()
{
	ID_Number = 0;																		// Следующий пользователь будет первым (нулевой ID)
	CHAT_ID = 1;																		// Следующий чат будет вторым (public - 0, private - 1,2,3...)
	char input, open_file[400];
	int a = -1, userID = 0, i, index, chatID = 0, b = -1;
	bool bool1, bool2, access = false;
	string message = "", login, password, name;
	vector<User> users;																	// Контейнер для всех пользователей
	User user;																			// Вспомогательная переменная типа класса пользователей
	vector<PrivateChat> chats;															// Контейнер всех приватных чатов
	PublicChat publicChat;
	PrivateChat chat;																	// Вспомогательная переменная класса приватных чатов
	fstream file;

	file.open("LOGINS.txt");															// Открываем файл со всеми логинами
	if (!file.is_open())																// На случай запуска в первый раз
	{																					// Если нет файла и, соответственно, не удается его открыть
		file.close();																	
		ofstream{ "LOGINS.txt" };														// То создаем его
		file.open("LOGINS.txt");														// И открываем
	}
		
	file.seekg(0, ios_base::end);														// Перемещаем указатель в конец файла
	if (file.tellg())																	// Проверяем, не пустой ли файл
	{
		file.seekg(0, ios_base::beg);													// Перемещаем указатель в начало файла
		while (!file.eof())																// Пока не дойдем до конца файла
		{
			user.erase();																// Очищаем вспомогательную переменную
			file.getline(open_file, 400);												// Считываем из файла строку
			if (string(open_file) != "")												// Если строчка не пустая
			{
				user.setLogin(open_file);												// Запоминаем логин
				user.setID(ID_Number);													// Запоминаем ID пользователя
				users.push_back(user);													// Записываем в контейнер пользователя
				ID_Number++;
			}
		}
	}	
	file.close();																		// Закрываем файл

	file.open("PASSWORDS.txt");															// Открываем файл со всеми паролями
	if (!file.is_open())																// На случай запуска в первый раз (Аналогично с логинами)
	{	
		file.close();
		ofstream{ "PASSWORDS.txt" };
		file.open("PASSWORDS.txt");
	}
	for (i = 0; i < ID_Number; i++)														// Проходим по всем зарегистрированным пользователям
	{
		file.getline(open_file, 400);													// Считываем из файла строку
		users[i].setPassword(open_file);												// Записываем пароли соответствующих пользователей в контейнер
	}
	file.close();																		// Закрываем файл

	file.open("USERNAMES.txt");															// Открываем файл со всеми никнеймами
	if (!file.is_open())																// На случай запуска в первый раз (Аналогично с логинами)
	{
		file.close();
		ofstream{ "USERNAMES.txt" };
		file.open("USERNAMES.txt");
	}
	for (i = 0; i < ID_Number; i++)														// Проходим по всем зарегистрированным пользователям
	{
		file.getline(open_file, 400);													// Считываем из файла строку
		users[i].setName(open_file);													// Записываем никнеймы соответствующих пользователей в контейнер
	}
	file.close();																		// Закрываем файл

	file.open("Public_Chat.txt");														// Открываем файл с сообщениями публичного чата
	if (!file.is_open())																// На случай запуска в первый раз (Аналогично с логинами)
	{
		file.close();
		ofstream{ "Public_Chat.txt" };
		file.open("Public_Chat.txt");
	}
	file.seekg(0, ios_base::end);														// Перемещаем указатель в конец файла
	if (file.tellg())																	// Проверяем, не пустой ли файл
	{
		file.seekg(0, ios_base::beg);													// Перемещаем указатель в начало файла
		while (!file.eof())																// Пока не дойдем до конца файла
		{
			file.getline(open_file, 400);												// Считываем из файла строку
			publicChat.SetMessages(string(open_file));									// Записываем сообщения пользователей публичного чата в переменную класса PublicChat
		}
	}
	file.close();																		// Закрываем файл
	i = Chats_Count(ID_Number);															// Запоминаем количество чатов
	for (i; i >= 1; i--)																// Проходим по всем приватным чатам
	{																					// Первые две строки в файле каждого приватного чата - это ID пользователей в него входящих
		name = "Private_Chat_" + to_string(i) + ".txt";									// Формируем название для открытия файла конкретного приватного чата
		file.open(name);																// Открываем файл
		file.seekg(0, ios_base::end);													// Перемещаем указатель в конец файла
		
		if (file.tellg() && file.is_open())												// Проверяем, не пустой ли файл и удалось ли его открыть
		{
			file.seekg(ios_base::beg);													// Перемещаем указатель в начало файла
			chat.setChatID(i);															// Присваиваем чату ID
			file >> a;																	// Считываем ID первого пользователя в чате
			chat.setUserID1(a);															// Запоминаем ID первого пользователя в чате
			file >> a;																	// Считываем ID второго пользователя в чате
			chat.setUserID2(a);															// Запоминаем ID второго пользователя в чате
			while (!file.eof())															// Пока не дошли до конца файла
			{
				file.getline(open_file, 400);											// Считываем строку из файла
				chat.SetMessages(string(open_file));									// Запоминаем данную строку
			}
			chats.insert(chats.begin(), chat);											// Помещаем данный чат в контейнер приватных чатов
			chat.erase();																// Очищаем вспомогательную переменную
			CHAT_ID++;
		}
		file.close();																	// Закрываем файл
	}

	a = -1;
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
						access = true;																								
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
				access = true;
				
				user.setLogin(login);													// Присваиваем вспомогательной переменной логин
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
					user.setID(ID_Number);												// Устанавливаем ID пользователя

					file.open("LOGINS.txt", ios::app);									// Открываем файл с логинами пользователей
					ID_Number == 0 ? file << login : file << "\n" << login;				// Записываем логин нового пользователя в конец файла
					file.close();														// Закрываем файл

					cout << "Set password: ";
					cin >> password;													// Вводим пароль
					file.open("PASSWORDS.txt", ios::app);								// Открываем файл с паролями пользователей
					ID_Number == 0 ? file << password : file << "\n" << password;		// Записываем пароль нового пользователя в конец файла
					file.close();														// Закрываем файл
					user.setPassword(password);											// Устанавливаем пароль в вспомогательную переменную пользователя

					cout << "Set your UserName: ";
					cin >> name;														// Вводим никнейм
					file.open("USERNAMES.txt", ios::app);								// Открываем файл с никнеймами пользователей
					ID_Number == 0 ? file << name : file << "\n" << name;				// Записываем никнейм нового пользователя в конец файла
					file.close();														// Закрываем файл
					user.setName(name);													// Устанавливаем никнейм в вспомогательную переменную пользователя

					ID_Number++;
					index = ID_Number - 1;												// Запоминаем индекс пользователя, чтобы дальше работать с конкретным пользователем
					users.push_back(user);												// Добавляем информацию пользователя в вектор всех существующих пользователей								
					user.erase();														// Очищаем вспомогательную переменную
				}
				break;

			case 'q':																	// ВЫХОД
				cout << "Are you sure you want to close the Console Chat?" << endl;		// Убеждаемся, что пользователь хочет выйти из консольного чата
				cout << "0 - No" << endl;
				cout << "1 - Yes" << endl;
				cin >> a;
				if (a == 0)
					input = 'f';														// Меняем значение переменной input, чтобы не выйти из цикла															
				break;																	// Иначе, не меняем и выходим из чата

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
					cout << "0 - public chat" << endl;									// Вывод на консоль всех существующих чатов (сначала общий) совместно с их ID
					for (i = 0; i < chats.size(); i++)									// Проходим по всем приватным чатам
					{
						if (chats[i].getUserID1() == users[index].getID())				// Проверяем есть ли в чате авторизованный пользователь
						{
							cout << chats[i].getChatID() << " - chat with user "
								<< users[chats[i].getUserID2()].getName() << endl;		
						}
						else if (chats[i].getUserID2() == users[index].getID())			// Проверяем есть ли в чате авторизованный пользователь
						{
							cout << chats[i].getChatID() << " - chat with user "
								<< users[chats[i].getUserID1()].getName() << endl;
						}
					}

					cout << "Choose chat: ";											
					cin >> chatID;															// Выбор чата по его ID
					message = "";
					if (chatID == 0)														// Выбран публичный чат
					{
						file.open("Public_Chat.txt", ios::app);								// Открываем файл с сообщениями публичного чата
						while (message != "CLOSE")											// Пока пользователь не напишет "CLOSE", чат не закроется
						{
							system("cls");													// Очистка экрана консоли
							cout << "CLOSE - close chat" << endl;							// Постоянный вывод напоминания, какое слово нужно ввести для выхода из чата
							cout << "--------------------------------" 
								<< "-------------------------------" << endl;
							publicChat.showChat();											// Вывод всех сообщений из данного чата на консоль
							cout << "Message: ";
							getline(cin, message);											// Ввод сообщения, либо "CLOSE", чтобы закрыть данный чат
							while (message[0] == ' ')										// Удаляем пробелы из начала сообщения
									message.erase(0, 1);
							if (message != "CLOSE")
							{
								publicChat.addMessage(message, users[index].getName());		// Отправка сообщения в чат, закрепление его в данном чате
								if (message.size() > 0)
									file << users[index].getName() + ": " + message + "\n"; // Записываем также сообщение в файл
							}
						}
						file.close();														// Закрываем файл
					}
					else																	// Если выбран не публичный чат
					{
						for (i = 0; i < chats.size(); i++)									// Проходим по всем приватным чатам
						{
							bool2 = chats[i].getChatID() == chatID;							// Находим чат с введенным пользователем ID
							if (bool2)
							{
								bool1 = chats[i].getUserID1() == users[index].getID() || chats[i].getUserID2() == users[index].getID();
								if (bool1)													// Проверяем, действительно ли авторизованным пользователь есть в данном чате
								{
									name = "Private_Chat_" + to_string(chatID) + ".txt";	// Формируем имя для открытия файла нужного приватного чата
									file.open(name, ios::app);								// Открываем файл с нужным приватным чатом
									while (message != "CLOSE")								// Пока пользователь не напишет "CLOSE", чат не закроется
									{
										system("cls");										// Очистка экрана консоли
										cout << "CLOSE - close chat" << endl;				// Постоянный вывод напоминания, какое слово нужно ввести для выхода из чата
										cout << "--------------------------------"
											<< "-------------------------------" << endl;
										chats[chatID - 1].showChat();						// Вывод всех сообщений из данного чата на консоль
										cout << "Message: ";
										getline(cin, message);								// Ввод сообщения, либо "CLOSE", чтобы закрыть данный чат
										while (message[0] == ' ')							// Удаляем пробелы из начала сообщения
											message.erase(0, 1);
										if (message != "CLOSE")
										{
											chats[chatID - 1].addMessage(message, users[index].getName());	// Отправка сообщения в чат, закрепление его в данном чате
											if (message.size() > 0)
												file << users[index].getName() + ": " + message + "\n";	// Записываем также сообщение в файл
										}
									}
									file.close();											// Закрываем файл
								}
								else														// Вывод сообщения в случае введения некорректных данных
								{
									cout << "Incorrect data." << endl;					
									message = "CLOSE";
									system("pause");
								}
							}
						}
					}
					break;

				case 2:																		// СОЗДАНИЕ НОВОГО ПРИВАТНОГО ЧАТА
					a = 0;
					for (i = 0; i < users.size(); i++)										// Проходим по всем зарегистрированным пользователям
					{
						access = true;
						if (i != index)														// Препятствуем созданию чата с самим собой
						{
							for (int j = 0; j < chats.size(); j++)							// Проходим по всем приватным чатам
							{
								bool1 = chats[j].isUserIn(users[i].getID());				
								bool2 = chats[j].isUserIn(users[index].getID());
								if (bool1 * bool2)											// Проверка, есть ли чат с авторизованным и указанным пользователями 
								{
									j = chats.size();										// Выход из цикла
									access = false;											
								}
							}
							if (access)														// Если уже созданного такого чата не нашлось
							{
								cout << "User ID: " << users[i].getID()
									<< " - " << users[i].getName() << endl;					// Вывод на консоль, что с данным пользователем можно создать новый приватный чат
								a = 1;
							}
						}
					}
					if (a == 0)																// Если создать чат нельзя (уже существует)
					{
						cout << "Impossible to create new chat."
							<< " Chats for all users have been already created." << endl;	// Вывод информации на консоль
						system("pause");
						access = true;														// Устанавливаем значение true, чтобы не выйти из пользователя
					}
					else																	// Если создать новый чат можно
					{
						cout << endl << "Enter user ID: " << endl;
						cin >> userID;														// Вводим ID пользователя, кому хотим написать
						for (i = 0; i < users.size(); i++)									// Проходим по всем пользователям
						{
							if (users[i].getID() == userID)									// Проверка на существования пользователя с таким ID
							{
								system("cls");												// Очистка экрана консоли					
								chat.setUserID1(users[index].getID());						// Запоминаем ID первого пользователя в чате 
								chat.setUserID2(userID);									// Запоминаем ID второго пользователя в чате
								chat.setChatID(CHAT_ID);									// Запоминаем ID чата
								chatID = CHAT_ID;											// Получаем ID чата с пользователем, у которого ID - UserID
								name = "Private_Chat_" + to_string(CHAT_ID) + ".txt";		// Формируем название для создания нового файла для нового чата
								ofstream{ name };											// Создаем файл с нужным названием
								CHAT_ID++;
								chats.push_back(chat);										// Добавляем новый чат в контейнер всех приватных чатов

								file.open(name, ios::app);									// Открываем файл для записи
								file.clear();												// Сбрасываем флаги ошибок для формирования потока ввода
								file << to_string(chat.getUserID1()) << endl;				// Записываем ID первого пользователя в чате
								file << to_string(chat.getUserID2()) << endl;				// Записываем ID второго пользователя в чате
								message = "";

								while (message != "CLOSE")									// Пока пользователь не напишет "CLOSE", чат не закроется
								{
									system("cls");											// Очистка экрана консоли
									cout << "CLOSE - close chat" << endl;					// Постоянный вывод напоминания, какое слово нужно ввести для выхода из чата
									cout << "--------------------------------"
										<< "-------------------------------" << endl;
									chats[chatID - 1].showChat();							// Вывод всех сообщений из данного чата на консоль
									cout << "Message: ";
									getline(cin, message);									// Ввод сообщения, либо "CLOSE", чтобы закрыть данный чат
									while (message[0] == ' ')										// Удаляем пробелы из начала сообщения
										message.erase(0, 1);
									if (message != "CLOSE")
									{
										chats[chatID - 1].addMessage(message, users[index].getName());	// Отправка сообщения в чат, закрепление его в данном чате
										if (message.size() > 0)
											file << users[index].getName() + ": " + message + "\n";	// Записываем также сообщение в файл
									}
								}
								file.close();												// Закрываем файл
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
