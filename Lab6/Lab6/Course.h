#pragma once
#ifndef COURSE_H
#define COURSE_H

using namespace std;
#include <string>
#include <iostream>

class Course {
	private:
		int courseNumber;
		string courseName;
		string courseTime;
		string courseSemester;
	public:
		Course();
		Course(int, string, string, string);
		void toString();

		// Getters and setters
		void setNumber(int number);
		void setName(string name);
		void setTime(string time);
		void setSemester(string semester);

		int getNumber() const;
        string getName() const;
        string getTime() const;
        string getSemester() const;
		
		// Operator overloaders
        bool operator==(Course &c);
        bool operator!=(Course &c);
        bool operator<(Course &c);
        bool operator>=(Course &c);
};

#endif 