#include "Rectangle.h"
#include <cmath>
#include <iostream>

using namespace std;

Rectangle::Rectangle(){
    width = 0;
    height = 0;
    centerX = 0;
    centerY = 0;
}

Rectangle::Rectangle(int aCenterX, int aCenterY, int aWidth, int aHeight){
    centerX = aCenterX;
    centerY = aCenterY;
    width = aWidth;
    height = aHeight;

}

int Rectangle::getWidth() const {
    return width;
}  

int Rectangle::getHeight() const {
    return height;
}

int Rectangle::getCenterX() const {
    return centerX;
}

int Rectangle::getCenterY() const {
    return centerY;
}

void Rectangle::setWidth(int aWidth){
    width = aWidth;
}

void Rectangle::setHeight(int aHeight){
    height = aHeight;
}

void Rectangle::setCenterX(int aCenterX){
    centerX = aCenterX;
}

void Rectangle::setCenterY(int aCenterY){
    centerY = aCenterY;
}

//overridden virtual functions
double Rectangle::calcArea() const{
    int area = 0;
    return area = width * height;
}

void Rectangle::draw() const{
    // graph size
    int x = 100;
    int y = 100;
    
    // threshold = approximation of the point on the function
    // set higher = thicker border
    // set lower = thinner border (might miss some points)
    int threshold = 5;
    // if radius = 10, set to 10

    int graph[x][y] = {0}; // clear the graph
    graph[centerX][centerY] = {1}; // set the origin


    // iterate through the points
    // bia creating the corners first

    for (int x_i = 0; x_i <= width; x_i++){
        graph[centerX-height/2][centerY-width/2 + x_i] = {1};
        graph[centerX+height/2][centerY-width/2 + x_i] = {1};
    }

    for (int y_i = height; y_i >= 0; y_i--){
        graph[centerX-height/2 + y_i][centerY+width/2] = {1}; // Top right
        graph[centerX+height/2 - y_i][centerY-width/2] = {1}; // Bottom right
    }

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

    graph[x][y] = {0}; // clear the graph, doesnt work? use delete [] graph

}
