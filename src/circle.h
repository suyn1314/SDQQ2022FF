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

    double radius() const {
      return 0;
    }

    double area() const override {
      return 0;
    }

    double perimeter() const override {
      return 0;
    }

    std::string info() const override {
      return "Circle (" + _radiusVec->info() + ")";
    }
};
