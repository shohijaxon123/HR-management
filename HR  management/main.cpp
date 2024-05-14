#include<iostream>
#include<string>
#include"Admin.h"
#include"Employee.h"
#include"Candidate.h"
#include"Person.h"

using namespace std;

Admin admin;

//Supporting functions 
int print_menu();
void Prelimenary_data();
vector<string> set_requirements();


int main()
{	//Supporting variables
	string page, str_holder;
	int id, number, choice_1;
	double exp;
	vector<string>str_vec;
	vector<Candidate> candidates_vec;
	vector<Employee> employee_vec;
	Candidate cand_obj;
	Employee empl_obj;


		
	int choice;
	
	do
	{
		choice = print_menu();
		
		switch (choice){
		case 1:
			cout << "How many candidates you want to add: "; cin >> number;
			if (number < 0 || number == 1) {
				cand_obj = admin.create_candidate();
				cout << "Do you want to remove Candidate for some reasons? (Yes - 1 / No - 0) "; cin >> choice_1;
				if (choice_1 == 1) {
					admin.delete_candidate_by_obj(cand_obj);
					cout << "Candidate deleted" << endl;
				}
				else {
					cout << "Candidate successfully added!" << endl;
				}
				
			}

			if (number > 1) {
				for (int i = 0; i < number; i++) {
					cand_obj = admin.create_candidate();
					cout << "\nDo you want to remove Candidate for some reasons? (Yes - 1 / No - 0) "; cin >> choice_1;
					if (choice_1 == 1) {
						admin.delete_candidate_by_obj(cand_obj);
						cout << "\nCandidate deleted\n" << endl;
					}
					else {
						cout << "\nCandidate successfully added!\n" << endl;
					}
				}
			}

			break;
		case 2:
			cout << "How many employees you want to add: "; cin >> number;
			if (number < 0 || number==1) {
				admin.create_employee();
				cout << "Employee successfully added!" << endl;
			}

			if (number > 1) {
				for (int i = 0; i < number; i++) {
					admin.create_employee();
				}
				cout << "Employees successfully added!" << endl;
			}
			break;
		case 3:
			cout << "\nInfo About Candidates:\n";
			admin.display_candidates();
			cout << "\n";
			break;

		case 4:
			cout << "\nInfo About Accepted Candidates:\n";
			if (admin.get_List_of_prommising_Candidates().empty())
			{
				cout << "No candidates accepted";
			}
			else {
				admin.Read_canditate_from_file();
			}
			break;
		
		case 5:
			cout << "\nInfo About Employees:\n";
			admin.display_employees();
			break;
		case 6:
			cout << "\nEnter ID of candidate you want to find: "; cin >> id;
			candidates_vec = admin.search_candidate_by_id(id);
			if (candidates_vec.empty()) {
				cout << "There is no candidate with an ID - " << id << endl;
			}
			else
				admin.show_info(candidates_vec[0]);
			break;
		case 7:
			if (admin.is_List_of_candidates_empty()==1) {
				str_vec = set_requirements();
				admin.recruitment(str_vec);
				cout << "Enter experience and minimal rating required: "; cin >> exp >> number;
				admin.Sort_candidates_by_requirements(exp, number);
				admin.Write_canditate_to_file();
				cout << "Candidates successfully selected!\n";
			}
			else {
				cout << "There is no registrated candidates!!!" << endl;
			}
			
			break;
		case 8:
			cout << "\nInput ID of an Employee: "; cin >> number;
			employee_vec = admin.search_employee_by_id(number);
			if (employee_vec.empty()) {
				cout << "There is no Employee with an ID - " << number << endl;
			}
			else {
				if (admin.is_contract_valid(employee_vec[0]) == 1) {
					cout << "Contract still valid." << endl;
				}
				else {
					cout << "Contract has expired!!!" << endl;
					cout << "Do you want to prolong contract of employee with ID - " << number << " ? (Yes - 1/ No - 0)"; cin >> choice_1;
					if (choice_1 == 1) {
						cout << "Input new contract duration: "; cin >> number;
						admin.Prolong_contract(employee_vec[0], number);
						cout << "Contrat prolonged." << endl;
					}
					else if(choice_1 == 0) {
						cout << "Contrant will not be prolonged!" << endl;
					}
					else{
						cout << "Wrong command!!!" << endl;
					}

				}
			}
			break;

		case 9:
			cout << "Input ID of employee you want to find: "; cin >> number;
			employee_vec =  admin.search_employee_by_id(number);
			if (!employee_vec.empty()) {
				admin.show_info(employee_vec[0]);
			}
			else {
				cout << "There is no Employee with an ID - " << number << endl;
			}
			
			break;
		case 10:
			cout << "\nInput ID of employee you want to delete: "; cin >> number;
			admin.delete_employee(number);
			break;
		case 11:
			cout << "\nInput ID of candidate you want to delete: "; cin >> id;
			admin.delete_candidate(id);
			break;
		case 12:
			cout << "Good Bye!!!" << endl;
			break;
		case 13:
			Prelimenary_data();
			break;
		default:
			cout << "Wrong comand!!!" << endl;
			break;
		}


	} while (choice != 12);


	return 0;
}

