#include <iostream>
#include <string>
#include"Admin.h"
#include"Employee.h"
#include"Candidate.h"

using namespace std;


int main()
{	Candidate obj1("Daniil", 19, "Tashkent, Uzbekistan", "daniilpulatov@gmail.com", "+998335959043", 2);
	obj1.set_skills();
	obj1.display_info_of_Candidate();
	system("pause");
	return 0;
}