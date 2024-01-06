# Console-Chat
Консольный Чат позволяет выполнить вход/авторизацию по логину или паролю. В Чате можно отправлять сообщения либо в общий чат, где есть все пользователи, либо в приватный чат с конкретным пользователем.
Логины, пароли, никнеймы, все сообщения в чате сохраняются в отдельных файлах для того, чтобы при закрытии консоли данные не пропадали. При запуске консоли все данные с файлов считываются и запоминаются в локальных переменных функции main(). Затем в нескольких вложенных циклах while происходят последовательно авторизация/регистрация, выбор/создание чата, отправка сообщения или закрытие чата. На каждом этапе предусмотрен выбор опций с помощью специального символа (например, выбор или создание чата, или выход из пользователя). Для каждого чата создается свой файл. Также отдельно создаются еще три файла - для логинов, паролей и никнеймов, соответственно. Соответствие логинов, паролей и никнеймов выполнено построчно, то есть первый логин в файле логинов соответствует первому паролю в файле паролей и первому никнейму в файле никнеймов, вторая строчка соответствуем вторым строчка и т.д.

# Зачем нужен Консольный Чат?
Главная цель данного проекта - освоение языка программирования C++, основных его конструкций, а также принципов ООП. Это начальная стадия проекта, которая в дальнейшем будет совершенствоваться.

# Пользовательские типы данных
Для реализации Консольного Чата созданы следующие пользователские типы данных:

* PublicChat

  Тип данных общего чата.

  Внутри себя имеет поле:
	- string _messages — все сообщения чата.

  А также методы:
	- void SetMessages(string x) — добавление строчки x в _messages;
	- void showChat() — вывод всех сообщений чата на экран консоли;
	- void addMessage(string x, string y) — добавление в _messages строчки x от пользователя с никнеймом y.

* PrivateChat

  Тип данных приватного чата.

  Внутри себя имеет поля:
  	- int _userID1 — ID первого пользователя в чате;
	- int _userID2 — ID второго пользователя в чате;
	- int _chatID — ID чата;
	- string _messages — все сообщения чата.

  А также методы:
  	- void setChatID(int x) — устанавливает в поле _chatID значение x;
	- int getChatID() const — возвращает значение _chatID;
	- void setUserID1(int x) — устанавливает в поле _userID1 значение x;
	- int getUserID1() const — возвращает значение _userID1;
	- void setUserID2(int x) — устанавливает в поле _userID2 значение x;
	- int getUserID2() const — возвращает значение _userID2;
	- void SetMessages(string x) — добавляет в поле _messages строчку x;
	- bool isUserIn(int) — проверка, есть ли пользователь в данном чате с таким ID;
	- void erase() — очистка полей класса;
	- void showChat() — вывод сообщений на консоль;
	- void addMessage(string, string) — добавление сообщения в чат.

* User

  Тип данных пользователей.

  Внутри себя имеет поля:
  	- int _userid — ID пользователя;
  	- string _login — логин пользователя;
  	- string _password — пароль пользователя;
  	- string _username — никнейм пользователя;

  И методы:

  	- void setLogin(string x) — устанавливает строчку x в поле _login;
	- void setPassword(string x) — устанавливает строчку x в поле _password;
	- void setID(int x) — устанавливает строчку x в поле _userid;
	- void setName(string x) — устанавливает строчку x в поле _username;
	- string getLogin() const — возвращает значение _login;
	- string getPassword() const — возвращает значение _password;
	- string getName() const — возвращает значение _username;
	- int getID() const — возвращает значение _userid;
	- void erase() — очистка полей класса;

# Список участников команды
- Кильдюшев Никита, имя пользователя в пачке: n.kildyushev
- Ковальчук Никита, имя пользователя в пачке: nikkitakoval

# Распределение обязанностей

Кильдюшев Никита:
- Написание main() и классов PublicChat и PrivateChat;
- Написание readme.
  
Ковальчук Никита:
- Написание класса User;
- Создание идеи реализации через файлы.
