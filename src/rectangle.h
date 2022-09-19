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
      //點積為0，為90度
      if((_lengthVec->dot(_widthVec)!= 0) || (_widthVec->dot(_lengthVec)!= 0)){
        throw std::string("This is not a rectangle!");
      }
    }~Rectangle() {}

    double length() const {
      if (_lengthVec->length() <= 0 ){
        throw std::string("This is not a rectangle!"); }
      return _lengthVec->length();
    }

    double width() const {
      if (_widthVec->length() <= 0 ){
        throw std::string("This is not a rectangle!"); }
      return _widthVec->length();
    }

    double area() const override {

      return fabs(_lengthVec->cross(_widthVec));
    }

    double perimeter() const override {

      return 2*(length()+width());
    }

    std::string info() const override {
      return "Rectangle (" + _lengthVec->info() + ", " + _widthVec->info() + ")";
    }
};
