#include "Student.h"

#include <string>

Student::Student() {
	int studentID = 0;
	std::string firstName = "John";
	std::string lastName = "Doe";
	LinkedList<Course> courseList;
}

Student::Student(int ID, std::string first, std::string last, LinkedList<Course> list) {
	studentID = ID;
	firstName = first;
	lastName = last;
    courseList = list;
}

Student::Student(int ID, std::string first, std::string last){
	studentID = ID;
	firstName = first;
	lastName = last;
}

int Student::getStudentId() const{
    return studentID;
}

LinkedList<Course> Student::getSchedule() const{
    return courseList;
}

void Student::dropCourse(Course c){
    courseList.deleteNode(c);
}

void Student::addCourse(Course c){
    courseList.appendNode(c);
}

void Student::sortCourse(){
    courseList.insertionsort();	
}

// Output as a string while moving through the linked list
void Student::toString() const{
	ListNode<Course> *head = courseList.getHead();
    cout << "ID	   : " << studentID << endl;
	cout << "First Name : " << firstName << endl;
	cout << "Last Name  : " << lastName << endl;
    cout << "----------Schedule for " << head->value.getSemester() << "----------" << endl;	    	
		
	ListNode<Course>* nodePtr; // To move through the list	
	nodePtr = head;	
	while (nodePtr) {
        nodePtr->value.toString();        
        nodePtr = nodePtr->next;
	}
}

// Traverse the students linkedlist of courses
void Student::showCourses() const{
	ListNode<Course> *head = courseList.getHead();
	ListNode<Course>* nodePtr; // To move through the list	
	nodePtr = head;	
	while (nodePtr) {
        nodePtr->value.toString();        
        nodePtr = nodePtr->next;
	}
}