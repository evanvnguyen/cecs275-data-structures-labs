/*
 * Answer to Lab 6
 * CECS 275 - Spring 2022 
 * @author Evan Nguyen  
 * @author Joseph Guzman
 * @version 1.0.0 
 *
 */

#include <iostream>
#include "Student.h"
#include "LinkedList.h"
#include "Course.h"
#include <random>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int yourID;
    string yourFirst;
    string yourLast;
    cout << "Welcome to your Spring 2022 enrollment center. Please enter your \nID: ";
    cin >> yourID;
    cout << "Your first name: ";
    cin >> yourFirst;
    cout << "Your last name: ";
    cin >> yourLast;

    // create the student object
    Student myStudent = Student(yourID, yourFirst, yourLast);

    // provide a vector of unsorted courses
    vector<Course> catalog = { Course(275, "CECS", "MW 5:30 PM - 7:30 PM", "Spring 2022"),
                               Course(346, "CECS", "TuThu 5:30 PM - 7:30 PM", "Spring 2022"),
                               Course(458, "MUS", "ONLINE ASYNCHRONOUS", "Spring 2022"),
                               Course(317, "ENGL", "TuThu 9:30 AM - 10:30 AM", "Spring 2022"),
                               Course(340, "REC", "ONLINE ASYNCHRONOUS", "Spring 2022"),
                               Course(122, "THEA", "ONLINE ASYNCHRONOUS", "Spring 2022"),
                               Course(460, "CECS", "Friday 10:30 AM - 4:30 PM", "Spring 2022"),
                               Course(174, "CECS", "MW 8:00 AM - 9:30 AM", "Spring 2022")};
    cout << "--------------------------------------------------------------------------------\n";
    cout << "Based on your major: COMPUTER ENGINEERING, here are the courses availble to you:\n";
    


    for (int i = 0; i < catalog.size(); i++) {
        cout <<  "COURSE ID# " << i + 1 << ": ";
        cout << catalog[i].getSemester() << " ";
        cout << catalog[i].getName() << " ";
        cout << catalog[i].getNumber() << ": ";
        cout << catalog[i].getTime() << "\n";
    }

    bool isDone = false;
    string selection;
    
    cout << "--------------------------------------------------------------------------------\n";
    // add course loop
    while (!isDone) {
        cout << "What courses would you like to enroll in? Enter the number(Press F to finish enrolling): ";
        cin >> selection;
        if (selection == "F") {
            isDone = true;
        } else {
            myStudent.addCourse(catalog[stoi(selection) - 1]);            
            cout << "Enrolled!\n";
        }

    }
    cout << "--------------------------------------------------------------------------------\n";
    cout << "You have enrolled in these courses:\n";
    myStudent.toString();    
    
    cout << "--------------------------------------------------------------------------------\n";
    bool remove = false;

    while(!remove){        
        cout << "Would you like to drop any of these courses (Press F if not)? " << endl;
        cout << "Please enter the COURSE # shown previously to drop the selected course.\n";
        myStudent.showCourses();
        cin >> selection;
        if (selection == "F") {
            remove = true;
        } else {
            myStudent.dropCourse(catalog[stoi(selection) - 1]);                        
            cout << "Deleted!\n";
        }
    }
    
    cout << "--------------------------------------------------------------------------------\n";
    cout << "Remaining courses sorted with course number :" << endl;
    myStudent.sortCourse();
    myStudent.toString();

    return 0;
}
