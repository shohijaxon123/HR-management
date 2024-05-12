#include<iostream>
#include<string>
#include"Admin.h"
#include"Employee.h"
#include"Candidate.h"

using namespace std;


Admin admin;

int main()
{
	vector<string> skills_emp1 = { "CSS", "HTML" };
	vector<string> skills_emp2= { "C++", "SQL" };
	vector<string> skills_emp3= { "Java", "Python", "Git" };
	vector<string> requirements = { "C++", "HTML", "Python", "Java", "CSS"};

	Candidate candidate1 = admin.create_candidate();
	vector<string> Skills = { "C++", "Html", "Python", "Java"};
	candidate1.calculate_rating(Skills);
	admin.show_info(candidate1);

	admin.create_candidate("Dan", 20, "xxx", "xxx", "XXX", 1, skills_emp1);
	admin.create_candidate("Max", 20, "xxx", "xxx", "XXX", 2, skills_emp2);
	admin.create_candidate("Ian", 20, "xxx", "xxx", "XXX", 3, skills_emp3);
	
	for (int i = 0; i < 3; i++) {
		admin.recruitment(requirements);
		cout<< "Rating of "<< admin.get_Candidates()[i].get_name()<< " is: " << admin.get_Candidates()[i].get_rating() << endl;
	}

	admin.Write_canditate_to_file(candidate1);
	admin.Read_canditate_from_file();


	return 0;
}