
#pragma once
#include <string>
#include <vector>
#include "StudentCourse.hpp"
using namespace std;

class Student{
private:
    string name;
    vector<course> c; // this stores all the classes they took

public:
    Student(){ //blank incase we dont know the name yet
    } 
    Student(string n){ //student with a name already 
        name=n;
    } 

    void setName(string n){
        name=n; 
    }
    string getName()const{
        return name; //just return the students name
    }

    void addCourse(const course& newCourse){
        c.push_back(newCourse); //puts the class in the course list
    }

    const vector<course>& getCourses()const{
        return c; //gives back all the courses (gives access)
    }

    int totalCredits()const{
        int s=0; //loops thrpugh all courses and adds up their credits 
        for(int i=0;i<c.size();i++){
            s+=c[i].credits;
        }
        return s;
    }

    double totalPoints()const{
        double s=0; //same thing but adding the grade points
        for(int i=0;i<c.size();i++){
            s+=c[i].Totalpts;
        }
        return s;
    }

    double gpa()const{
        int t=totalCredits();
        if(t==0) return 0; //to not divide by zero or else program wont work
        return totalPoints()/t;
    }

    string standing()const{
        double g=gpa(); //tells us their status based on gpa
        if(g>=3.70) return "Dean's List";
        if(g>=2.00) return "Good Standing";
        return "Probation"; //if it didnt pass the first 2 it will be this
    }
};
