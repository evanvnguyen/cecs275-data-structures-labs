#include "Circle.h"
#include <cmath>
#include <iostream>

using namespace std;

const double PIE = 3.14;

Circle::Circle(){
    centerX = 0;
    centerY = 0;
    radius = 0.0;
}

Circle::Circle(int aCenterX, int aCenterY, double aRadius) {
    centerX = aCenterX;
    centerY = aCenterY;
    radius = aRadius;

}

int Circle::getCenterX() const {
    return centerX;
}

int Circle::getCenterY() const {
    return centerY;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setCenterX(int aCenterX){
    centerX = aCenterX;
}

void Circle::setCenterY(int aCenterY){
    centerY = aCenterY;
}

void Circle::setRadius(double aRadius){
    radius = aRadius;
}

//overridden virtual functions
double Circle::calcArea() const {
    double area = 0.0;
    return area = PIE * pow(radius, 2);
}


void Circle::draw() const {

    // graph size
    int x = 100;
    int y = 100;

    // threshold = approximation of the point on the function
    // set higher = thicker border
    // set lower = thinner border (might miss some points)
    int threshold = 5;
    // if radius = 10, set to 10


    int graph[x][y] = {0}; // clear the graph
    graph[centerX][centerY] = {1}; //origin

    // equation variables
    int op1 = 0;
    int op2 = 0;
    int calc = 0;

    // iterate through x and y of 2d
    // and see if it satisfies the equation
    // of a circle at the origin
    // x^2 + y^2 = r^2

    for (int y_i = 0; y_i < y; y_i++){
        for (int x_i = 0; x_i < x; x_i++){

            op1 = pow(abs(x_i - centerX), 2); // x^2
            op2 = pow(abs(y_i - centerY), 2); // y^2
            calc = abs(op1 + op2 - pow(radius, 2)); //x^2 + y^2 - r^2

            // EX: Checking the coordinates (10,10) where origin is (50,50):

            // (x-50)^2 = abs(10-50)^2 = 1600
            // (y-50)^2 = abs(10-50)^2 = 1600
            // assuming r = 5, r^2 = 25
            // if 1600 + 1600 - 25 <= 5? No, so don't plot it.

            // if x = 45, y = 50, 
            // x --> (45-50)^2 = abs(5)^2 = 25
            // y --> (50-50)^2 = abs(0)^2 = 0
            // assume r = 5, r^2 = 25
            // if 25 + 0 - 25 <= 5? Yes, plot it.

            if (calc <= threshold){
                graph[x_i][y_i] = 1;
            }
        }
    }

    // if the point on the graph is 1, plot an X
    // if the point on the graph is 0, plot a .

    // cut off the rest of the coordinates bc sparkles? lol
    for (int i = 0; i < 50; i++){
        for (int j = 0; j < 50; j++){
            if (graph[i][j] == 1){
                cout << "X ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }

}
