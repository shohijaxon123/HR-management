#pragma once
#include"Person.h"

using namespace std;


class Candidate : public Person{
private:
    // Skills = Dynamic Array with skills using vectors or new
    vector<string> Skills;
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
    //Parametrized constructor without skills
    Candidate(const string& name, unsigned int age, string address, string email, string number, int exp) : Person(name, age, address, email, number){
        Name = name;
		Age = age;
		Address = address;
		Email = email;
		Phone_number = number;
        Experience = exp;
        Accepted = false;
    }
    //Parametrized constructor with skills
    // skill vector is a reference WARNING

    Candidate(const string& name, unsigned int age, string address, string email, string number, int exp, vector<string>& skills) : Person(name, age, address, email, number){
        Name = name;
		Age = age;
		Address = address;
		Email = email;
		Phone_number = number;
        Experience = exp;
        Skills = skills;
        Accepted = false;
    }


    void display_info_of_Candidate();
    void show_rating();

    void set_experience(int exp);
    void set_rating(int rating);
    void set_status(bool status);
    void set_skills();

    vector<string> get_skills();
    int get_experience();
    int get_rating();
    bool get_status();


    void show_skills();
};

//Setters

void Candidate::set_experience(int exp){
    Experience = exp;
}
void Candidate::set_rating(int rating){
    Rating = rating;
}
void Candidate::set_status(bool status){
    Accepted = status;
}
void Candidate::set_skills(){
    string skill;

    cout<<"Enter your skills and if you want to stop enter 'stop' : "<<endl;
    
    do
    {
        cout<<"Enter your skill : "; cin>>skill;
        Skills.push_back(skill);
        
    } while (skill != "stop");
    Skills.shrink_to_fit();
}

//Getters
vector<string> Candidate::get_skills(){
    return Skills;
}

int Candidate::get_experience(){
    return Experience;
}
int Candidate::get_rating(){
    return Rating;
}
bool Candidate::get_status(){
    return Accepted;
}

//Display functions

void Candidate::display_info_of_Candidate(){
        Person::display_info_of_person();
        cout<<"Experience: "<< Experience<<" years"<<endl;
        cout<<"Skills:\n"; this->show_skills();
        cout<<"Accepted: "<< Accepted<<endl;
    }

void Candidate::show_rating(){
        cout << "Rating: " << Rating<<endl;
    }

void Candidate::show_skills(){
    for (int i=0; i<Skills.size(); i++){
        cout<<i<<" - "<< Skills[i] <<endl;
    }
}

