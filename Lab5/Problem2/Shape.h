#ifndef SHAPE_H
#define SHAPE_H

// To create an abstract class,
// declare at least one pure virtual memebr function
// Abstract base class is not instantiated, but just a base for other classes

// To be overrided by a derived class Circle and Rectangle

class Shape {
    private:
        double area;

    public: 
        // Constructors
        Shape(); 
        Shape(double aArea); 
        ~Shape();
        // Get/set functions
        double getArea() const;
        void setArea(double area);

        // Virtual functions to be overridden
        virtual double calcArea() const = 0; 
        virtual void draw() const = 0;
};

#endif