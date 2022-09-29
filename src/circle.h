#pragma once

#include <string>
#include <cmath>
#include "two_dimensional_vector.h"
#include "shape.h"
#include "./iterator/null_iterator.h"

class Circle : public Shape
{
private:
    TwoDimensionalVector *_radiusVec;

public:
    Circle(TwoDimensionalVector *radiusVec) : _radiusVec(radiusVec) {}
    ~Circle() {}

    double radius() const {return _radiusVec->length();}

    double area() const override {return M_PI *radius()*radius();}

    double perimeter() const override {return 2*radius()*M_PI;}

    std::string info() const override {return "Circle (" + _radiusVec->info() + ")";}

    Iterator* createDFSIterator() override {return new NullIterator();}

    Iterator* createBFSIterator() override {return new NullIterator();}

    void addShape(Shape* shape) override {throw std::string("Cannot do addShape!");}

    void deleteShape(Shape* shape) override {throw std::string("Cannot do deleteShape!");}
};
