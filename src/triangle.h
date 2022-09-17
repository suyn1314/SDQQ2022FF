#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector *_v1;
    TwoDimensionalVector *_v2;

public:
    Triangle(TwoDimensionalVector *v1, TwoDimensionalVector *v2) : _v1(v1), _v2(v2){}
    ~Triangle() {}

    double area() const override {
      return 0;
    }

    double perimeter() const override {
      return 0;
    }

    std::string info() const override {
      return 0;
    }
};
