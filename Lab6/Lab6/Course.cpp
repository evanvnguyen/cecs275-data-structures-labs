#include "Course.h"

// Course no arg constructor
Course::Course() {
	courseNumber = 0;
	courseName = "NULL";
	courseSemester = "NULL";
    courseTime = "NULL";
}

// Course overloaded constructor
Course::Course(int number, std::string name, std::string time, std::string semester) {
	courseNumber = number;
	courseName = name;
	courseTime = time;
	courseSemester = semester;
}

// Set functions
void Course::setNumber(int number) {
	courseNumber = number;
}
void Course::setName(std::string name) {
	courseName = name;
}
void Course::setTime(std::string time) {
	courseTime = time;
}
void Course::setSemester(std::string semester) {
	courseSemester = semester;
}

// Get functions
int Course::getNumber() const{
    return courseNumber;
}
string Course::getName() const{
    return courseName;
}
string Course::getTime() const{
    return courseTime;
}
string Course::getSemester() const{
    return courseSemester;
}

// Output as a string 
void Course::toString() {
	cout << "-> "<< courseName << " " << courseNumber << ": " << courseTime << endl;
}

// Operator overloading functions
bool Course::operator==(Course &c){
	if (courseNumber == c.courseNumber){
		if(courseName == c.courseName){
			if(courseTime == c.courseTime){
				if(courseSemester == c.courseSemester){
					return true;
                }
			}
		}
	}
    return false;
}

bool Course::operator!=(Course &c){
    return !operator==(c);
}

bool Course::operator<(Course &c){
    return courseNumber < c.courseNumber;
}

bool Course::operator>=(Course &c){
    return !operator<(c);
}