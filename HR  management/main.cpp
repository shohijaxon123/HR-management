#include<iostream>
#include<string>
#include"Admin.h"
#include"Employee.h"
#include"Candidate.h"

using namespace std;


int main()
{
	Admin admin;
	Candidate candidate1 = admin.create_candidate();
	vector<string> Skills = { "C++", "Html", "Python", "Java"};
	candidate1.calculate_rating(Skills);
	admin.show_info(candidate1);


	admin.Write_canditate_to_file(candidate1);
	admin.Read_canditate_from_file();
	//admin.display_candidates();

	//vector<string> skills_emp = { "C++", "Html" };
	//admin.recruitment(Skills);
	//cout<<admin.get_Candidates()[0].get_rating() << endl;
	//Candidate obj("dan", 19, "xxx", "xxx", "xxx", 2, skills_emp);

	//obj.calculate_rating(Skills);
	

	return 0;
}