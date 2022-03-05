/* 
 * Answer tp #1 on Lab2
 * CECS 275 - Spring 2022
 * @author Evan Nguyen
 * @author Joseph Guzman
 * @version 1.0.0
 */

#include <iostream>
#include <string>
using namespace std;

int main () {

    string userInput;
    int foundDigit;
    int sum;

    while (true) {
        sum = 0;
        foundDigit = 0;
        cout << "Enter a positive integer: ";
        cin >> userInput;

        /*  APPROACH:
            iterate through each index of the string, 
            find its ascii comparison of each index, store it and sum
            - doing the modulo equation results in program breaking if input > range of data type
            - if string = "0", invalid
            - if index 0 of string = '-', ASCII 45, can assume its negative */

       if (userInput == "0") {
           cout << "You have entered zero. Please try again!\n";
       } else if (userInput[0] == '-') {
           cout << "You have entered a negative number. Please try again!\n";
       } else {
           cout << "You have entered " << userInput << ".\n";
           /* for each char in userInput, find it's distance from "0",
            * aka, it's integer value */
           for (char ch : userInput) {
               foundDigit = (ch - '0');
               //cout << "foundDigit: " << foundDigit << endl;
               sum += foundDigit;
               //cout << "sum: " << sum;
           }
           cout << "The sum of all the digits of " << userInput << " is " << sum << endl << endl;
       }
    }
    return 0;
}