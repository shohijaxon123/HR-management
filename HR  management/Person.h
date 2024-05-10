#pragma once
#include <iostream>
#include <string>
#include <regex>
#include<vector>

using namespace std;


const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); 
  

class Person{
protected:
	string Name;
	unsigned int Age;
	string Address;
	string Email;
	string Phone_number;
public:
	Person(){
		Name = "Unknown";
		Age = 0;
		Address = "";
		Email = "";
		Phone_number = "";
	}

	Person(const string& name, unsigned int age, string address, string email, string number){
		Name = name;
		Age = age;
		Address = address;
		Email = email;
		Phone_number = number;
	}

	Person(const string& name, unsigned int age, string address){
		Name = name;
		Age = age;
		Address = address;
		Email = "";
		Phone_number = "";
	}
	void set_name(const string& name);
	void set_age(unsigned int age);
	void set_address(string address);
	void set_email(string email);
	void set_phoneNumber(string num);

	string get_name(string const& name);
	unsigned int get_age(unsigned int age);
	string get_address(string address);
	string get_email(string email);
	string get_phoneNumber(string num);

	void display_info_of_person();
};

// Person class member functions

//Setters
void Person::set_name(const string& name){
	//regex needed
	Name = name;
}
void Person::set_age(unsigned int age){
	if (age > 0 && age < 120)
		Age = age;
	else
		Age = 0;
}
void Person::set_address(string address){
	Address = address;
}
void Person::set_email(string email){
	if (regex_match(email, pattern))
		Email = email;
	else{
		Email = "";
		//Exception handling
	}
}
void Person::set_phoneNumber(string num){
	//regex needed
	Phone_number = num;
}

//Getters

string Person::get_name(string const& name){
	return Name;
}
unsigned int Person::get_age(unsigned int age){
	return Age;
}
string Person::get_address(string address){
	return Address;
}
string Person::get_email(string email){
	return Email;
}
string Person::get_phoneNumber(string num){
	return Phone_number;
}

//Display function
void Person::display_info_of_person(){
	cout<< "---------------------------"<< endl;
	cout<< "Name: " << Name << endl;
	cout<< "Age: " << Age << endl;
	cout<< "Address: " << Address << endl;
	cout<< "Phone Number: " << Phone_number << endl;
	cout<< "Email address: " << Email << endl;
}





class AddEmployee
{



};