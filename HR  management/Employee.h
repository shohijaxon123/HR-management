#pragma once
#include <iostream>
#include <string>
#include <regex>
#include"Person.h"

using namespace std;

const double TAX_RATE = 0.12;


class Employee:public Person
{
private:
    int Year_of_enrolling;
	string Position;
	double Salary;
    int Contract_duration;
public:
	// Default constructor
	Employee() : Person(){
		Name = "Unknown";
		Age = 0;
		Address = "";
		Email = "";
		Phone_number = "";
        Contract_duration = 0;
		Position = "";
		Salary = 0.0;
	}
	// Parametrized constructor without email and phone number
	Employee(const string& name, unsigned int age, string address, int year_of_enrolling, string position, int duration, double salary) : Person(name, age, address){
		Name = name;
		Age = age;
		Address = address;
		Email = "";
		Phone_number = "";
		Position = position;
        Year_of_enrolling = year_of_enrolling;
        Contract_duration = duration;
		Salary = Calculate_Tax(salary, TAX_RATE); //salary_total
	}

	Employee(const string& name, unsigned int age, string address, string email, string number, int year_of_enrolling, string position, int duration, double salary) : Person(name, age, address, email, number){
		Name = name;
		Age = age;
		Address = address;
		Email = email;
		Phone_number = number;
		Position = position;
        Year_of_enrolling = year_of_enrolling;
        Contract_duration = duration;
		Salary = Calculate_Tax(salary, TAX_RATE); //salary_total
	}

	// Salary with the Tax
	double Calculate_Tax(double salary, double tax_rate){
		double Total_Salary = salary - salary*tax_rate;
		return Total_Salary; // need to round up to three digits 
	}

    void display_info_of_Employee(){
        Person::display_info_of_person();
        cout<<"Enrolling Year: "<<Year_of_enrolling<<" years"<<endl;
        cout<<"Position: "<< Position <<endl;
        cout<<"Salary: "<< Salary <<endl;
        cout<<"Contract duration: "<< Contract_duration<<" months."<<endl;
    }
};

//Getters required!!!

// Setters required!!!