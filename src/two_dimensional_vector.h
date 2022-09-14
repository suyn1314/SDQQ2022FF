#pragma once

#include <cmath>
#include "point.h"

class TwoDimensionalVector
{
private:
    const Point *_a;
    const Point *_b;

public:
    TwoDimensionalVector(const Point *a, const Point *b) {}
    ~TwoDimensionalVector() {}

    const Point *a() const {
      return a;
    }

    const Point *b() const {
      return b;
    }

    double length() const {}

    double dot(const TwoDimensionalVector *vec) const {
      double *a1 = begin(a) , *a2 = end(a) , *b1 = begin (b) , *b2 = end(b);
      double result = (a1*b1) + (a2*b2);
      return result;
    }

    double cross(const TwoDimensionalVector *vec) const {
      double *a1 = begin(a) , *a2 = end(a) , *b1 = begin (b) , *b2 = end(b);
      duuble result = a1*b2+a2*b1
      return result
    }

    std::string info() const {}
};
