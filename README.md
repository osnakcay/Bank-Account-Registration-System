# Bank-Account-Registration-System
Easy bank account management.
# The Purpose
This program creates a simple bank account management program using C ++ language.
# How to use
There are 6 options in the menu:
- Create bank account
- View registered bank accounts
- Search for a bank account
- Update bank account
- Delete bank account
- Quit
# Listed bank account information
- Account Number
- First Name
- Last Name
- Total Balance
# Generated Functions
- readData(); --> Receives information from the user.
- getData(); --> Prints user data to the screen.
- writeRegister(); --> Writes information entered by users into "accountDatabase.txt" file.
- getRegister(); --> It takes the data from the "accountDatabase.txt" file and prints the data to the screen by running the getData() function.
- searchRegister(); --> It extracts the number of users in the database and prints the data in the desired order on the screen.
- setRegister(); --> Updates the selected user's data by executing the readData() function.
- removeRegister(); --> Deletes selected user data from the database.
# Included Libraries
- iostream
- fstream
# Some of the ready functions used:
- reinterpret_cast(); --> Convert integer types to pointer types and vice versa and convert one pointer type to another.
- seekg(); --> is a function in the iostream library that allows us to seek an arbitrary position in a file.
It is mainly used to set the position of the next character to be extracted from the input stream from a given file in C++ file handling.
- tellg(); --> The function is used with input streams and returns the current “get” position of the pointer in the stream.
It has no parameters and returns a value of the member type pos_type, which is an integer data type representing the current position of the get stream pointer.
