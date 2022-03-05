/*
 * Answer to #2 on Lab 1 
 * CECS 275 - Spring 2022 
 * @author Joseph Guzman 
 * @author Evan Nguyen 
 * @version 1.0.0 
 *
 */

#include <iostream>
using namespace std;

int main() {

    /** Given a positive integer n (0 < n < 10000000),
        print the sequence of numbers where
        if n is even, then evaluate n / 2.
        if n is odd, then evaluate 3n + 1 **/

    int n;
    int count; 
    string out;

    while (true) {

        // get input and initialize the count 
        cout << "n = ";
        count = 1;
        cin >> n;

        while (n != 1) {

            // Method to output the recursive series:
            // 1. Initialize the starting n, and cout it
            // 2. Evaluate the function
            // 3. Add a comma delimiter to the same line (no endl)
            // 4. The function should resolve to 1, output it at the end of the line.
            count += 1;
            cout << n;

            // if n % 2 == 0, no remainder, n is even.
            if (n % 2 == 0){
                n = n / 2;
            // if n % 2 == 1, remainder, n is odd.
            } else if (n % 2 == 1) {
                n = 3 * n + 1;
            }
            // add a comma delimiter
            cout << ", ";
        }
        // the function should resolve to 1, thus output to the end of the line.
        cout << n << endl;
        cout << "There are " << count << " numbers." << endl;
    }
    return 0; 
}