
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

 double convertGrade(string L)
{
    double Totalpts;

    if (L == "A" || L == "A+" || L == "a" || L == "a+") 
        Totalpts = 4.0;
    else if (L == "A-" || L == "a-") 
        Totalpts = 3.7;
    else if (L == "B+" || L == "b+") 
        Totalpts = 3.3;
    else if (L == "B" || L == "b")  
        Totalpts = 3.0;
    else if (L == "B-" || L == "b-") 
        Totalpts = 2.7;
    else if (L == "C+" || L == "c+") 
        Totalpts = 2.3;
    else if (L == "C" || L == "c")   
        Totalpts = 2.0;
    else if (L == "C-" || L == "c-") 
        Totalpts = 1.7;
    else if (L == "D+" || L == "d+") 
        Totalpts = 1.3;
    else if (L == "D" || L == "d")   
        Totalpts = 1.0;
    else if (L == "D-" || L == "d-") 
        Totalpts = 0.7;
    else                             
        Totalpts = 0.0;

    return Totalpts;
}

inline void greetUser(string name)
{
    cout << "Student: " << name << "!" << endl;
}

class course
{
public:
    string coursename;
    string L;
    int credits;
    double gradePts;
    double Totalpts;

    void input()
    {
        cout << "Please enter the Information below (Only press Enter, when starting): " << endl;

        cout << "Course Name: " << endl;
        getline(cin >> ws, coursename); 

        cout << "Credits: " << endl;
        while (!(cin >> credits) || credits < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a non-negative integer for credits: " << endl;
        }

        cout << "Grade (A, B+, C-, etc): " << endl;
        cin >> L;

        gradePts = convertGrade(L);
        Totalpts = credits * gradePts;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
    }

    void display()
    {
        cout << setw(30) << left  << coursename
             << setw(10) << right << fixed << setprecision(2) << credits
             << setw(10) << right << gradePts
             << setw(10) << right << Totalpts << endl;
    }
};