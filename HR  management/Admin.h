#pragma once
#include<vector>
#include"Employee.h"
#include"Candidate.h"
#include"Person.h"
using namespace std;


class Admin{
private:
	static vector<Candidate>List_of_candidates;
	static vector<Employee>List_of_employees;
	static vector<Candidate>List_of_prommising_Candidates;
public:

	/*~Admin() {
		List_of_employees.clear();
		List_of_candidates.clear();
		List_of_prommising_Candidates.clear();
	}*/

	//Create Employee (enter all the data from a console)

	// Member function that create and return employee, while also add it into a vector
	Employee create_employee() {
		string Name, Address, Email, Phone_number;
		unsigned int Age;
		int Year_of_enrolling, Contract_duration;
		string Position;
		double Salary;

		cout << "\nInput data of an employee: " << endl;
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
		List_of_employees.shrink_to_fit();
		return emp;

	}
	//create Candidate (enter all the data from a console)
	Candidate create_candidate() {

		string Name, Address, Email, Phone_number;
		unsigned int Age;
		vector<string> Skills;
		int Experience;
		cout << "\nInput data of a candidate: " << endl;
		cout << "Input Name: "; cin >> Name;
		cout << "Input Age: "; cin >> Age;
		cout << "Input Address: "; cin >> Address;
		cout << "Input Email: "; cin >> Email;
		cout << "Input Phone_number: "; cin >> Phone_number;
		cout << "Input Experience in years: "; cin >> Experience;
		
		Candidate cand(Name, Age, Address, Email, Phone_number, Experience);
		cand.set_skills();
		List_of_candidates.push_back(cand);
		List_of_candidates.shrink_to_fit();
		return cand;

	}

	//Create Candidate and indicate skills beforehand
	Candidate create_candidate(vector<string>& skills) {

		string Name, Address, Email, Phone_number;
		unsigned int Age;
		vector<string> Skills;
		int Experience;
		cout << "\nInput data of a candidate: " << endl;
		cout << "Input Name: "; cin >> Name;
		cout << "Input Age: "; cin >> Age;
		cout << "Input Address: "; cin >> Address;
		cout << "Input Email: "; cin >> Email;
		cout << "Input Phone_number: "; cin >> Phone_number;
		cout << "Input Experience in years: "; cin >> Experience;

		Candidate cand(Name, Age, Address, Email, Phone_number, Experience, skills);
		List_of_candidates.push_back(cand);
		List_of_candidates.shrink_to_fit();
		return cand;

	}

	vector<Candidate> get_Candidates() {
		return List_of_candidates;
	}

	void display_candidates() {
		for (int i = 0; i < List_of_candidates.size(); i++) {
			cout << i + 1 << List_of_candidates[i].get_name() << endl;
		}
	}

	void show_info(Employee obj) {
		obj.display_info();
	}

	void show_info(Candidate obj) {
		obj.display_info();
	}

	//Find and Sort candidates indicating skills required (strict and NOT strict search)
	//Write promissing candidates into a .dat file and output on the console
	//Acept Candidates
	// 
	// Check If the contract of employee is still valid if not prolong a contract or delete employee

	void recruitment(vector<string>& skills_required) {

		//Transform into lower case


	/*	for (int x = 0; x < List_of_candidates.size(); x++) {
			for (int y = 0; y < List_of_candidates[x].get_skills().size(); y++) {
				for (int z = 0; z < List_of_candidates[x].get_skills()[y].size(); z++) {
					putchar(tolower(List_of_candidates[x].get_skills()[y][z]));
				}
			}
			
		}

		for (int x = 0; x < skills_required.size(); x++){
			for (int y = 0; y < skills_required[x].length(); y++)
				putchar(tolower(skills_required[x][y]));
		}		
	*/
		

		for (int i = 0; i < List_of_candidates.size(); i++) {
			int relevant_slkills = 0;
			for (int j = 0; j < skills_required.size(); j++) {
				for (int k = 0; k < List_of_candidates[i].get_skills().size(); k++) {
					if (skills_required[j] == List_of_candidates[i].get_skills()[k]) {
						relevant_slkills++;
					}
				}
			}

			int rating = (int) ceil(100 * relevant_slkills / skills_required.size());
			List_of_candidates[i].set_rating(rating);
		}



		//return;
	}

};