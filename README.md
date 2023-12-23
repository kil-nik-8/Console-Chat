# Console-Chat
Консольный Чат позволяет выполнить вход/авторизацию по логину или паролю. В Чате можно отправлять сообщения либо в общий чат, где есть все пользователи, либо в приватный чат с конкретным пользователем.

# Зачем нужен Консольный Чат?
Главная цель данного проекта - освоение языка программирования C++, основных его конструкций, а также принципов ООП. Это начальная стадия проекта, которая в дальнейшем будет совершенствоваться.

# Пользовательские типы данных
Для реализации Консольного Чата созданы следующие пользователские типы данных:
* Chat
  Тип данных чатов (общего и приватных).
  Внутри себя имеет поля:
  - int _ID – ID номер чата;
  - vector<vector<string>> _messages - вектор из векторов сообщений каждого чата.
  А также методы:
  - 

* User
  Тип данных пользователей.
  Внутри себя имеет поля:
  - string _login - логин пользователя;
  - string _password - пароль пользователя;
  - vector<Chat> _chats - вектор из чатов, в которых состоит конкретный пользователь (по умолчанию есть хотя бы один - общий).
  И методы:
  - getLogIn() - возвращает логин данного пользователя;
  - setLogIn(string x) - устанавливает в поле _login значение переменной x;
  - getPassword() - возвращает пароль данного пользователя;
  - setPassword(string x) - устанавливает в поле _password значение переменной x;
  - getID() - возвращает ID-номер данного пользователя;
  - setID(int id) - устанавливает в поле _ID значение переменной id;
  - getChatList() - возвращает элемент типа string - информация о доступных пользователю чатах и количестве непрочитанных сообщениях в каждом;
  - showChat(int chat_id) - выводит на консоль все сообщения чата с ID-номером, равным chat_id;
  - sendMessage(int chat_id, string x) - отправляет сообщение x в чат с ID-номером, равным chat_id;
  - startChatWith(int user_id) - создает новый приватный чат с пользователем с ID-номером, равным user_id;
