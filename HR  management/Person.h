#pragma once
#include <iostream>
#include<chrono>
#include<cctype>
#include <string>
#include <regex>
#include<vector>
//#include <algorithm>

using namespace std;

const regex email_pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); 
const regex Name_pattern("^[A-Za-z ]+$");
const regex  Phone_number_pattern("\\+\\d{12}");
  
class Person{
protected:
	string Name;
	unsigned int Age;
	string Email;
	string Phone_number;
public:
	Person(){
		Name = "Unknown";
		Age = 0;
		Email = "";
		Phone_number = "";
	}

	Person(const string& name, unsigned int age, string email, string number){
		this->set_name(name);
		this->set_age(age);
		this->set_email(email);
		this->set_phoneNumber(number);
	}


	//Input validation
	 static bool validate_name(string name);
	 static bool validate_email(string email);
	 static bool validate_age(unsigned int age);
	 static bool validate_Phonenumber(string num);

	//setters
	void set_name(string name);
	void set_age(unsigned int age);
	void set_email(string email);
	void set_phoneNumber(string num);

	string get_name();
	unsigned int get_age();
	string get_email();
	string get_phoneNumber();

	void display_info_of_person();
};

// Person class member functions

//Input validation
bool Person::validate_name(string name) {
	if (regex_match(name, Name_pattern)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool Person::validate_email(string email) {
	if (regex_match(email, email_pattern))
	{
		return 1;
	}
	else {
		return 0;
	}

}
bool Person::validate_age(unsigned int age) {
	if (age > 14 && age < 80)
	{
		return 1;
	}
	else {
		return 0;
	}

}
bool Person::validate_Phonenumber(string num) {
	if (regex_match(num, Phone_number_pattern))
	{
		return 1;
	}
	else {
		return 0;
		}

}

//Setters
void Person::set_name(string name) {
	if (validate_name(name) == 1) {
		Name = name;
	}
	else {
		cout << "Name - " << name << " can not be accepted!!!"<<endl;
	}
}
void Person::set_age(unsigned int age) {
	if (validate_age(age) == 1) {
		Age = age;
	}
	else {
		cout << "Age - " << age << " can not be accepted!!!" << endl;
	}
}

void Person::set_email(string email){
	if (validate_email(email) == 1) {
		Email = email;
	}
	else{ cout << "Email - " << email << " can not be accepted!!!" << endl; }
}
void Person::set_phoneNumber(string num){
	if (validate_Phonenumber(num) == 1) {
		Phone_number = num;
	}
	else {
		cout << "Phone number - " << num << " can not be accepted!!!" << endl;
	}
}

//Getters

string Person::get_name(){
	return Name;
}
unsigned int Person::get_age(){
	return Age;
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
	cout<< "Phone Number: " << Phone_number << endl;
	cout<< "Email address: " << Email << endl;
}

string toLowerCase(const string& str) {
	string result = str;

	for (char& c : result) {
		c = tolower(c);
	}
	return result;
}