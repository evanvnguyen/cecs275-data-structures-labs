#include "Shape.h"

using namespace std;

Shape::Shape(){
    area = 0.0;
}

Shape::Shape(double aArea){
    area = aArea;
}

double Shape::getArea() const{
    return area;
}


void Shape::setArea(double aArea){
    area = aArea;
}

// pure virtual function
double Shape::calcArea() const{
    return 0.0;
}

void Shape::draw() const{

}

Shape::~Shape(){
    //cout << "Shape destroyed" << endl;
}