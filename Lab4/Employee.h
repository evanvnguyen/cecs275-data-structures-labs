#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "BankAccount.h"
#include <string>

// omit using namespace std in header files
// and implicitly type std

class Employee {

    public:
        /*
        Constructs an employee with a id, given name, salary, and
        bank account.
        @param id the id
        @param n the name
        @param s the annual salary
        @param a a pointer to the bank account
        */
        employee(std::string id, std::string fn, std::string ln, double s, BankAccount* a);

        //Deposits one month's salary into the bank account.
        void deposit_monthly_salary();

        //Prints this employee's information to cout.
        void print() const;

        // GET ID
        std::string get_id() const;

        // GET first name
        std::string get_fn() const;

        // GET last name
        std::string get_ln() const;

        // GET salary
        double get_salary() const;

        // GET - pointer to employees account instance
        BankAccount *get_account() const;

    private:
        std::string id;
        // separate name to fn and ln cuz its easier
        std::string thisFn;
        std::string thisLn;
        double thisSalary;
        BankAccount* account;
};

#endif