#include <iostream>
#include <string>
using namespace std;


int main()
{
	int  choice;
	do
	{
		cout << "1. To add new employee" << endl;
		cout << "0. To exit" << endl;
		cout << "Input your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "hello  world"  <<endl;
			break;

		default:
			break;
		}



	} while (choice !=0);
	






	system("pause");
	return 0;
}