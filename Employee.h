#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
	string first_Name;
	string last_Name;
	int empl_Age;
	string empl_Department;

	string username;
	string password;

public:
	void set_first_Name(string first_name);
	string get_first_Name();

	void set_last_Name(string last_name);
	string get_last_Name();

	void set_empl_Age(int empl_age);
	int get_empl_Age();

	void set_empl_Department(string empl_department);
	string get_empl_Department();

	Employee();
	Employee(string first_name, string last_name);
	Employee(string empl_department);
	Employee(string first_name, string last_name, int empl_Age, string empl_department);

	void employee_Account();
	bool Login();
};