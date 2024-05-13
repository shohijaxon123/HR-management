#pragma once
#include <iostream>
#include <string>
#include <regex>
#include<vector>
#include <algorithm>

using namespace std;


const regex email_pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); 
const regex Name_pattern("[a-zA-Z]+");
const regex  Phone_number_pattern("\\+\\d{12}");
  

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

	string get_name();
	unsigned int get_age();
	string get_address();
	string get_email();
	string get_phoneNumber();

	void display_info_of_person();
};

// Person class member functions

//Setters
void Person::set_name(const string& name) {
	if (regex_match(name, Name_pattern)) {
		Name = name;
	}
	else {
		Name = "Unknown";
	}
	
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
	if (regex_match(email, email_pattern))
		Email = email;
	else{
		Email = "";
	}
}
void Person::set_phoneNumber(string num){
	if (regex_match(num, Phone_number_pattern)) {
		Phone_number = num;
	}
	else {
		Phone_number = "Unknown";
	}
}

//Getters

string Person::get_name(){
	return Name;
}
unsigned int Person::get_age(){
	return Age;
}
string Person::get_address(){
	return Address;
}
string Person::get_email(){
	return Email;
}
string Person::get_phoneNumber(){
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