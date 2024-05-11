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

	vector<string> Skills = { "C++", "Html", "Python" };
	admin.recruitment(Skills);
	return 0;
}