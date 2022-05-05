#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
    private:
        int centerX; // x coord
        int centerY; // y coord
        double radius;
    public:
        // Constructors
        Circle();
        Circle(int aCenterX, int aCenterY, double aRadius);
        
        // Get functions
        int getCenterX() const;
        int getCenterY() const;
        double getRadius() const;

        // Set functions
        void setCenterX(int centerX);
        void setCenterY(int centerY);
        void setRadius(double radius);

        // Overridden virtual functions
        virtual double calcArea() const;
        void draw() const;
};

#endif