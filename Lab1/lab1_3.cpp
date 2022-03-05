/*
 * Answer to #3 on Lab 1 
 * CECS 275 - Spring 2022 
 * @author Joseph Guzman 
 * @author Evan Nguyen 
 * @version 1.0.0 
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    string s;
    string sub_string;
    string reversed;
    int index;
    int n_index;
    int step = 0;

    cout << "s = ";
    cin >> s;
    
    /* get the length of the string
       this is our starting index at each iteration */
    index = s.length(); 

    while (index > 1){        
        /* Index is our procedural assignment of index at each half
           get the floor of the index, find the substring index each iteration */
        index = floor(index / 2); 
        n_index = s.length() - index;
        sub_string = s.substr(n_index, s.length());
        
        // reset the reversed string
        reversed = "";
        for (int i = sub_string.length()-1; i >= 0; i--){
            /* FOR DEBUG
            cout << substring[i] << endl;
            reversed.append(sub_string[i]);
            */
            reversed += sub_string[i];
        }
        
        // get the beginning string and add the new reversed string
        s = s.substr(0, n_index) + reversed;

        /* FOR DEBUG PURPOSES:
        cout << "s at the beginning of while: " << s << endl;
        cout << index;
        cout << s.substr(n_index, s.length()) << endl;
        cout << "value of n_index before taking substring: " << n_index << endl;
        cout << sub_string << endl;
        cout << "value of sub_string: " << sub_string << endl;
        cout << "s.length - index: " << n_index << endl; 
        cout << "index character: " << n_index << "is: " << s[n_index] << endl;
        cout << "DEBUG: s: " << s << endl;
        cout << "reverse of substring: " << reversed << endl;
        cout << "0 to index: " << index << endl;
        cout << "length of: " << s << " " << s.length() << endl;
        */

        step += 1;
        cout << "Step " << step << " : " << s << endl;

        /* I noticied in the test cases, when the index floor value
           is 2, it stops the recursion.
           This breaks the loop at index 2 */
        if (index == 2) {
            break;
        }
    }
    return 0;
}