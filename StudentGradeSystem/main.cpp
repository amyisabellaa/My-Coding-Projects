
#include <iostream> 
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include "StudentCourse.hpp"
using namespace std;

int main()
{
    // Ask for their name
    string name;
    cout << "Please enter your name: " << endl;
    getline(cin, name);
    greetUser(name); // greeting the user

    // Asking for how many courses
    int numCourses;
    cout << "How many courses are you taking? " << endl;
    cin >> numCourses;
    cin.ignore(); // to ignore the additional numbers

    // Asking for course details
    vector<course> course(numCourses);
    for (int i = 0; i < numCourses; i++)
    {
        cout << "Enter details for course " << (i + 1) << ": " << endl;
        course[i].input();
    }
    cin.ignore(); 
    cout << "==================== Student Grade Report ====================" << endl
         << endl;
    cout << "Student Name: " << name << endl;
    cout << endl;
    cout << setw(30) << left << "Classes " << right << setw(10) << "Credits" << setw(10) << "GradePts" << setw(10) << "TotalPts" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (int i = 0; i < numCourses; i++)
    {
        course[i].display();
    }

    cout << "--------------------------------------------------------------" << endl;
    int totalCredits = 0;
    double totalGradePoints = 0.0;
    double semesterGPA = 0.0;
    string Standing;

    for (int i = 0; i < numCourses; i++)
    {
        totalCredits += course[i].credits;
        totalGradePoints += course[i].Totalpts;
        semesterGPA = totalGradePoints / totalCredits;
    }

    if (semesterGPA >= 3.70)
        Standing = "Dean's List";
    else if (semesterGPA >= 2.00)
        Standing = "Good Standing";
    else if (semesterGPA < 2.00)
        Standing = "Probation";

    cout << setw(30) << left << "Total Credits: " << setw(10) << right << totalCredits << endl;
    cout << setw(30) << left << "Total Points: " << setw(10) << right << fixed << setprecision(2) << totalGradePoints << endl;
    cout << setw(30) << left << "Semester GPA: " << setw(10) << right << fixed << setprecision(2) << semesterGPA << endl;
    cout << setw(30) << left << "Standing: " << setw(10) << right << Standing << endl;

    cout << "===============================================================" << endl;

    return 0;
}
