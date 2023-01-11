#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void PrintMenu()
{
	std::cout << "1 for create a new employee" << std::endl;
	std::cout << "2 for delete an employee" << std::endl;
	std::cout << "3 for print all employees" << std::endl;
	std::cout << "4 to quit" << std::endl;
	std::cout << "Choose your destiny!" << std::endl;
};

int GetValueFromUser()
{
	int userInput = 0;
	std::cin >> userInput;
	return userInput;
}

std::string GetStringFromUser(std::string prompt)
{
	std::cout << prompt << std::endl;
	std::string userValue;
	std::cin >> userValue;
	return userValue;
}
class Employee
{
public:
	Employee(int id, std::string firstName, std::string lastName);
	~Employee();
	std::string GetString() const;

private:
	int Id;
	std::string LastName;
	std::string FirstName;
};

Employee::Employee(int id, std::string firstName, std::string lastName) : Id(id), FirstName(FirstName), LastName(lastName)
{
}

Employee::~Employee()
{
}

std::string Employee::GetString() const
{
	return "ID: " + std::to_string(this->Id) + " Last Name: " + this->LastName + " First Name: " + this->FirstName;
}

class EmployeeDatabase
{
public:
	EmployeeDatabase() : database{} {};
	~EmployeeDatabase() {};
	void CreateNewEmployee(std::string firstName, std::string lastName) 
	{
		Employee e(lastUsedId++, firstName, lastName);
		database.push_back(e);
	};
	void PrintEmployees()
	{
		for (size_t i = 0; i < database.size(); i++)
		{
			std::cout << database[i].GetString() << std::endl;
		}
	};
private:
	int lastUsedId = 0;
	std::vector<Employee> database;
};

void CreateNewEmployee(EmployeeDatabase & database)
{
	std::string firstName = GetStringFromUser("Enter first name.");
	std::string lastName = GetStringFromUser("Enter last name.");
	database.CreateNewEmployee(firstName, lastName);
};

void DeleteEmployee(int id, EmployeeDatabase & database)
{};

void PrintEmployees(EmployeeDatabase & database)
{
	database.PrintEmployees();
};



int main()
{
	bool repeatCommand = true;
	EmployeeDatabase database;
	do
	{
		PrintMenu();
		auto userSelection = GetValueFromUser();
		switch (userSelection)
		{
		case 1:
			CreateNewEmployee(database);
			break;
		case 2:
			DeleteEmployee(1, database);
			break;
		case 3:
			PrintEmployees(database);
			break;
		case 4:
			repeatCommand = false;
			break;
		default:
			break;
		}
	} while (repeatCommand);
}