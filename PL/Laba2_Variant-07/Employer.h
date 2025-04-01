#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <cstring>
#include <iostream>

using namespace std;

class employee
{
public:
	int change_salary(float);
	long get_id(void);

	employee(const char* name, long employee_id, float salary)
	{
		strcpy(this->name, name);
		this->employee_id = employee_id;
		if (salary < 50000.0)
			this->salary = salary;
		else
			this->salary = 0.0;
	}
	employee(const char* name, long employee_id)
	{
		strcpy(this->name, name);
		this->employee_id = employee_id;
		do
		{
			cout << "Write USDT for " << name << " less them $50000: ";
			cin >> this->salary;
		} while (salary >= 50000.0);
	}
	void show_employee(void)
	{
		cout << "Employer: " << this->name << endl;
		cout << "Emp's number: " << this->employee_id << endl;
		cout << "USD: " << this->salary << endl;
	}
	~employee(void)
	{
		cout << "Delete object for " << name << endl;
	}

private:
	char name[64];
	long employee_id;
	float salary;
};