/*
 * Answer to #1 on Lab 3 
 * CECS 275 - Spring 2022 
 * @author Joseph Guzman 
 * @author Evan Nguyen 
 * @version 1.0.0 
 *
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// vector<int> read_data - takes read_data.txt as an argument and returns the data as a vector<int>
// vector<int> sort_data - takes a vector<int> and int vecSize as argument, sorts it, returns new sorted vector<int>
// int max - takes a sorted vector<int> as an argument and returns the maximum value
// int min - takes a sorted vector<int> as an argument and returns the minimum value
// float avg - takes a vector<int> as an argument and returns the average
// vector<int> outToFile - takes sorted vector<int>, int min, int max, float avg and outputs to file
// void swap - takes reference arguments a & b and swaps them. use for sorting

vector<int> read_data(string inputFile);
vector<int> sort_data(vector<int> rawData, int vecSize);
vector<int> outToFile(vector<int> sortedData, int minValue, int maxValue, float avg);
int max_val(vector<int> sortedData);
int min_val(vector<int> sortedData);
float avg(vector<int> sortedData, int vecSize);
void swap(int &a, int&b);

int main(){
    
    string file = "data.txt";
    int vecSize = 0;
    
    vector<int> rawData = read_data(file);

    // get the vector size to use in other functions
    for (int h : rawData){
        vecSize++;
    }

    vector<int> sortedData = sort_data(rawData, vecSize);
    
    int minValue = min_val(sortedData);
    int maxValue = max_val(sortedData);
    
    float avgValue = avg(sortedData, vecSize);
    outToFile(sortedData, minValue, maxValue, avgValue);
    
    return 0;
}

// swap function for sorting
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<int> read_data(string inputFile) {
    vector<int> number_List;
    string word, temp_Word;
    int temp_Num, int1, newInt, store;
    int temp = 0;

    ifstream inFile;
    inFile.open(inputFile);
    
    if (!inFile){
        cout << "File Not Found!" << endl;
    }
    else{
        cout << "File Found!" << endl;
    }
    //int i = 0;
    while(inFile >> word){
        //For loop that removes commas from the string
        for (int i = 0; i < word.length(); i++){
            if (word[i] == ',')
            {
                word[i] = ' ';
            }
            temp_Word += word[i]; // temp_Word holds our number list with spaces instead of commas
        }
    }

    cout << temp_Word;


    // convert the word to ascii, modulus by 10 and get the integer value. pushback into vector
    for (int i = 0; i < temp_Word.length(); i++){
        if (temp_Word[i] != ' ') { // ignore space
            int1 = (temp_Word[i] - '0') % 10; 
            temp *= 10;
            newInt = int1 + temp;
            //cout << "newInt: " << newInt << endl;
            temp = int1;
        } 
        else {
            store = newInt;
            number_List.push_back(store);
            //cout << "store: " << store << endl;
            int1 = 0;
            temp = 0;
        }
    }
    store = newInt;
    number_List.push_back(store);

    //cout << "store at end: " << store << endl;
    
    for (int i : number_List){
        cout << i << " ";
    }
    return number_List;
}

// sorts rawData and returns a sorted vector
vector<int> sort_data(vector<int> rawData, int vecSize){
    int minIndex, minValue;

    // selection sort
    for (int start = 0; start < (vecSize-1); start++){
        minIndex = start;
        minValue = rawData[start];
        for(int index = start + 1; index < vecSize; index++){
            if (rawData[index] < minValue){
                minValue = rawData[index];
                minIndex = index;
            }
        }
        swap(rawData[minIndex], rawData[start]);
    }  

    // check if array sorted
    cout << endl << endl << "Sorted from Min to Max" << endl;   
    for (int j : rawData){
        cout << j << " ";
    }
    cout << endl;

    return rawData;
}

// min value is the first element in a sorted vector
int min_val(vector<int> sortedData){

    cout << "\nSorted Data Min Value: " << sortedData[0] << endl;

    return sortedData[0];
}

// max value is the last element in a sorted vector
int max_val(vector<int> sortedData){

    cout << "\nSorted Data Max Value: " << sortedData[sortedData.size()-1] << endl;

    return sortedData[sortedData.size()-1];
}

// compute the average of the vector
float avg(vector<int> sortedData, int vecSize){
    double sum = 0.0;
    double average_2pt = 0.0;

    for (int i : sortedData){
        sum += i;
    }

    // round to 2 decimal points
    average_2pt = ceil((sum / vecSize) * 100.0) / 100.0;
    return average_2pt;
}

// output to file 
vector<int>outToFile(vector<int> sortedData, int min, int max, float avg){
    vector<int> count;
    vector<int> unique;
    int value;
    int freq = 0;
    int unique_Val;
    int range = sortedData.size();
    int numS = 0;
    cout << '\n';

    ofstream outputFile("frequency.txt");
    for (int i = 0; i < range; i++){
        unique_Val = sortedData[i];
        unique.push_back(unique_Val); // store unique values
        int j = 0;
        
        //cout << unique_Val;

        outputFile << unique_Val;
        // check unique values and determine if the next value is == to it.
        while (sortedData[i+j]==unique_Val){
            //cout << "sortedData[" << i << "+" << j << "]: " << sortedData[i+j] << " unique_Val: " << unique_Val << endl;
            j++;
            freq++;
            //cout << "Unique_Val: " << unique_Val << "Frequency: " << freq << endl;
        }

        //cout << ":";
        outputFile << ":";
        
        // append *'s
        for (int i=0; i < freq; i++){
            if (freq != 0){
                //cout <<"*";
                numS++;
                outputFile << "*";
            }
            else {
                break;
            }
        }

        // set teh width to accomodate 2 digit numbers
        if (unique_Val < 10) {
            //cout << setw(9-numS);
            outputFile << setw(9-numS);
        } else {
            //cout << setw(8-numS);
            outputFile << setw(8-numS);
        }

        //cout << "(" << freq << ")" << endl;
        outputFile << " " << "(" << freq << ")" << endl;

        if (sortedData[i+j]!= unique_Val){
            i = i+j-1;
        }

        for (int c = 0; c < unique.size(); c++){
            if (((unique[c] + 1) != unique[c+1]))
                if (unique[c] + 1 > unique_Val && ((unique[c] + 1) < sortedData[i+1]))
                    //cout << unique[c] + 1 << ":       (0)" << endl;
                    outputFile << unique[c] + 1 << ":        (0)" << endl;
                    //cout << unique[c] + 1 << ":        (0)" << endl;
        }

        numS = 0;
        freq = 0;

    }

    outputFile << "The maximum is " << max << "." << endl;  
    outputFile << "The minimum is " << min << "." << endl;
    outputFile << "The average is " << avg <<". (Format with 2 decimal places)";
    outputFile.close();
}
   