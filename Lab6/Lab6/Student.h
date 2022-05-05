#pragma once
#include "LinkedList.h"
#include <string>

using namespace std;
class Student{
private:
	int studentID;
    string firstName;
	string lastName;
    LinkedList<Course> courseList;

public:
    // Constructors
	Student();
 	Student(int ID, std::string first, std::string last, LinkedList<Course> list);
	Student(int ID, std::string first, std::string last);
	
	// Get functions
    string getFullName() const;
    int getStudentId() const;
    LinkedList<Course> getSchedule() const;
    
    // Course functions *access the linked list
    void dropCourse(Course c);
    void addCourse(Course c);
    void sortCourse();
    void showCourses() const;
    
    void toString() const;    
};
