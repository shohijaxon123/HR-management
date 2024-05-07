#pragma once
#include <iostream>
#include <string>
# include <regex>
#include<Person.h>

using namespace std;


class Candidate : public Person{
private:
    // Dynamic Array with skills
    int Experience;
    int Rating;
    bool Accepted;

public:

//Default constructor
    Candidate(){
        Name = "Unknown";
		Age = 0;
		Address = "";
		Email = "";
		Phone_number = "";
        Experience = 0;
        Accepted = false;
    }

    Candidate(const string& name, unsigned int age, string address, string email, string number, int exp, bool status) : Person(name, age, address, email, number){
        Name = name;
		Age = age;
		Address = address;
		Email = email;
		Phone_number = number;
        Experience = exp;
        Accepted = status;
    }

    void display_info_of_Candidate(){
        Person::display_info_of_person();
        cout<<"Experience: "<< Experience<<" years"<<endl;
        //cout<<"Skills: "<< <<endl;
        cout<<"Accepted: "<< Accepted<<endl;
    }

    void show_rating(){
        cout << "Rating: " << Rating<<endl;
    }

};

//Getters and setters required