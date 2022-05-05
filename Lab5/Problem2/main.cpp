/*
 * Answer to #2 on Lab 5
 * CECS 275 - Spring 2022 
 * @author Evan Nguyen  
 * @author Joseph Guzman
 * @version 1.0.0 
 *
 */

#include <iostream>
#include <stdlib.h>

#include "Shape.h"
#include "Shape.cpp"
#include "Circle.h"
#include "Circle.cpp"
#include "Rectangle.h"
#include "Rectangle.cpp"

using namespace std;

int main() {
    
    int userInput;

    int centerX;
    int centerY;
    
    int circRadius;
    int rectH;
    int rectW;

    while(true){  
        cout << "Lab5 Problem 2: Circle/Rectangle Drawer" << endl;
        cout << "Press 1 to draw a Circle" << endl;
        cout << "Press 2 to draw a Rectangle" << endl;
        cout << "Press 3 to quit" << endl;
        cin >> userInput;
        // randomized seed
        int centerX = rand() % 25 + 10;
        int centerY = rand() % 25 + 10;
        if (userInput == 1) {
            cout << "-------------------Enter circle radius---------------\n";
            cout << "----------------Origin is set to (25,25)-------------\n";
            cout << "-------------Since the graph size is 50x50-----------\n";
            cout << "\nEnter circle radius: ";
            cin >> circRadius;

            Circle Circ(centerX, centerY, circRadius);
            //cout << "Circle Area: " << Circ.calcArea() << endl;
            Circ.draw();
        } else if (userInput == 2) {
            cout << "-------------------Enter Height/Width----------------\n";
            cout << "----------------Origin is set to (25,25)-------------\n";
            cout << "-------------Since the graph size is 50x50-----------\n";
            cout << "\nEnter height: ";
            cin >> rectH;
            cout << "\nEnter width: ";
            cin >> rectW;

            Rectangle Rect(centerX, centerY, rectW, rectH);
            //cout << "Rectangle Area: " << Rect.calcArea() << endl;
            Rect.draw();
        } else if (userInput == 3){
            return 0;
        }

    }
    return 0;
}