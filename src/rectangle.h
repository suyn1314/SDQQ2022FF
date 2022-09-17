#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector *_lengthVec;
    TwoDimensionalVector *_widthVec;

public:
    Rectangle(TwoDimensionalVector *lengthVec, TwoDimensionalVector *widthVec) :_lengthVec(lengthVec) ,_widthVec(widthVec){}
    ~Rectangle() {}

    double length() const {
      return 0;
    }

    double width() const {
      return 0;
    }

    double area() const override {
      return 0;
    }

    double perimeter() const override {
      return 0;
    }

    std::string info() const override {
      return "Rectangle  (" + _lengthVec->info() + ", " + _widthVec->info() + ")";
    }
};
