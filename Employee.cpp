#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Employee.h"
#include "Functions.h"

using namespace std;

void Employee::set_first_Name(string first_name)
{
	first_Name = first_name;
}

string Employee::get_first_Name()
{
	return first_Name;
}

void Employee::set_last_Name(string last_name)
{
	last_Name = last_name;
}

string Employee::get_last_Name()
{
	return last_Name;
}

void Employee::set_empl_Age(int empl_age)
{
	empl_Age = empl_age;
}

int Employee::get_empl_Age()
{
	return empl_Age;
}

void Employee::set_empl_Department(string empl_department)
{
	empl_Department = empl_department;
}

string Employee::get_empl_Department()
{
	return empl_Department;
}

//CONSTRUCTORS
Employee::Employee()
{
	//default empty constructor
}

Employee::Employee(string first_name, string last_name)
{
	this->first_Name = first_name;
	this->last_Name = last_name;

	cout << "Registered employee's first name: " << first_Name << endl;
	cout << "Registered employee's last name: " << last_Name << endl;
}

Employee::Employee(string empl_department)
{
	this->empl_Department = empl_department;

	cout << "The employee's department: " << empl_Department << endl;
}

Employee::Employee(string first_name, string last_name, int empl_age, string empl_department)
{
	this->first_Name = first_name;
	this->last_Name = last_name;
	this->empl_Age = empl_age;
	this->empl_Department = empl_department;

	cout << "Registered employee's first name: " << first_Name << endl;
	cout << "Registered employee's last name: " << last_Name << endl;
	cout << "The employee's age: " << empl_Age << endl;
	cout << "The employee's department: " << empl_Department << endl;
}

