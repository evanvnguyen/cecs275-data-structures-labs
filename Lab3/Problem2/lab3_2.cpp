#include <iostream>

using namespace std;

void reverse(char s[]);
void concat(const char a[], const char b[], char result[], int result_maxlength);

int main(){

    // function 1: reverse
    char s[] = "Hello, my name is Evan.";
    reverse(s);

    // function 2: concat
    int result_maxlength = 5;
    const char a[] = "chicken";
    const char b[] = "waffle";
    char result[result_maxlength]; // buffer result
    concat(a, b, result, result_maxlength); 

    //for (int o = 0; o < result_maxlength; o++){
    //    cout << "result from main: "<< result[o];
    //}
    

    return 0;
}

void reverse(char s[]){
    int i = 0;
    int sizeOf = 0;

    // iterate through the address and checks if it returns an item
    bool isDone = false;
    while(isDone == false){
        if (*(s + i)) {
            sizeOf++; // still in the array
        } else {
            isDone = true; // not in the array, flag isDone
        }
        i++;
    }

    // create a dynamically allocated array to store the size
    // of the inputted string. add each string character 
    // starting from the last to reverse it.
    char *newStr = new char[sizeOf];
    for (int i = 0; i <= sizeOf; i++){
        newStr[i] = (*(s + (sizeOf - i)));
        cout << newStr[i];
    }
    cout << endl;

    delete [] newStr;
    newStr = nullptr;
}

void concat(const char a[], const char b[], char result[], int result_maxlength){

    // get the size of a -> add to new char array
    int i;
    bool isDone;

    i = 0;
    int sizeOfA = 0;
    isDone = false;
    
    while(isDone == false){
        if (*(a + i)) {
            sizeOfA++; // still in the array
        } else {
            isDone = true; // not in the array, flag isDone
        }
        i++;
    }

    // get the size of b -> add to new char array. reset flags
    i = 0;
    int sizeOfB = 0;
    isDone = false;
    while(isDone == false){
        if (*(b + i)) {
            sizeOfB++; // still in the array
        } else {
            isDone = true; // not in the array, flag isDone
        }
        i++;
    }

    char buffer[sizeOfA + sizeOfB];
    char *ptr = buffer; // pointer to buffer

    for (int j = 0; j <= sizeOfA-1; j++){ // add array a via dereference. -1 to remove null character
        *ptr++ = a[j];
    }
    for (int k = 0; k <= sizeOfB; k++){ // add array b via dereference
        *ptr++ = b[k];
    }

    // output it based on the result_maxlength
    for (int o = 0; o < result_maxlength; o++){
        cout << buffer[o];
    }
    cout << endl;
}