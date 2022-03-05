/* 
 * Answer to #2 on Lab2
 * CECS 275 - Spring 2022
 * @author Evan Nguyen
 * @author Joseph Guzman
 * @version 1.0.0
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// outputs the substring of the word, and its count
// works with upper and lowercase letters
// note: only checks 1 line at a time. check main to get more lines.
// APPROACH: create a sliding window, and then iterate through sub-windows
                /* ex: ababa 
                //     1. [aba]ba
                //          1.1 [a(ba]b)a <- keeps the master substring, then compares with the next substring
                            1.2 [ab(a]ba) <- duplicate! assign aba to the leader
                //     2. a[bab]a
                //          2.1 a[b(ab]a) <- if there is no leader, create a temporary leader and update it 
                            2.2 a[ba(b]a) <- detect the maximum index it can store
                //     3. ab([aba]) <- check the end index */

int main() {
    string word, temp, leader, newWord;
    // hold the current substr to be compared with the next
    // hold the next substr to be compared with current
    string thisSubstr, nextSubstr;
    // hold the current substr count
    int thisStart = 0, thisEnd = 0;
    // hold the next substr count
    int nextStart = 0, nextEnd = 0;
    int n = 3;
    int tempCount = 0;
    int leaderCount = 0;
    // create input stream and output streams to each file
    ifstream inputFile("input.txt");
    ofstream outputFile("result.txt");
    // while in the file, check each char in the word
    while (inputFile >> word) {
        for (char ch : word) {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                //get the word here                
                newWord = word;
                thisStart = 0;
                // create FIRST sliding window to nab THIS substring
                // master substring

                // reset leaders for each word
                leader = "";
                leaderCount = 0;
                while (thisEnd != newWord.length()) {
                    thisEnd = thisStart + 3;
                    // keep initial substring for comparison
                    thisSubstr = newWord.substr(thisStart, n);
                    //create SECOND sliding window to go thru the NEXT substrings and compare
                    nextStart = thisStart + 1;
                    // temp holder
                    temp = thisSubstr; 
                    // count thisSubstring
                    tempCount = 1;

                    while(nextEnd != newWord.length()) {
                        nextEnd = nextStart + 3;
                        // we started from 0 so we +1 it
                        if (nextEnd == newWord.length()+1){
                            /// when we reach the end, nexSubstr always == thisSubstr.
                            nextSubstr = thisSubstr;
                            //cout << "thisSubstr: " << thisSubstr << " nextSubstr: " << nextSubstr << endl;
                            // when we get to the last 3 substrings of a word, keep it. fix this.
                            break;
                        } else {
                            // secondary substring
                            nextSubstr = newWord.substr(nextStart, n);
                        }
                        nextStart++;
                        
                        // The next iterations will be compared.
                        // Leader will be held against temp leader. 
                        if (thisSubstr == nextSubstr) {
                            //cout << ">>> Found a duplicate!" << endl;
                            tempCount++;
                            //cout << "temp: " << temp << " tempCount: " << tempCount << endl;
                        }
                        // set the new leader
                        if (tempCount > leaderCount) {
                            leader = temp;
                            leaderCount = tempCount;
                        }
                    }
                    // when we reach the end, restart
                    if (nextEnd == newWord.length()){
                        nextEnd = nextStart + 3;
                    }
                    thisStart++;
                }
                // break after each line in file
                cout << "I found the secret message! In " << newWord << ", " << leader << " occurs " << leaderCount << " times!" << endl;
                outputFile << leader << endl;
                break;
            } else {
                // raise an exception when we dont find a letter
                cout << "SKIP: char is not a letter: " << ch << endl;
            }
        }
    }
    return 0;
}