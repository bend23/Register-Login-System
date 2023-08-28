#include <iostream>
#include <string>
#include <fstream>
#include "Functions.h"
#include "Employee.h"

using namespace std;

string crypto_Key(string token)
{
	for (int i = 0; token[i] != '\0'; i++)
	{
		token[i] = token[i] + 2;
	}
	return token;
}

string decrypt_Key(string decrypt)
{
	for (int i = 0; decrypt[i] != '\0'; i++)
	{
		decrypt[i] = decrypt[i] - 2;
	}
	return decrypt;
}

int integer_Crypting(int num)
{
	string str;
	str = to_string(num);

	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = str[i] + 2;
	}
	return num;
}

int integer_Decrypting(int num)
{
	string str;
	str = to_string(num);

	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = str[i] - 2;
	}

	return num;
}

//verifying if a user already exists
bool check_User(const char* file_name, string input_Username)
{
	fstream MyFile;
	MyFile.open(file_name);
	string lines;

	//string users;

	while (!MyFile.eof())
	{
		getline(MyFile, lines);

		if (decrypt_Key(lines) == input_Username)
		{
			cout << "User already exists! " << endl;
			cout << "Please enter a new user: " << endl;

			return false;
		}
	}
	return true;
}

bool verify_Username(const char* file_name, string registered_Users)
{
	fstream MyFile;
	MyFile.open(file_name);
	string lines;

	if (MyFile.is_open())
	{
		//cout << "Succes open!" << endl;
		while (getline(MyFile, lines))
		{
			if (registered_Users == decrypt_Key(lines))
			{
				cout << "Enter your password: " << endl;
				
				return true;
			}
		}
		cout << "Invalid user or user doesn't exists! " << endl;
		cout << "\n";

		return false;
	}
}

bool verify_Passw(const char* file_name, string registered_Passw)
{
	fstream MyFile;
	MyFile.open(file_name);
	string lines;

	if (MyFile.is_open())
	{
		while (getline(MyFile, lines))
		{
			if (registered_Passw == decrypt_Key(lines))
			{
				cout << "\n";
				cout << "Succesful login!" << endl;
				//cout << "\n";

				return true;
			}
		}

		return false;
	}
}

