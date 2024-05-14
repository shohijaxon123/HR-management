#pragma once
#include"Person.h"

using namespace std;

const double TAX_RATE = 0.12;


class Employee:public Person
{
private:
    static int ID;
    int Year_of_enrolling;
	string Position;
	double Salary;
    int Contract_duration;
public:
	// Default constructor
	Employee() : Person(){
        ID++;
		Name = "Unknown";
		Age = 0;
		Email = "";
		Phone_number = "";
        Contract_duration = 0;
        Year_of_enrolling = 0;
		Position = "";
		Salary = 0.0;
	}

	Employee(const string& name, unsigned int age, string email, string number, int year_of_enrolling, string position, int duration, double salary) : Person(name, age, email, number){
        ID++;
        this->set_name(name);
        this->set_age(age);
        this->set_email(email);
        this->set_phoneNumber(number);
		Position = position;
        Year_of_enrolling = year_of_enrolling;
        Contract_duration = duration;
		Salary = Calculate_Tax(salary, TAX_RATE); //salary_total
	}

    ~Employee() {};

	// Salary with the Tax
	double Calculate_Tax(double salary, double tax_rate){
		double Total_Salary = salary - salary*tax_rate;
		return Total_Salary; // need to round up to three digits 
	}

    void display_info(){
        Person::display_info_of_person();
        cout << "ID: " << ID << endl;
        cout<<"Enrolling Year: "<<Year_of_enrolling<<" years"<<endl;
        cout<<"Position: "<< Position <<endl;
        cout<<"Salary: "<< Salary <<endl;
        cout<<"Contract duration: "<< Contract_duration<<" months."<<endl;
    }

    //Setters
    void set_Position(string pos);
    void set_Salary(double salary);
    void set_new_Contract_duration(int new_date);
    void set_Contract_duration(int year);
    // Getters
    int get_Contract_duration();
    int get_id();
    string get_Position();
    double get_Salary();
    int get_year_of_enrolling();
};

int Employee::ID = 1;

//Setters

void Employee::set_Position(string pos){
    Position = pos;
}
void Employee::set_Salary(double salary){
    if (salary > 0)
        Salary = salary;
    else
        cout << "Invalid input of salary!!!" << endl;
}
void Employee::set_new_Contract_duration(int new_date) {
    if (new_date > 0 && new_date < 50) {
        Contract_duration = new_date;
    }
    else {
        cout << "Invalid input of contract duartion!!!"<<endl;
    }
}
void Employee::set_Contract_duration(int new_date) {
    if (new_date > 0 && new_date < 50) {
        Contract_duration = new_date;
    }
    else {
        cout << "Invalid input of contract duartion!!!" << endl;
    }
}


// Getters
int Employee::get_Contract_duration(){
    return Contract_duration;
}
int Employee::get_id() {
    return ID;
}
string Employee::get_Position(){
    return Position;
}
double Employee::get_Salary(){
    return Salary;
}
int Employee::get_year_of_enrolling(){
    return Year_of_enrolling;
}