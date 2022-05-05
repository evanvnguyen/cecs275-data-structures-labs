#include "BankAccount.h"
#include "BankAccount.cpp"

#include "Employee.h"
#include "Employee.cpp"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<Employee> readData(string);

int main () {
    string inputFile = "salary.txt";
    readData(inputFile); // read data from salary.txt, return a vector<Employee>
    return 0;
}

vector<Employee> readData(string inputFile) {

    
    // dynamically allocate a new employee every time a line is read
    
    vector<Employee> emp;
    string word;
    string read_id;
    string read_fn;
    string read_ln;
    string read_s;


    ifstream readFile(inputFile);

    getline(readFile, word); // skip first line
    while (readFile >> word) {
        cout << word << endl;
    }
    // store each attribute into an employee object

    //return a vector of employees
    return emp;
}