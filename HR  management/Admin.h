#pragma once
#include <fstream>
#include"Employee.h"
#include"Candidate.h"
#include"Person.h"
using namespace std;

//THINGS TO DO HERE

//Find and Sort candidates indicating skills required (strict and NOT strict search)
//Write promissing candidates into a .dat file and output on the console

// Check If the contract of employee is still valid if not prolong a contract or delete employee

class Admin{
private:
	vector<Candidate>List_of_candidates;
	vector<Employee>List_of_employees;
	vector<Candidate>List_of_prommising_Candidates;

	bool compare_Candidates(Candidate& a, Candidate& b);
	void sort_Candidates_By_Rating(vector<Candidate>& candidates);
public:

	/*~Admin() {
		List_of_employees.clear();
		List_of_candidates.clear();
		List_of_prommising_Candidates.clear();
	}*/
	//Create Employee (enter all the data from a console)
	Employee create_employee(); 
	//create Candidate (enter all the data from a console)
	Candidate create_candidate();
	//Create Candidate and indicate skills beforehand
	Candidate create_candidate(vector<string>& skills);
	//Create candidate with all parametres
	Candidate create_candidate(const string& Name, unsigned int Age, string Address, string Phone_number, string Email, int Experience, vector<string>& skills);

	vector<Candidate> search_candidate_by_name(const string& name);

	vector<Candidate> get_Candidates();

	void display_candidates(); 
	void show_info(Employee obj);
	void show_info(Candidate obj);

	//Set value of the Candidates rating according to the skills required
	void recruitment(vector<string>& skills_required);

	//This two functions delete inappropriate candidates
	void Sort_candidates_by_requirements(int experience_required, int manimal_rating);
	void Sort_candidates_by_requirements(int minimal_rating);

	void Write_canditate_to_file(Candidate& candidate);
	void Read_canditate_from_file();


	

};

//Create candidate with all parametres
Candidate Admin::create_candidate(const string& Name, unsigned int Age, string Address, string Phone_number, string Email, int Experience, vector<string>& skills) {
	Candidate cand(Name, Age, Address, Email, Phone_number, Experience, skills);
	List_of_candidates.push_back(cand);
	List_of_candidates.shrink_to_fit();
	return cand;
}


//Create Employee (enter all the data from a console)
Employee Admin::create_employee() {
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
Candidate Admin::create_candidate() {
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
Candidate Admin::create_candidate(vector<string>& skills) {
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


vector<Candidate> Admin::search_candidate_by_name(const string& name) {
	vector<Candidate> Result;
	for (int i = 0; i < List_of_candidates.size(); i++) {
		if (List_of_candidates[i].get_name() == name) {
			Result.push_back(List_of_candidates[i]);
		}
	}
	return Result;
}

vector<Candidate> Admin::get_Candidates() {
	return List_of_candidates;
}

void Admin::display_candidates() {
	for (int i = 0; i < List_of_candidates.size(); i++) {
		cout << i + 1 << "" << List_of_candidates[i].get_name() << endl;
	}
}

void Admin::show_info(Employee obj) {
	obj.display_info();
}

void Admin::show_info(Candidate obj) {
	obj.display_info();
}

void Admin::recruitment(vector<string>& skills_required) {
	for (int i = 0; i < List_of_candidates.size(); i++) {
		int relevant_slkills = 0;
		for (int j = 0; j < skills_required.size(); j++) {
			for (int k = 0; k < List_of_candidates[i].get_skills().size(); k++) {
				if (skills_required[j] == List_of_candidates[i].get_skills()[k]) {
					relevant_slkills++;
					break;
				}
			}
		}

		int rating = (int)ceil(10 * relevant_slkills / skills_required.size());
		List_of_candidates[i].set_rating(rating);
	}
}

//This two functions delete inappropriate candidates
void Admin::Sort_candidates_by_requirements(int experience_required, int minimal_rating) {
	for (int i = 0; i < List_of_candidates.size(); i++) {
		if ((List_of_candidates[i].get_experience() >= experience_required && List_of_candidates[i].get_rating() >= minimal_rating)) {
			List_of_prommising_Candidates.push_back(List_of_candidates[i]);
			List_of_candidates[i].set_status(true);
		}
	}
	sort_Candidates_By_Rating(List_of_prommising_Candidates);
}

void Admin::Sort_candidates_by_requirements(int minimal_rating) {
	for (int i = 0; i < List_of_candidates.size(); i++) {
		if (List_of_candidates[i].get_rating() >= minimal_rating) {
			List_of_prommising_Candidates.push_back(List_of_candidates[i]);
			List_of_candidates[i].set_status(true);
		}
	}
	sort_Candidates_By_Rating(List_of_prommising_Candidates);
}

//Loop to traverse vector List of promissing candidates
//Use fu nction search_candidate_by_name

void Admin::Write_canditate_to_file(Candidate& candidate)
{
	
	ofstream outfile("Candidate.dat", ios::app);
	if (!outfile.is_open())
	{
		cout << "Error opening file for writing" << endl;
	}
	else
	{
		outfile << candidate.get_name() << " - " << candidate.get_rating() << endl;
		
	}
	outfile.close();
}


void Admin::Read_canditate_from_file()
{
	ifstream infile("Candidate.dat", ios::app);
	string name;
	int rating;
	if (!infile.is_open())
	{
		cout<< "Error opening file for reading" << endl;
	}
	else
	{
		while (getline(infile, name, '-'))
		{
			infile >> rating;
			infile.ignore();
			cout << "Name: " << name << endl;
			cout << "Rating: " << rating << endl;
		}
	}
	infile.close();
}


// Custom comparison function for sorting candidates by rating in descending order
bool Admin::compare_Candidates(Candidate& a, Candidate& b) {
	return a.get_rating() > b.get_rating(); // Higher rating first
}

// Function to sort the vector of candidates by rating
void Admin::sort_Candidates_By_Rating(vector<Candidate>& candidates) {
	sort(candidates.begin(), candidates.end(), compare_Candidates);
}