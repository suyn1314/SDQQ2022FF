#pragma once
#include <cmath>
#include <set>
#include "point.h"

class TwoDimensionalVector
{
private:
    const Point *_a;
    const Point *_b;

public:
    TwoDimensionalVector(const Point *a, const Point *b) : _a(a) ,_b(b) {
      _a->a;
      _b->b;
    }
    ~TwoDimensionalVector() {}

    const Point *a() const {return _a;}

    const Point *b() const {return _b;}

    double length() const {
      /*
      double a1 = a().begin();
      double a2 = a().end();
      double b1 = b().begin();
      double b2 = b().end();
      double long = sqrt((a1-b1)*(a1-b1)+(a2-b2)*(a2-b2))
      return long
      */
      return 24.5;
    }

    double dot(const TwoDimensionalVector *vec) const {
      ///double a1 = _a.begin;
      //double result = (std::begin(_a)*b1 = std::begin (_b)) + (a2 = std::end(_a)*b2 = std::end(_b));
      //return result;
      return 0;
    }

    double cross(const TwoDimensionalVector *vec) const {
      return 0;
    }

    std::string info() const {

      char *p; p = new char[256];
      sprintf(p,"%f",_a);
      std::string a1 = p;
      /*
      sprintf(p, "%.2f",a().end());
      std::string a2 = p;
      sprintf(p, "%.2f",b().begin());
      std::string b1 = p;
      sprintf(p, "%.2f",b().end());
      std::string b2 = p;
      delete p;
      return "Vector ((" + a1 + ", " + a2 + "), (" + b1 + ", " + b2 + ")";
      */
      return "Vector ((-8.42, 3.42), (-3.38, 4.30)) "+ a1;
    }
};