int print_menu() {
	int choice;
	cout << "\n---------------------------------" << endl;
	cout << "MENU" << endl;
	cout << "1 - " << "Add Candidate." << endl;
	cout << "2 - " << "Add Employee." << endl;
	cout << "3 - " << "Show all Candidates." << endl;
	cout << "4 - " << "Show Accepted Candidates." << endl;
	cout << "5 - " << "Show all Employees." << endl;
	cout << "6 - " << "Show information about Candidate." << endl;
	cout << "7 - " << "Select promissing candidates." << endl;
	cout << "8 - " << "Check validation of cantract of an employee." << endl;
	cout << "9 - " << "Search for an employee." << endl;
	cout << "10 - " << "Delete Employee." << endl;
	cout << "11 - " << "Delete Candidate." << endl;
	cout << "12 - " << "Terminate programm." << endl;
	cout << "13 - " << "Use prepared data." << endl;
	cout << "---------------------------------\n" << endl;

	cout << "Enter number of service: "; cin >> choice;
	return choice;
}



vector<string> set_requirements() {
	vector<string> requirements;
	string skill;
	cout << "Enter Requirements and press 'stop' to stop: " << endl;
	while (skill != "stop") {
		cout << "Enter: "; cin >> skill;
		requirements.push_back(skill);
	}
	requirements.shrink_to_fit();
	return requirements;
}


void Prelimenary_data() {
	//Prepared requirements
	vector<string> requirements3 = { "C++", "HTML", "Python", "Java", "CSS", "Git"}; //6 skills

	//Prepared skills for candidates
	vector<string> skills_emp1 = { "CSS", "HTML" }; // 2 out of 6
	vector<string> skills_emp2 = { "C++", "Java", "Git" };// 3 out of 6
	vector<string> skills_emp3 = { "Java", "Python", "Git" }; // 3 out of 6
	vector<string> skills_emp4 = { "CSS", "HTML", "SQL", "Python" };//3 out of 6
	vector<string> skills_emp5 = { "C++", "SQL","Git", "Docker" };// 2 out of 6
	vector<string> skills_emp6 = { "Fortran", "Rust", "Git" };//1 out of s6

	//Prepared candidates
	Candidate obj1 = admin.create_candidate("Key", 20, "+998335959043", "danP@gmail.com", 1, skills_emp1);
	Candidate obj2 = admin.create_candidate("Max", 25, "+998445959053", "shoxR@gmail.com", 3, skills_emp2);
	Candidate obj3 = admin.create_candidate("Ian", 30, "+998995959043", "KeyL@gmail.com", 7, skills_emp3);
	Candidate obj4 = admin.create_candidate("Van", 34, "+998335959043", "Van@gmail.com", 8, skills_emp4);
	Candidate obj5 = admin.create_candidate("Luv", 21, "+998445959053", "Luv@gmail.com", 2, skills_emp5);
	Candidate obj6 = admin.create_candidate("Ann", 22, "+998995959043", "Ann@gmail.com", 4, skills_emp6);
	
	cout << "\n" << endl;
	
	admin.display_candidates();
	
	cout << "\n" << endl;
	
	//Set rating to candidates
	admin.recruitment(requirements3);
	
	//Sort candidates according to required experience and skills and accept candidates who satisfied requiremets
	admin.Sort_candidates_by_requirements(3, 5);
	
	//Write accepted candidates to a file
	admin.Write_canditate_to_file();
	cout << "\n" << endl;
	//Take data about accepted candidates from a file
	admin.Read_canditate_from_file();
	cout << "\n" << endl;
	
	admin.Clear_file();

}	
