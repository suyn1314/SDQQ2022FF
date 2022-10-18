<<<<<<< HEAD
#pragma once

#include "shape.h"
#include "two_dimensional_vector.h"
#include "./iterator/null_iterator.h"
#include <cmath>

class Circle : public Shape
{
private:
    TwoDimensionalVector *_radiusVec;
    std::string _id = "Circle";
public:
    Circle(TwoDimensionalVector *radiusVec) : _radiusVec(radiusVec) {}
    ~Circle() {}

    double radius() const {return _radiusVec->length();}

    double area() const override {return M_PI *radius()*radius();}

    double perimeter() const override {return 2*radius()*M_PI;}

    std::string info() const override {return "Circle (" + _radiusVec->info() + ")";}

    Iterator* createDFSIterator() override {return new NullIterator();}

    Iterator* createBFSIterator() override {return new NullIterator();}

    std::string id() const override {return _id;}

};
=======
#pragma once

#include <string>
#include <cmath>
#include "two_dimensional_vector.h"
#include "shape.h"

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
};
>>>>>>> 4320853380c6c07fe14597066a913f8c25f4735f
