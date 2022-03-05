#include <iostream>
#include <vector>
#include <fstream>

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
vector<int> sort_data(vector<int> rawData);
vector<int> frequency(vector<int> sortedData);

int max_val(vector<int> sortedData);
int min_val(vector<int> sortedData);
float avg(vector<int> sortedData);

void output_file(vector<int> frequencyData, int maxValue, int minValue, float avgValue);
void swap(int &a, int&b);

int main(){
    string file = "data.txt";

    vector<int> rawData = read_data(file);
    vector<int> sortedData = sort_data(rawData);
    vector<int> frequencyData = frequency(sortedData);

    int maxValue = max_val(sortedData);
    int minValue = min_val(sortedData);
    
    float avgValue = avg(sortedData);
    
    output_file(frequencyData, maxValue, minValue, avgValue);

    //DEBUG
    //read_data(file);
    return 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<int> read_data(string inputFile) {

    string word;
    string tempWord;
    vector<string> temp;
    ifstream inFile;
    inFile.open(inputFile);

    if (inFile){
        cout << "open success!";
    }

    //int i = 0;
    while(inFile >> word){
        for (int j = 0; j < word.length(); j++){
            cout << word[j-1] << endl;
        }
        //temp.push_back(word);
        //cout << temp[i] << endl;
        //i++;
    }

}