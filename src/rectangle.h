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
    Rectangle(TwoDimensionalVector *lengthVec, TwoDimensionalVector *widthVec) :_lengthVec(lengthVec) ,_widthVec(widthVec){

    }
    ~Rectangle() {}

    double length() const {
      return _lengthVec->length();
    }

    double width() const {
      return _widthVec->length();
    }

    double area() const override {

      return _lengthVec->cross(_widthVec);
    }

    double perimeter() const override {

      return 2*(length()+width());
    }

    std::string info() const override {
      return "Rectangle (" + _lengthVec->info() + ", " + _widthVec->info() + ")";
    }
};
