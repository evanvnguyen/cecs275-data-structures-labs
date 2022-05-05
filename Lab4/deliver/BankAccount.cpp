#include "BankAccount.h"
#include <string>

// implementation file, so we can use this here
using namespace std;

// Constructor Function - set every new instance of BankAccount (via employee)
BankAccount::BankAccount(){
    
    // get id from employee
    id;

    // default bank balance 
    balance = 2000;

}

/* DEPOSIT
Deposits money into this account.
@param amount the amount to deposit.
Void - dont return and only set a member variable
*/
void BankAccount::deposit(double amount){
    balance = balance + amount;
}

/* 
Withdraws money from this account.
@param amount the amount to withdraw.
*/
void BankAccount::withdraw(double amount){
    // not needed?
}

/*
Gets the balance of this account.
@return the balance
*/
double BankAccount::get_balance() const{
    // to set balance, point to it

    return balance;
}

/*
Gets the id of this account.
@return the id
*/
string BankAccount::get_id() const{

    return id;
}

/*
Set id for bank account.
Void - dont return and only set a member variable
*/
void BankAccount::set_id(string id){

    // get OG ID from employee by using "this"
    this->id = id;
}
