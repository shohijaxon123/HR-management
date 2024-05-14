#pragma once

#include <fstream>
#include"Employee.h"
#include"Candidate.h"
#include"Person.h"
using namespace std;

class Admin {
private:
	vector<Candidate>List_of_candidates;
	vector<Employee>List_of_employees;
	vector<Candidate>List_of_prommising_Candidates;

	void compare_Candidates(Candidate& first, Candidate& second);
	void sort_Candidates_By_Rating();
	int get_current_year();
public:

	~Admin() {}
	//Create Employee (enter all the data from a console)
	Employee create_employee();
	//create Candidate (enter all the data from a console)
	Candidate create_candidate();
	//Create Candidate and indicate skills beforehand
	Candidate create_candidate(vector<string>& skills);
	//Create candidate with all parametres
	Candidate create_candidate(const string& Name, unsigned int Age, string Phone_number, string Email, int Experience, vector<string>& skills);
	//Delete candidate
	void delete_candidate(int& id);
	//Delete employee
	void delete_employee(int& ID);
	//delete candidate obj
	void delete_candidate_by_obj(Candidate obj);

	vector<Candidate> search_candidate_by_id(int& id);
	vector<Employee> search_employee_by_id(int& id);
	vector<Candidate> get_Candidates();
	void display_employees();
	void display_candidates();
	void show_info(Employee obj);
	void show_info(Candidate obj);

	//Set value of the Candidates rating according to the skills required
	void recruitment(vector<string>& skills_required);

	//This two functions delete inappropriate candidates
	void Sort_candidates_by_requirements(double experience_required, int manimal_rating);

	void Write_canditate_to_file();
	void Read_canditate_from_file();
	void Clear_file();


	bool is_contract_valid(Employee obj);
	void Prolong_contract(Employee obj, int year);


	vector<Candidate>get_List_of_prommising_Candidates() {
		return List_of_prommising_Candidates;
	}


	bool is_List_of_candidates_empty(){
		if (List_of_candidates.empty())
			return false;
		return true;
	}
};



//Create candidate with all parametres
Candidate Admin::create_candidate(const string& Name, unsigned int Age, string Phone_number, string Email, int Experience, vector<string>& skills) {
	Candidate cand(Name, Age, Email, Phone_number, Experience, skills);
	List_of_candidates.push_back(cand);
	List_of_candidates.shrink_to_fit();
	return cand;
}


//Create Employee (enter all the data from a console)
Employee Admin::create_employee() {
	string Name, Email, Phone_number;
	unsigned int Age;
	int Year_of_enrolling, Contract_duration;
	string Position;
	double Salary;

	cout << "\nInput data of an employee: " << endl;
	cout << "Input Name: "; cin >> Name;
	cout << "Input Age: "; cin >> Age;
	cout << "Input Email: "; cin >> Email;
	cout << "Input Phone_number: "; cin >> Phone_number;
	cout << "Input Year of enroolment: "; cin >> Year_of_enrolling;
	cout << "Contract_duration: "; cin >> Contract_duration;
	cout << "Input Position: "; cin >> Position;
	cout << "Input Salary: "; cin >> Salary;

	Employee emp(Name, Age, Email, Phone_number, Year_of_enrolling, Position, Contract_duration, Salary);
	List_of_employees.push_back(emp);
	List_of_employees.shrink_to_fit();
	return emp;
}

//create Candidate (enter all the data from a console)
Candidate Admin::create_candidate() {
	string Name, Email, Phone_number;
	unsigned int Age;
	vector<string> Skills;
	double Experience;
	cout << "\nInput data of a candidate: " << endl;
	cout << "Input Name: "; cin >> Name;
	cout << "Input Age: "; cin >> Age;
	cout << "Input Email: "; cin >> Email;
	cout << "Input Phone_number: "; cin >> Phone_number;
	cout << "Input Experience in years: "; cin >> Experience;

	Candidate cand(Name, Age, Email, Phone_number, Experience);
	cand.set_skills();
	List_of_candidates.push_back(cand);
	List_of_candidates.shrink_to_fit();
	return cand;
}

//delete candidtes
void Admin::delete_candidate(int& id) {
	vector<Candidate> cand_to_delete = this->search_candidate_by_id(id);
	if (cand_to_delete.empty()) {
		cout << "No such candidate!\n" << endl;
	}
	else {
		List_of_candidates.erase(cand_to_delete.begin());
		List_of_candidates.shrink_to_fit();
	}
}


//delete candidtes obj
void Admin::delete_candidate_by_obj(Candidate obj) {
	for (int i = 0; i < List_of_candidates.size(); i++) {
		if (obj.get_ID() == List_of_candidates[i].get_ID()) {
			List_of_candidates.erase(List_of_candidates.begin() + i);
		}
	}	
		List_of_candidates.shrink_to_fit();
}


//delete employee
void Admin::delete_employee(int& ID) {
	vector<Employee> empl_to_delete = this->search_employee_by_id(ID);
	if (empl_to_delete.empty()) {
		cout << "No such employee!\n" << endl;
	}
	else {
		List_of_employees.erase(empl_to_delete.begin());
		List_of_employees.shrink_to_fit();
	}
}



//Create Candidate and indicate skills beforehand
Candidate Admin::create_candidate(vector<string>& skills) {
	string Name, Address, Email, Phone_number;
	unsigned int Age;
	vector<string> Skills;
	double Experience;
	cout << "\nInput data of a candidate: " << endl;
	cout << "Input Name: "; cin >> Name;
	cout << "Input Age: "; cin >> Age;
	cout << "Input Email: "; cin >> Email;
	cout << "Input Phone_number: "; cin >> Phone_number;
	cout << "Input Experience in years: "; cin >> Experience;

	Candidate cand(Name, Age, Email, Phone_number, Experience, skills);
	List_of_candidates.push_back(cand);
	List_of_candidates.shrink_to_fit();
	return cand;
}

