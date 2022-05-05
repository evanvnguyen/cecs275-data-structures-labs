#include "Date.h"
#include <iostream>
#include <array>
#include <iomanip>
using  namespace std;

array<int, 13> monthDays { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const array<string, 13> monthNames { "", "January", "February", "March", "April",
                                    "May", "June", "July", "August", "September",
                                    "October", "November", "December" };
enum Months { January = 1, February, March, April, May, June, July,
            August, September, October, November, December };


Date::Date():Date(1, 1, 1970){

}
Date::Date(int aDay, int aMonth, int aYear){
    day = aDay;
    month = aMonth;
    year = aYear;
}

void Date::setMonth(int aMonth)
{
    if (aMonth >= January && aMonth <= December)
    {
        month = aMonth;
    }
    else
    {
         throw InvalidMonth(aMonth);
    }
}

void Date::setDay(int aDay)
{  
    if (month == February && isLeapYear() && aDay == 29)
    {
        day = aDay;
        monthDays[2] = 29;
    }
    else if (aDay < 1 || aDay > monthDays[month])
    {
        throw InvalidDay(aDay);
    }
    else
    {
        day = aDay;
    }
}

void Date::setYear(int aYear)
{
    if (aYear >= 1 && aYear <= 2023)
    {
        this->year = aYear;
    }
    else
    {
         throw InvalidYear(aYear);
    }
}

bool Date::isLeapYear()
{
    //cout << year << endl;
    if (year % 4 == 0)
    {
        return true;
    }
    else if (year % 100 != 0)
    {
        return true;
    }
    else if (year % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Date::listAllDates() {
    // iterate thru the months and output each date
    cout << "-----------------All possible dates of the year " << year <<
            ". Chosen date is bracketed.----------------" << endl;
    for (int monthInt = January; monthInt < December + 1; monthInt++){
        cout << setw(9) << monthNames[monthInt] << ": ";
        for (int i = 1; i < monthDays[monthInt] + 1; i++) {
            // check if we're in the day and month we set, put it in brackets
            if ((i == day) && (monthInt == month)){
                cout << "[" << i << "] ";
            } else {
            cout << i << " ";
            }
        }
        cout << endl;
    }
}

Date Date::operator++(int aDay){
    Date temp;
    // assign temp to this->day and increase it
    temp.day = this->day+1;
    //day++;
    
    if (temp.day > monthDays[month]){
        month = month+1;
        day = 1;
    } else {
        day++;
    }

    cout << "Next day: ";
    getToString1();
    
    return temp;
}

Date Date::operator--(int aDay){
    Date temp;
    // assign temp to this->day and decrease it
    temp.day = this->day;
    day--;
    day--;
    // if leap year then make sure it works
    if (day < 1){
        month = month-1;
        day = monthDays[month];
        if (day == 29 && monthDays[month] == 29){
            day--;
        }
    } else {

    }
    cout << "Previous day: ";
    getToString1();
    return temp;
}

void Date::getToString1() const
{
    cout << "Date format 1: " << month << "/" << day << "/" << year << "\n";
}

void Date::getToString2() const
{
    cout << "Date format 2: " << monthNames[month] << " " << day << ", " << year << "\n";
}

void Date::getToString3() const
{
    cout << "Date format 3: " << day << " " << monthNames[month] << " " << year << "\n";
}