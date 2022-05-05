#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape {
    private:
        int width;
        int height;
        int centerX;
        int centerY;
    public:
        // Constructors
        Rectangle();
        Rectangle(int aCenterX, int aCenterY, int aWidth, int aHeight);

        // Get functions
        int getWidth() const;
        int getHeight() const;
        int getCenterX() const;
        int getCenterY() const;

        // Set functions
        void setWidth(int width);
        void setHeight(int height);
        void setCenterX(int centerX);
        void setCenterY(int centerY);

        //overridden virtual functions
        virtual double calcArea() const;
        void draw() const;
};

#endif