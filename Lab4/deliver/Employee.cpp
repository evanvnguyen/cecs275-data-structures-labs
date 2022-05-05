#include "Employee.h"
#include <string>
#include <iostream>

// implementation file, so we can use this here
using namespace std;

// Constructor function - set every new instance of Employee (via reading file)
Employee::employee(string id, string fn, string ln, double s, BankAccount* a){
    // read id, name, salary from file
    this->id = id;
    thisFn = fn;
    thisLn = ln;
    thisSalary = s;
    account = a;
}

//Deposits one month's salary into the bank account.
void Employee::deposit_monthly_salary(){
    double newSal = thisSalary / 12;
    account->deposit(newSal);
}

/*
Prints this employee's information to cout.
Void - dont return and only set a member variable
*/
void Employee::print() const{
    cout << "ID: " << id << endl;
    cout << "FN: " << thisFn << endl;
    cout << "LN: " << thisLn << endl;
    cout << "Salary: " << thisSalary << endl;
    cout << "Bank ID: " << account->get_id() << endl;
    cout << "Account balance: " << account->get_balance() << endl;
}

string Employee::get_id() const {

    return id;
}

// GET first_name, set as constant to avoid changes
// Taken from file and initialized in instance creation
string Employee::get_fn() const{
    return thisFn;
}

// GET last_name, set as constant to avoid changes
// Taken from file and initialized in instance creation
string Employee::get_ln() const {
    return thisLn;
}

// GET salary, set as constant to avoid changes
// Taken from file and initialized in instance creation
double Employee::get_salary() const {
    return thisSalary;
}

// GET account, set as constant to avoid changes
// Point to account
BankAccount *Employee::get_account() const {
    return account;
}