void Employee::employee_Account()
{
	cout << "If you want to login PRESS 0! " << endl;
	cout << "If you want to register PRESS 1! " << endl;
	cout << "\n";

	int x;
	cin >> x;
	cout << "\n";

	string name_First; string name_Last; int age_Employee; string department_Employee; 
	string empl_Username; string empl_Password;

	age_Employee = 0; 

	this->first_Name = name_First;
	this->last_Name = name_Last;
	this->empl_Age = age_Employee;
	this->empl_Department = department_Employee;
	this->username = empl_Username;
	this->password = empl_Password;

	fstream data_file;
	string lines;

	fstream account_file;
	string text;

	string answer;
	string registered_Passw;

	switch (x)
	{
	default:
		cout << "Invalid option" << endl;
		cout << "\n";
		employee_Account();

	case 0:		//LOGIN
		
		cout << "Please enter your username: " << endl;
		cin >> empl_Username;
		
		if (verify_Username("User_n_Passw.txt", empl_Username) == true)
		{
			cin >> registered_Passw;
			
			for (; verify_Passw("User_n_Passw.txt", registered_Passw) == false;)
			{
				cout << "Incorrect password! Try again:" << endl;
				cin >> registered_Passw;
			}
			cout << "Welcome " << empl_Username << "!" << endl;
			cout << "\n";
		}

		cout << "Do you want any other operation? " << endl;
		cout << "Press [Y/N]" << endl;
		cin >> answer;

		if (answer == "y" || answer == "Y")
		{
			employee_Account();
		}
		else if (answer == "n" || answer == "N")
		{

		}
		else for ( ; answer != "y" || answer != "Y" || answer != "n" || answer != "N"; )
		{
			cout << "Please enter a valid key! " << endl;
			cout << "[Y/N]" << endl;
			cin >> answer;

			if (answer == "y" || answer == "Y")
			{
				employee_Account();
			}
			else if (answer == "n" || answer == "N")
			{
				break;
			}
		}
		break;

	case 1:
		 //Without opening the file

		cout << "Enter the first name: " << endl;
		cin >> name_First;

		cout << "Enter the last name: " << endl;
		cin >> name_Last;

		cout << "Enter the age: " << endl;
		cin >> age_Employee;

		cout << "Enter the department: " << endl;
		cin >> department_Employee;

		cout << "\n";

		cout << "Set username: " << endl;
		cout << "General: please note that username must be uniqe! " << endl;
		cin >> empl_Username;
		cout << "\n";
		for ( ; check_User("User_n_Passw.txt", empl_Username) == false ; )
		{
			cout << "\n";
			cin >> empl_Username;
			cout << "\n";
		}
		
		cout << "Set up password: " << endl;
		cin >> empl_Password;

		cout << "\n";
		/*///////////////////////////////////////////////////////////////////////////////////////////////////*/

		cout << "Please CHECK the entered  data!" << endl;
		cout << "\n";

		cout << "First name: " << endl;
		cout << name_First << endl;
		cout << "\n";

		cout << "Last name: " << endl;
		cout << name_Last << endl;
		cout << "\n";

		cout << "Age: " << endl;
		cout << age_Employee << endl;
		cout << "\n";

		cout << "Department: " << endl;
		cout << department_Employee << endl;
		cout << "\n";

		cout << "Username: " << endl;
		cout << empl_Username << endl;
		cout << "\n";

		cout << "Password: " << endl;
		cout << empl_Password << endl;
		cout << "\n";

		cout << "\n";

		cout << "Is the data correct!" << endl;
		cout << "[Y/N]" << endl;

		string y;
		cin >> y;

		if (y == "y" || y == "Y")
		{
			fstream data_file("Data.txt", ios::app);
			fstream account_file("User_n_Passw.txt", ios::app);

			name_First = crypto_Key(name_First);
			data_file << name_First;
			data_file << "\n";

			name_Last = crypto_Key(name_Last);
			data_file << name_Last;
			data_file << "\n";

			string integer_String;
			integer_String = to_string(age_Employee);
			integer_String = crypto_Key(integer_String);
			data_file << integer_String;
			data_file << "\n";

			department_Employee = crypto_Key(department_Employee);
			data_file << department_Employee;
			data_file << "\n";

			empl_Username = crypto_Key(empl_Username);
			account_file << empl_Username;
			account_file << "\n";
			data_file << empl_Username;
			data_file << "\n";

			empl_Password = crypto_Key(empl_Password);
			account_file << empl_Password;
			account_file << "\n";
			data_file << empl_Password;
			data_file << "\n";

			data_file << "\n";
			account_file << "\n";
			data_file.close();
			account_file.close();
		}
		else if (y == "n" || y == "N")
		{
			cout << "\n";
			fstream data_file("Data.txt", ios::app); //append mode --> TO SAVE THE FILE PERMANENTLY/ OVERWRITE THE FILE
			fstream account_file("User_n_Passw.txt", ios::app);

			employee_Account();
		}
		else for (; y != "y" || y != "Y" || y != "n" || y != "N";)
		{
			cout << "\n";
			string z;
			cout << "ERROR! Enter a valid key!" << endl;
			cout << "Press [Y/N]" << endl;
			cin >> z;
			if (z == "y" || z == "Y")
			{
				fstream data_file("Data.txt", ios::app);
				fstream accout_file("User_n_Passw.txt", ios::app);

				name_First = crypto_Key(name_First);
				data_file << name_First;
				data_file << "\n";

				name_Last = crypto_Key(name_Last);
				data_file << name_Last;
				data_file << "\n";

				string integer_String;
				integer_String = to_string(age_Employee);
				integer_String = crypto_Key(integer_String);
				data_file << integer_String;
				data_file << "\n";

				department_Employee = crypto_Key(department_Employee);
				data_file << department_Employee;
				data_file << "\n";

				empl_Username = crypto_Key(empl_Username);
				account_file << empl_Username;
				account_file << "\n";
				data_file << empl_Username;
				data_file << "\n";

				empl_Password = crypto_Key(empl_Password);
				account_file << empl_Password;
				account_file << "\n";
				data_file << empl_Password;
				data_file << "\n";

				data_file << "\n";
				account_file << "\n";
				data_file.close();
				break;
			}
			else if (z == "n" || z == "N")
			{
				cout << "\n";
				fstream data_file("Data.txt", ios::app);
				fstream accout_file("User_n_Passw.txt", ios::app);

				employee_Account();
			}
		}
	}
}
