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
vector<string> set_requirements();




int main()
{
	string page;
	int number;
	vector<string> skills_emp1 = { "CSS", "HTML" };
	vector<string> skills_emp2= { "C++", "SQL" };
	vector<string> skills_emp3= { "Java", "Python", "Git" };
	vector<string> requirements = { "C++", "HTML", "Python", "Java", "CSS"};

	Admin admin;
	/*Candidate candidate1 = admin.create_candidate();
	vector<string> Skills = { "C++", "Html", "Python", "Java"};
	candidate1.calculate_rating(Skills);
	admin.show_info(candidate1);*/

	admin.create_candidate("Dan", 20, "xxx", "xxx", "XXX", 1, skills_emp1);
	admin.create_candidate("Max", 20, "xxx", "xxx", "XXX", 2, skills_emp2);
	admin.create_candidate("Ian", 20, "xxx", "xxx", "XXX", 3, skills_emp3);
	
	for (int i = 0; i < 3; i++) {
		admin.recruitment(requirements);
		cout<< "Rating of "<< admin.get_Candidates()[i].get_name()<< " is: " << admin.get_Candidates()[i].get_rating() << endl;
	}

	*/
	admin.Write_canditate_to_file();
	admin.Read_canditate_from_file();
		
	int choice = print_menu();
	do
	{
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
			admin.get_Candidates();
		}


	} while (choice != 14);


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
	cout << "9 - " << "Prolong cantract duration of an employee." << endl;
	cout << "10 - " << "Search for an employee." << endl;
	cout << "12 - " << "Seaech for a candidate." << endl;
	cout << "13 - " << "Get data from a file." << endl;
	cout << "14 - " << "Terminate programm." << endl;
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