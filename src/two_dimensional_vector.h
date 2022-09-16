#pragma once
#include <cmath>
#include <set>
#include "point.h"

class TwoDimensionalVector
{
private:
    //指標變數_a指向函數Point
    const Point *_a;
    const Point *_b;

public:
    TwoDimensionalVector(const Point *a, const Point *b) : _a(a) , _b(b) {}
    ~TwoDimensionalVector() {}
    //指標函數a回傳指標變數_a
    const Point *a() const {return _a;}

    const Point *b() const {return _b;}

    double length() const {
      double ax = _a->x();
      double ay = _a->y();
      double bx = _b->x();
      double by = _b->y();
      //向量長度公式:|v| = sqrt(x^2 + y^2)
      return sqrt((ax - bx)*(ax - bx)+(ay - by)*(ay - by));
    }

    double dot(const TwoDimensionalVector *vec) const {
      double ax = _a->x();
      double ay = _a->y();
      double bx = _b->x();
      double by = _b->y();
      //內積運算 : a . b = x1*x2 + y1*y2
      return ax * ay + bx * by;
    }

    double cross(const TwoDimensionalVector *vec) const {
      double ax = _a->x();
      double ay = _a->y();
      double bx = _b->x();
      double by = _b->y();
      //外積運算 : a x b = x1*y2 - x2*y1
      return ax * by - ay * bx;
    }

    std::string info() const {
      char *p; p = new char[256];
      sprintf( p,"%.2f", _a->x());std::string ax = p;
      sprintf( p,"%.2f", _a->y());std::string ay = p;
      sprintf( p,"%.2f", _b->x());std::string bx = p;
      sprintf( p,"%.2f", _b->y());std::string by = p;
      delete p;
      return "Vector ((" + ax + ", " + ay + "), (" + bx + ", "+ by + "))";
    }
};
