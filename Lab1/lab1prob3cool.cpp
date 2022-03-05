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
    int step;

    while (true) {
        step = 0;
        cout << "s = ";
        cin >> s;
        
        index = s.length(); 

        while (index > 1 ^ index == 2){        
            index = floor(index / 2); 
            n_index = s.length() - index;
            sub_string = s.substr(n_index, s.length());
            reversed = "";

            for (int i = sub_string.length()-1; i >= 0; i--){
                reversed += sub_string[i];
            }
            
            s = s.substr(0, n_index) + reversed;
            step += 1;
            cout << "Step " << step << " : " << s << endl;

            //if (index == 2) {
            //    break;
            //}
        }
    }
    return 0;
}