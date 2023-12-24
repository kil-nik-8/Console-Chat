#include <iostream>
#include <vector>
#include "User.h"
#include "Message.h"

using namespace std;

int ID_Number;																			// Глобальная переменная, определяющая ID следующего нового пользователя

int main()
{
	ID_Number = 1;																		// Следующий пользователь будет первым
	char input;
	int a = -1, userID = 0, i, index, chatID = 0, b = -1;
	string message = "", login, password;
	vector<User> users;																	// Контейнер для всех пользователей
	User user;																			// Вспомогательная переменная типа класса пользователей
	vector<Message> chats;
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
				cout << "4 - change user" << endl;
				
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
					users[index].getChatList();											// Вывод на консоль всех существующих чатов (сначала общий) совместно с их ID и количеством непрочитанных сообщений
					cout << "Choose chat: ";											
					cin >> chatID;														// Выбор чата по его ID
					message = "";
					while (message != "CLOSE")											// Пока пользователь не напишет "CLOSE", чат не закроется
					{
						system("cls");													// Очистка экрана консоли
						cout << "CLOSE - close chat" << endl;							// Постоянный вывод напоминания, какое слово нужно ввести для выхода из чата
						cout << "---------------------------------------------------------------" << endl;
						users[index].showChat(chatID);									// Вывод всех сообщений из данного чата на консоль
						cout << "Message: ";
						cin >> message;													// Ввод сообщения, либо "CLOSE", чтобы закрыть данный чат
						if (message != "CLOSE")
						{
							message += "\n";
							users[index].sendMessage(chatID, message);					// Отправка сообщения в чат, закрепление его в данном чате
						}
					}
					break;

				case 2:																	// СОЗДАНИЕ НОВОГО ПРИВАТНОГО ЧАТА
					cout << "Enter user ID: " << endl;
					cin >> userID;														// Вводим ID пользователя, кому хотим написать
					for (i = 0; i < users.size(); i++)									// Проходим по всем пользователям
					{
						if (users[i].getID() == userID)									// Проверка на существования пользователя с таким ID
						{
							system("cls");												// Очистка экрана консоли
							users[index].startChatWith(userID);							// Создание нового элемента класса чатов 
							{
								Message AB;
								AB._senderID = users[index].getID();
								AB._addressID = userID;
								-----
									users[index].addChat(AB);
								users[userID].addChat(AB);
								
							}
							chatID = (users[index]._chats).getChatID(userID);			// Получаем ID чата с пользователем, у которого ID - UserID
							cout << "Message: ";
							cin >> message;												// Ввод сообщения
							users[index].sendMessage(chatID, message);					// Отправка сообщения в чат, закрепление его в данном чате
						}
					}
					break;

				default:
					cout << "Incorrect data." << endl;									// Выводим сообщение, если введенные данные не соответствуют предложенным опциям. Процесс выбора чата начинается заново
				}
			} while (access);
			
		}
		
	} while (input != 'q');
	
	return 0;
}