vector<Employee> Admin::search_employee_by_id(int& id) {
	vector<Employee> Result;
	for (int i = 0; i < List_of_employees.size(); i++) {
		if (List_of_employees[i] .get_id() == id) {
			Result.push_back(List_of_employees[i]);
		}
	}
	Result.shrink_to_fit();
	return Result;

}

vector<Candidate> Admin::search_candidate_by_id(int& id) {
	vector<Candidate> Result;
	for (int i = 0; i < List_of_candidates.size(); i++) {
		if (List_of_candidates[i].get_ID() == id) {
			Result.push_back(List_of_candidates[i]);
		}
	}
	Result.shrink_to_fit();
	return Result;
}

vector<Candidate> Admin::get_Candidates() {
	return List_of_candidates;
}

void Admin::display_candidates() {
	if (List_of_candidates.empty()) {
		cout << "No registrated Candidates!" << endl;
	}
	else {
		for (int i = 0; i < List_of_candidates.size(); i++) {
			cout <<"ID: "<< List_of_candidates[i].get_ID() << " - " << List_of_candidates[i].get_name() << "; Age: " << List_of_candidates[i].get_age() << "; Experience: "<< List_of_candidates[i].get_experience()<< " years ";
			if (List_of_candidates[i].get_rating() != 0) {
				cout << List_of_candidates[i].get_rating() << endl;
			}
			else {
				cout << endl;
			}
		}
	}
}

void Admin::display_employees() {
	if (List_of_employees.empty()) {
		cout << "No registrated Employees!" << endl;
	}
	else {
		for (int i = 0; i < List_of_employees.size(); i++) {
			cout << "ID: " << List_of_employees[i].get_id() << " - " << List_of_employees[i].get_name() << " - Age: " << List_of_employees[i].get_age() << " years; " << List_of_employees[i].get_phoneNumber() << "; " << List_of_employees[i].get_email() << "/nPosition: " << List_of_employees[i].get_Position() << endl;;
		}
	}
}

void Admin::show_info(Employee obj) {
	obj.display_info();
}

void Admin::show_info(Candidate obj) {
	obj.display_info();
}

//Assess candidates by their skills
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

//Add suitable candidates into a new vector, and sort them according to their rating
void Admin::Sort_candidates_by_requirements(double experience_required, int minimal_rating) {
	for (int i = 0; i < List_of_candidates.size(); i++) {
		if ((List_of_candidates[i].get_experience() >= experience_required && List_of_candidates[i].get_rating() >= minimal_rating)) {
			List_of_prommising_Candidates.push_back(List_of_candidates[i]);
			List_of_candidates[i].set_status(true);
			List_of_candidates.erase(List_of_candidates.begin() + i);
		}
	}
	sort_Candidates_By_Rating();
}

//Loop to traverse vector List of promissing candidates
//Use function search_candidate_by_name


void Admin::Write_canditate_to_file()
{
	Candidate candidate;
	ofstream outfile("Candidates.dat", ios::app);
	if (!outfile.is_open())
	{
		cout << "Error opening file for writing" << endl;
	}
	else
	{
		for (auto& candidate: List_of_prommising_Candidates)
		{
			outfile<<candidate.get_name() << "-" << candidate.get_rating() << endl;
			cout << "Candidate " << candidate.get_name() << " added to the file" << endl;
		}
		
	}
	outfile.close();
}

void Admin::Read_canditate_from_file()
{
	ifstream infile("Candidates.dat", ios::app);
	string name;
	int rating;
	if (!infile.is_open())
	{
		cout << "Error opening file for reading" << endl;
	}
	else
	{
		while (getline(infile, name, '-'))
		{
			infile >> rating;
			infile.ignore();
			cout << "Name: " << name << "\t";
			cout << "Rating: " << rating << endl;
		}
	}
	infile.close();
}

void Admin::Clear_file()
{
	ofstream file("Candidates.dat");
	file.close();
	cout << "File cleared" << endl;

}

// Custom comparison function for sorting candidates by rating in descending order
void Admin::compare_Candidates(Candidate& first, Candidate& second){
		Candidate temp = first;
		first = second;
		second = temp;
}

// Function to sort the vector of candidates by rating (bubble sort)
void Admin::sort_Candidates_By_Rating() {
	int n = List_of_prommising_Candidates.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (List_of_prommising_Candidates[j].get_rating() < List_of_prommising_Candidates[j + 1].get_rating()) {
				compare_Candidates(List_of_prommising_Candidates[j], List_of_prommising_Candidates[j + 1]);
			}
		}
	}
}

bool Admin::is_contract_valid(Employee obj) {
	int current_year = get_current_year();
	if (obj.get_Contract_duration() < current_year - obj.get_year_of_enrolling()) {
		return false;
	}

	return true;
}

void Admin::Prolong_contract(Employee obj, int year) {
	obj.set_Contract_duration(year);
}

int Admin::get_current_year() {
	auto now = chrono::system_clock::now();

	// Get the current year from the time point
	auto currentTime = chrono::system_clock::to_time_t(now);

	tm currentTm;
	localtime_s(&currentTm, &currentTime);

	int currentYear = currentTm.tm_year + 1900; // tm_year represents years since 1900

	return currentYear;
}