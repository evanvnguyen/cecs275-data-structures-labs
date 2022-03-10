#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// vector<int> read_data - takes read_data.txt as an argument and returns the data as a vector<int>
// vector<int> sort_data - takes a vector<int> as an argument and sorts it, returns a new sorted vector<int>
// int max - takes a sorted vector<int> as an argument and returns the maximum value
// int min - takes a sorted vector<int> as an argument and returns the minimum value
// float avg - takes a vector<int> as an argument and returns the average
// vector<int> frequency - takes a sorted vector<int> as an argument and returns a vector that contains the count of a number connected via subscript (i.e., #1 = vector[0], where vector[0] contains 3. #1's frequency is 3.). parallel array
// void output_file - takes frequency vector<int>, min, max, and avg as an argument and outputs formatted data into frequency.txt
// void swap - takes reference arguments a & b and swaps them. use for sorting

vector<int> read_data(string inputFile);
vector<int> sort_data(vector<int> rawData, int vecSize);
vector<int> frequency(vector<int> sortedData);

int max_val(vector<int> sortedData);
int min_val(vector<int> sortedData);
float avg(vector<int> sortedData, int vecSize);

void output_file(vector<int> frequencyData, int maxValue, int minValue, float avgValue);
void swap(int &a, int&b);

int main(){
    
    string file = "data.txt";
    int vecSize = 0;

    vector<int> rawData = read_data(file);

    //TEST VECTOR
    //vector<int> rawData = {1, 65, 2, 63, 643, 42, 11, 33, 55}; 

    // get the vector size to use in other functions
    for (int h : rawData){
        vecSize++;
    }

    vector<int> sortedData = sort_data(rawData, vecSize);
    //vector<int> frequencyData = frequency(sortedData);

    int minValue = min_val(sortedData);
    int maxValue = max_val(sortedData);
    
    float avgValue = avg(sortedData, vecSize);
    
    //output_file(frequencyData, maxValue, minValue, avgValue);

    //DEBUG
    //read_data(file);
    return 0;
}

// swap function for sorting
void swap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;

}
void convert(char num_Temp){
    char d = num_Temp;
    string y = "";
    y += d;
    int num_Converted;
    num_Converted = stoi(y);
    cout << num_Converted;
}

vector<int> read_data(string inputFile) {
    string word;
    ifstream inFile;
    inFile.open(inputFile);
    if (inFile){
        cout << "Open success!" << endl;
    }
    //int i = 0;
    while(inFile >> word){
        for (int j = 0; j < word.length(); j++){
            if (word[j]==','){
                word.erase(j);
                cout << " ";
            }
            else{
            convert(word[j]);
            }

        //temp.push_back(word);
        //cout << temp[i] << endl;
        //i++;
        }
    }
}

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
    for (int j : rawData){
        cout << j << endl;
    }

    return rawData;
}

// min value is the first element in a sorted vector
int min_val(vector<int> sortedData){

    cout << "Sorted Data Min Value: " << sortedData[0] << endl;

    return sortedData[0];
}

// max value is the last element in a sorted vector
int max_val(vector<int> sortedData){

    cout << "Sorted Data Max Value: " << sortedData[sortedData.size()-1] << endl;

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
    //cout << "avg " << average_2pt << endl;
    return average_2pt;
}