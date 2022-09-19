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
      return _radiusVec->length();
    }

    double area() const override {
      double  value = M_PI *radius()*radius();
      float result = round(value * 100) / 100;
      return M_PI *radius()*radius();
    }

    double perimeter() const override {
      double  value = 2*radius()*M_PI;
      float result = round(value * 100) / 100;
      return 2*radius()*M_PI;
    }

    std::string info() const override {
      return "Circle (" + _radiusVec->info() + ")";
    }
};
