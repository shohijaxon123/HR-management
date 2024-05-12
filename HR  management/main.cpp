#include<iostream>
#include<string>
#include"Admin.h"
#include"Employee.h"
#include"Candidate.h"

using namespace std;


int main()
{
	vector<string> skills_emp1 = { "CSS", "HTML" };
	vector<string> skills_emp2= { "C++", "SQL" };
	vector<string> skills_emp3= { "Java", "Python", "Git" };
	vector<string> requirements = { "C++", "HTML", "Python", "Java", "CSS"};

	Admin admin;
	admin.create_candidate("Dan", 20, "xxx", "xxx", "XXX", 1, skills_emp1);
	admin.create_candidate("Max", 20, "xxx", "xxx", "XXX", 2, skills_emp2);
	admin.create_candidate("Ian", 20, "xxx", "xxx", "XXX", 3, skills_emp3);
	
	for (int i = 0; i < 3; i++) {
		admin.recruitment(requirements);
		cout<< "Rating of "<< admin.get_Candidates()[i].get_name()<< " is: " << admin.get_Candidates()[i].get_rating() << endl;
	}



	//Candidate candidate1 = admin.create_candidate();
	//admin.show_info(candidate1);

	//admin.display_candidates();

	
	//admin.recruitment(Skills);
	//cout<<admin.get_Candidates()[0].get_rating() << endl;
	//Candidate obj("dan", 19, "xxx", "xxx", "xxx", 2, skills_emp);


	return 0;
}