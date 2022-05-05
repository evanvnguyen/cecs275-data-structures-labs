/*
 * Answer to #1 on Lab 5
 * CECS 275 - Spring 2022 
 * @author Evan Nguyen  
 * @author Joseph Guzman
 * @version 1.0.0 
 *
 */

#include "Date.h"
#include <iostream>

using  namespace std;
int main()
{
    int month = 0;
    int day = 0;
    int year = 0;
    bool isDone = false;


    cout << "Enter your birthday: (DAY MONTH YEAR) ";
    cin >> day >> month >> year;
    cout << "\n";
    
    while (!isDone)
    {
        try
        {    
            //Date dateObj(day, month, year);
            
            //dateObj(day, month, year);
            Date dateObj;
            dateObj.setMonth(month);
            dateObj.setDay(day);
            dateObj.setYear(year);
            
            dateObj.getToString1();
            dateObj.getToString2();
            dateObj.getToString3();
            
            dateObj.listAllDates();
            dateObj++;
            dateObj--;

            isDone = true;
        }
        catch (Date::InvalidDay dayVal)
        {
            cout << "Error: Day " << dayVal.getInvalidDay() << " is invalid.\n";
            cout << "Please enter a valid day: \n";
            cin >> day;
        }
        catch (Date::InvalidMonth monthVal)
        {
            cout << "Error: Month " << monthVal.getInvalidMonth() << " does not exist.\n";
            cout << "Please enter a valid month: \n";
            cin >> month;
        }
        catch (Date::InvalidYear yearVal)
        {
            cout << "Error: Year " << yearVal.getInvalidYear() << " does not exist.\n";
            cout << "Please enter a valid year: \n";
            cin >> year;
        }
        cout << "\n";
    }
    
    
    cin.ignore();
    cin.get();
    

    return 0;
}
