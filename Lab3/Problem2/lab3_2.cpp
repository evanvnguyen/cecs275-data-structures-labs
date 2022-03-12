#include <iostream>

using namespace std;

void reverse(char s[]);
void concat(const char a[], const char b[], char result[], int result_maxlength);

int main(){
    cout << "\n*******************TESTING***********************\n";
    // FUNCTION 1: reverse
    // change s[] to get varying outputs
    cout << "FUNCTION 1: reverse \n";
    char s[] = "Hello, I am Evan.";
    reverse(s);

    cout << "-------------------------------------------------\n";

    // FUNCTION 2: concat
    // result_maxlength = 5. starting max_length
    // max length 10 and 20 are outputted, as seein in the sample run
    cout << "FUNCTION 2: concat \n";
    int result_maxlength = 5;
    const char a[] = "chicken";
    const char b[] = "waffle";
    char result[result_maxlength]; // buffer result
    concat(a, b, result, result_maxlength); 
    cout << "\n*************************************************\n\n";
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
        if (ptr[i]) {
            sizeOf++; // still in the array
        } else {
            isDone = true; // not in the array, flag isDone
        }
        i++;
    }

    // I think its better to point rather than access directly,
    // hence why i created char *ptr = s rather than
    // doing *(s + 1) and so forth.
    cout << "\"";
    for (int i = 0; i <= sizeOf; i++){
        cout << ptr[i];
    } 
    cout << "\"";
    cout << " becomes ";
    cout <<"\"";

    // define new string with new size
    char newStr[sizeOf];
    for (int i = 0; i <= sizeOf; i++){
        newStr[i] = ptr[sizeOf - i];
        cout << newStr[i];
    }
    cout <<"\".";
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
        if (ptrA[i]) {
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
        if (ptrB[i]) {
            sizeOfB++; // still in the array
        } else {
            isDone = true; // not in the array, flag isDone
        }
        i++;
    }

    int sizeBoth = sizeOfA + sizeOfB;
    char buffer[sizeBoth];
    char *ptr = buffer; // pointer to buffer

    // add array a and b via dereference. -1 to remove null character
    for (int j = 0; j <= sizeOfA-1; j++){ 
        *ptr++ = a[j];
    }
    for (int k = 0; k <= sizeOfB-1; k++){ 
        *ptr++ = b[k];
    }

    // point to original char a[] and char[b]
    cout << "If char a[] = \"";
    for (int i = 0; i <= sizeOfA; i++){
        cout << ptrA[i];
    }

    cout << "\" and char b[] = \"";
    for (int i = 0; i <= sizeOfB; i++){
        cout << ptrB[i];
    }    

    // -Output the buffer
    // If result_maxlength is greater than sizeBoth,
    // just output the entire string. Ignore extraneous characters.
    // Accessing out of bound array elements results in weird characters
    cout << "\"\nthen:";

    // this code block creates  test
    // cases as seen in the sample run.
    int *ptrR = &result_maxlength;
    int testCase = 0;
    while (testCase != 3){

        int outLength = *ptrR;
        if (*ptrR > sizeBoth){
            outLength = sizeBoth;
        }

        cout << "\nmax_length = " << *ptrR << " ---> \"";
        for (int o = 0; o < outLength; o++){
            cout << buffer[o];
            // point to result and change it based on these conditions
        }

        cout << "\"";
        *ptrR *= 2;
        testCase++;
    }
}
