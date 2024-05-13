#include<iostream>
#include<string>
#include"Admin.h"
#include"Employee.h"
#include"Candidate.h"

using namespace std;

Admin admin;

//Supporting functions
int print_menu(string page);  
int print_menu();
void Prelimenary_data();
vector<string> set_requirements();




int main()
{	//Supporting variables
	string page, str_holder;
	int number, exp;
	vector<string>str_vec;
	vector<Candidate> candidates_vec;
	vector<Employee> employee_vec;
	Candidate cand_obj;
	Employee empl_obj;

	

	
	/*for (int i = 0; i < 3; i++) {
		admin.recruitment(requirements);
		cout<< "Rating of "<< admin.get_Candidates()[i].get_name()<< " is: " << admin.get_Candidates()[i].get_rating() << endl;
	}*/

	
	//admin.Write_canditate_to_file();
	//admin.Read_canditate_from_file();
		
	int choice;
	do
	{
		choice = print_menu();
		
		switch (choice){
		case 1:
			cout << "How many candidates you want to add: "; cin >> number;
			if (number < 0 || number == 1) {
				admin.create_candidate();
				cout << "Candidate successfully added!" << endl;
			}

			if (number > 1) {
				for (int i = 0; i < number; i++) {
					admin.create_candidate();
				}
				cout << "Candidates successfully added!" << endl;
			}
			break;

	
	//admin.display_candidates();
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
			cout << "/nInfo About Candidates:/n";
			admin.display_candidates();
			cout << "/n";
			break;

		case 4:
			cout << "/nInfo About Accepted Candidates:/n";
			if (admin.get_List_of_prommising_Candidates().empty())
			{
				cout << "No candidates accepted";
			}
			else {
				admin.Read_canditate_from_file();
			}
			break;
		
		case 5:
			cout << "/nInfo About Employees:/n";
			admin.display_employees();
			break;
		case 6:
			cout << "/nEnter email of candidate you want to find: "; cin >> str_holder;
			candidates_vec = admin.search_candidate_by_email(str_holder);
			admin.show_info(candidates_vec[0]);
			break;
		case 7:
			str_vec = set_requirements();
			admin.recruitment(str_vec);
			cout << "Enter experience and minimal rating required: "; cin >> exp >> number;
			admin.Sort_candidates_by_requirements(exp, number);
			admin.Write_canditate_to_file();
			cout << "Candidates successfully selected!/n";
			break;
		case 8:
			cout << "/nInput ID of an Employee: "; cin >> number;
			employee_vec = admin.search_employee_by_id(number);
			if (admin.is_contract_valid(employee_vec[0]) == 1) {
				cout << "Contract still valid." << endl;
			}
			else {
				cout << "Contract has expired!!!" << endl;
				cout << "Do you want to prolong contract of employee with ID - " << number << " ? (Yes - 1/ No - 0)"; cin >> exp;
				if (exp == 1) {
					cout << "Input new contract duration: "; cin >> number;
					admin.Prolong_contract(employee_vec[0], number);
					cout << "Contrat prolonged." << endl;
				}
				//else {}

			}
			break;

		case 9:
			cout << "Input ID of employee you want to find: "; cin >> number;
			employee_vec =  admin.search_employee_by_id(number);
			admin.show_info(employee_vec[0]);
			break;
		case 10:
			cout << "Good Bye!!!" << endl;
			break;

		case 11:

			break;

		default:
			cout << "Wrong comand!!!" << endl;
			break;
		}


	} while (choice != 10);


	return 0;
}


int print_menu(string page) {
	int choice;
	cout << "---------------------------------" << endl;
	cout << "MENU" << endl;
//	if (page != "MENU")
	cout << "0 - " << "Back to main menu." << endl;
	cout << "1 - " << "Add Candidate." << endl;
	cout << "2 - " << "Add Employee." << endl;
	cout << "3 - " << "Show all Candidates." << endl;
	cout << "4 - " << "Show Accepted Candidates." << endl;
	cout << "5 - " << "Show all Employees." << endl;
	cout << "6 - " << "Show information about Candidate." << endl;
	cout << "7 - " << "Select promissing candidates." << endl;
	cout << "8 - " << "Check validation of cantract of an employee." << endl;
	cout << "9 - " << "Search for an employee." << endl;
	cout << "10 - " << "Terminate programm." << endl;
	cout << "11 - " << "Use prepared data." << endl;
	cout << "---------------------------------" << endl;

	cout << "Enter number of service: "; cin >> choice;
	return choice;
}

int print_menu() {
	int choice;
	cout << "---------------------------------" << endl;
	cout << "MENU" << endl;
	cout << "1 - " << "Add Candidate." << endl;
	cout << "2 - " << "Add Employee." << endl;
	cout << "3 - " << "Show all Candidates." << endl;
	cout << "4 - " << "Show Accepted Candidates." << endl;
	cout << "5 - " << "Show all Employees." << endl;
	cout << "6 - " << "Show information about Candidate." << endl;
	cout << "7 - " << "Select promissing candidates." << endl;
	cout << "8 - " << "Check validation of cantract of an employee." << endl;
	cout << "9 - " << "Prolong cantract duration of an employee." << endl;
	cout << "10 - " << "Search for an employee." << endl;
	cout << "12 - " << "Seaech for a candidate." << endl;
	cout << "13 - " << "Get data from a file." << endl;
	cout << "14 - " << "Terminate programm." << endl;
	cout << "---------------------------------" << endl;

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

	vector<string> skills_emp1 = { "CSS", "HTML", "Git" };
	vector<string> skills_emp2 = { "C++", "SQL", "Fortran" };
	vector<string> skills_emp3 = { "Java", "Python", "Git" };
	vector<string> skills_emp4 = { "CSS", "HTML", "SQL", "Django" };
	vector<string> skills_emp5 = { "C++", "SQL","Git", "Docker" };
	vector<string> skills_emp6 = { "Java", "Python", "Git" };


	vector<string> requirements1 = { "C++", "SQL", "Django", "Java", "JavaScript" };
	vector<string> requirements2 = { "C++", "Fortran", "Git", "Docker", };
	vector<string> requirements3 = { "C++", "HTML", "Python", "Java", "CSS" };


	admin.create_candidate("Daniil", 20, "xxx", "+998335959043", "danP@gmail.com", 1, skills_emp1);
	admin.create_candidate("Max", 25, "xxx", "+998445959053", "shoxR@gmail.com", 3, skills_emp2);
	admin.create_candidate("Ian", 30, "xxx", "+998995959043", "KeyL@gmail.com", 7, skills_emp3);

	admin.create_candidate("Van", 34, "xxx", "+998335959043", "Van@gmail.com", 8, skills_emp4);
	admin.create_candidate("Luv", 21, "xxx", "+998445959053", "Luv@gmail.com", 2, skills_emp5);
	admin.create_candidate("Ann", 22, "xxx", "+998995959043", "Ann@gmail.com", 4, skills_emp6);
}