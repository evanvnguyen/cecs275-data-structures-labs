/*
 * Answer to Lab 4
 * CECS 275 - Spring 2022 
 * @author Joseph Guzman 
 * @author Evan Nguyen 
 * @version 1.0.0 
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Employee.h"
#include "BankAccount.h"

using namespace std;

int main()
{
    //Vector for each of the employees within the txt file
    vector<Employee*> employees;

    //Points for Employee and Bank Account
    Employee *employ;
    BankAccount *bank_account;

    //Initialize variables
    string id_Num; 
    string first_Name;
    string last_Name; 
    string word;
    string starting_Salary;
    string temp_Salary;
    double salary;

    // Read from the text file
    ifstream fileread("salary.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (fileread >> id_Num)
    {
        // reading first name, last name and salary into string type variables
        fileread >> first_Name;
        fileread >> last_Name;
        fileread >> starting_Salary;

        // converts string to double
        salary = stod(starting_Salary);

        // creates a bank account for the Employee
        bank_account = new BankAccount();

        // setting bank account id same as Employee id
        bank_account->set_id(id_Num);

        // creating a new Employee object
        employ = new Employee(id_Num, first_Name, last_Name, salary, bank_account);

        // push back into vector "employees"
        employees.push_back(employ);
    }
    // closing file
    fileread.close();

    // Create and open a text file for writing
    ofstream filewrite("monthly_salary.txt");

    filewrite << "Employee ID   |Last Name       |First Name       |Annual Salary    |Monthly Salary    |Balance   " << endl;

    // write the rest to a file

    // Close the file
    filewrite.close();
    return 0;
}

