#include <iostream>

using namespace std;

void reverse(char s[]);
void concat(const char a[], const char b[], char result[], int result_maxlength);

int main(){

    // FUNCTION 1: reverse
    // change s[] to get varying outputs
    char s[] = "Hello, my name is Evan.";
    reverse(s);

    // FUNCTION 2: concat
    // change result_maxlength to get varying outputs
    int result_maxlength = 10;
    const char a[] = "chicken";
    const char b[] = "waffle";
    char result[result_maxlength]; // buffer result
    concat(a, b, result, result_maxlength); 

    return 0;
}

void reverse(char s[]){

    // create pointer to char
    char *ptr = s;
    int i = 0;
    int sizeOf = 0;

    // iterate through the address and checks if it returns an item
    bool isDone = false;
    while(isDone == false){
        if (*(ptr + i)) {
            sizeOf++; // still in the array
        } else {
            isDone = true; // not in the array, flag isDone
        }
        i++;
    }

    // define new string with new size
    char newStr[sizeOf];
    for (int i = 0; i <= sizeOf; i++){
        newStr[i] = (*(ptr + (sizeOf - i)));
        cout << newStr[i];
    }
    cout << endl;

}

void concat(const char a[], const char b[], char result[], int result_maxlength){

    // create pointer to constants
    const char *ptrA = a;
    const char *ptrB = b;

    // get the size of a -> add to new char array
    int i = 0;
    int sizeOfA = 0;
    bool isDone = false;
    while(isDone == false){
        if (*(ptrA + i)) {
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
        if (*(ptrB + i)) {
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