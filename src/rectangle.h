<<<<<<< HEAD
#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector *_lengthVec;
    TwoDimensionalVector *_widthVec;
    std::string _id = "Rectangle";
public:
    Rectangle(TwoDimensionalVector *lengthVec, TwoDimensionalVector *widthVec) :_lengthVec(lengthVec) ,_widthVec(widthVec){
      //點積為0，為90度
      if((_lengthVec->dot(_widthVec)!= 0) || (_widthVec->dot(_lengthVec)!= 0)){
        throw std::string("This is not a rectangle!");}
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

    double area() const override {return fabs(_lengthVec->cross(_widthVec));}

    double perimeter() const override {return 2*(length()+width());}

    std::string info() const override {return "Rectangle (" + _lengthVec->info() + ", " + _widthVec->info() + ")";}

    Iterator* createDFSIterator() override {return new NullIterator();}

    Iterator* createBFSIterator() override {return new NullIterator();}

    std::string id() const override {return _id;}

};
=======
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
        throw std::string("This is not a rectangle!");}
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

    double area() const override {return fabs(_lengthVec->cross(_widthVec));}

    double perimeter() const override {return 2*(length()+width());}

    std::string info() const override {
      return "Rectangle (" + _lengthVec->info() + ", " + _widthVec->info() + ")";
    }
};
>>>>>>> 4320853380c6c07fe14597066a913f8c25f4735f
