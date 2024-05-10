#pragma once
#include"Employee.h"
#include"Candidate.h"
#include"Person.h"
using namespace std;

class Admin{
private:
	vector<Candidate>List_of_candidates;
	vector<Employee>List_of_employees;
public:

	//Create Employee (enter all the data from a console)

	// Member function that create and return employee, while also add it into a vector
	Employee create_employee() {
		string Name, Address, Email, Phone_number;
		unsigned int Age;
		int Year_of_enrolling, Contract_duration;
		string Position;
		double Salary;
		cout << "Input data of an employee: " << endl;
		cout << "Input Name: "; cin >> Name;
		cout << "Input Age: "; cin >> Age;
		cout << "Input Address: "; cin >> Address;
		cout << "Input Email: "; cin >> Email;
		cout << "Input Phone_number: "; cin >> Phone_number;
		cout << "Input Year of enroolment: "; cin >> Year_of_enrolling;
		cout << "Contract_duration: "; cin >> Contract_duration;
		cout << "Input Position: "; cin >> Position;
		cout << "Input Salary: "; cin >> Salary;

		Employee emp(Name, Age, Address, Email, Phone_number, Year_of_enrolling, Position, Contract_duration, Salary);
		List_of_employees.push_back(emp);
		return emp;

	}
	//create Candidate (enter all the data from a console)
	Candidate create_candidate() {

		string Name, Address, Email, Phone_number;
		unsigned int Age;
		vector<string> Skills;
		int Experience;
		bool Accepted;
		cout << "Input data of an employee: " << endl;
		cout << "Input Name: "; cin >> Name;
		cout << "Input Age: "; cin >> Age;
		cout << "Input Address: "; cin >> Address;
		cout << "Input Email: "; cin >> Email;
		cout << "Input Phone_number: "; cin >> Phone_number;
		cout << "Input Experience: "; cin >> Experience;
		cout << "Input Status (1 - accepted, 0 - not accepted): "; cin >> Accepted;
		
		Candidate cand(Name, Age, Address, Email, Phone_number, Experience);
		cand.set_skills();
		List_of_candidates.push_back(cand);
		return cand;

	}

	//Create Candidate and indicate skills beforehand
	Candidate create_candidate(vector<string>& skills) {

		string Name, Address, Email, Phone_number;
		unsigned int Age;
		vector<string> Skills;
		int Experience;
		bool Accepted;
		cout << "Input data of an employee: " << endl;
		cout << "Input Name: "; cin >> Name;
		cout << "Input Age: "; cin >> Age;
		cout << "Input Address: "; cin >> Address;
		cout << "Input Email: "; cin >> Email;
		cout << "Input Phone_number: "; cin >> Phone_number;
		cout << "Input Experience: "; cin >> Experience;
		cout << "Input Status (1 - accepted, 0 - not accepted): "; cin >> Accepted;

		Candidate cand(Name, Age, Address, Email, Phone_number, Experience, skills);
		List_of_candidates.push_back(cand);
		return cand;

	}

	//Find and Sort candidates indicating skills required (strict and NOT strict search)
	//Write promissing candidates into a .dat file and output on the console
	//Acept Candidates
	// 
	// Check If the contract of employee is still valid if not prolong a contract or delete employee


};