#pragma once
#include <iostream>
#include <string>

using namespace std;


class Employee
{
private:
	string name;
	string position;
	double salary;
public:
	// Default constructor
	Employee(){
		name = "Unknown";
		position = "Unknown";
		salary = 0.0;
	}
	// Parametrized constructor
	Employee(string name, string position, double salary ){
		this->name = name;
		this->position = position;
		this->salary = salary;
	}


};



class AddEmployee
{



};