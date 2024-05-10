#pragma once
#include"Person.h"

using namespace std;


class Candidate : public Person{
private:
    // Skills = Dynamic Array with skills using vectors or new
    vector<string> Skills;
    int Experience;
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

    //Distructor
    ~Candidate() {
        Skills.clear();
    }

    void display_info();

    void set_experience(int exp);
    void set_status(bool status);
    void set_skills();

    vector<string> get_skills();
    int get_experience();
    bool get_status();


    void show_skills();
};

//Setters

void Candidate::set_experience(int exp){
    Experience = exp;
}

void Candidate::set_status(bool status){
    Accepted = status;
}
void Candidate::set_skills(){
    string skill;

    cout<<"Enter your skills and if you want to stop enter 'stop' : "<<endl;
    
    do
    {
        cout << "Enter your skill : "; cin >> skill;
        if (skill != "stop") {
            Skills.push_back(skill);
    }
        
        
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

bool Candidate::get_status(){
    return Accepted;
}

//Display functions

void Candidate::display_info(){
        Person::display_info_of_person();
        cout<<"Experience: "<< Experience<<" years"<<endl;
        cout<<"Accepted: "<< Accepted <<endl;
        cout << "Skills:\n"; this->show_skills();
    }

void Candidate::show_skills(){
    for (int i=0; i < Skills.size(); i++){
        cout<<i+1<<" - "<< Skills[i] <<endl;
    }
}

