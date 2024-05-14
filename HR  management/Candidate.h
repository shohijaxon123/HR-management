#pragma once
#include"Person.h"
#include"Admin.h"
using namespace std;


class Candidate : public Person{
private:
    int ID;
    vector<string> Skills;
    int Experience;
    bool Accepted;
    int Rating;
public:

    static int Count;
    //Default constructor
    Candidate(){
        ID = Count++;
        Name = "Unknown";
		Age = 0;
		Email = "";
		Phone_number = "";
        Experience = 0;
        Accepted = false;
        Rating = 0;
    }

    //Parametrized constructor without skills
    Candidate(const string& name, unsigned int age, string email, string number, int exp) : Person(name, age, email, number){
        ID = Count++;
        this->set_name(name);
        this->set_age(age);
        this->set_email(email);
        this->set_phoneNumber(number);
        Experience = exp;
        Accepted = false;
        Rating = 0;
    }
    //Parametrized constructor with skills
    // skill vector is a reference WARNING

    Candidate(const string& name, unsigned int age,  string email, string number, int exp, vector<string> skills) : Person(name, age, email, number){
        ID = Count++;
        this->set_name(name);
        this->set_age(age);
        this->set_email(email);
        this->set_phoneNumber(number);
        Experience = exp;
        Skills = skills;
        Accepted = false;
        Rating = 0;
    }

    //Distructor
    ~Candidate() {
        Skills.clear();
        Skills.shrink_to_fit();
    }

    void display_info();

    void set_experience(int exp);
    void set_status(bool status);
    void set_skills();
    void set_rating(int rate);

    vector<string> get_skills();
    int get_experience();
    bool get_status();
    int get_rating();
    int get_ID();

    void show_skills();

    void calculate_rating(vector<string>skills);


};

int Candidate::Count = 0;
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
            Skills.push_back(toLowerCase(skill));
    }
        
        
    } while (skill != "stop");
    Skills.shrink_to_fit();
}

void Candidate::set_rating(int rate) {
    Rating = rate;
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
int Candidate::get_rating() {
    return Rating;
}
int Candidate::get_ID() {
    return ID;
}

//Display functions
void Candidate::display_info(){
    cout << "ID: " << ID << endl;
    Person::display_info_of_person();
    cout<<"Experience: "<< Experience<<" years"<<endl;
    cout<<"Accepted: "<< Accepted <<endl;
    cout << "Skills:\n"; this->show_skills();
    }

void Candidate::show_skills(){
    for (int i=0; i < Skills.size(); i++){
        cout << i + 1 << " - " << Skills[i] << endl;
    }
    cout << endl;
}

//Calculations
void Candidate::calculate_rating(vector<string>skills) {

    int relevant_skills = 0;
    for (int i = 0; i < skills.size(); i++) {
        for (int j = 0; j < this->get_skills().size(); j++) {
            if (skills[i] == this->get_skills()[j]) {
                relevant_skills++;
                break;
            }
        }

    }
    int rating = (int)ceil(10 * relevant_skills / skills.size());
    this->set_rating(rating);
}