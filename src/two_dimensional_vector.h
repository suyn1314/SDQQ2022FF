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
    TwoDimensionalVector(const Point *a, const Point *b) : _a(a) , _b(b) {}
    ~TwoDimensionalVector() {}

    const Point *a() const {return _a;}

    const Point *b() const {return _b;}

    double length() const {
      double ax = _a->x(), ay = _a->y(), bx = _b->x() ,by = _b->y();
      //向量長度公式:|v| = sqrt(x^2 + y^2)
      return sqrt((ax - bx)*(ax - bx)+(ay - by)*(ay - by));
    }

    double dot(const TwoDimensionalVector *vec) const {
      double v1ax = _a->x(), v1ay = _a->y(), v1bx = _b->x(), v1by = _b->y();
      double v2ax = vec->a()->x(), v2ay = vec->a()->y(), v2bx = vec->b()->x(), v2by = vec->b()->y();
      double v1AB_x = v1bx - v1ax,  v1AB_y = v1by - v1ay;
      double v2AB_x = v2bx - v2ax,  v2AB_y = v2by - v2ay;
      double _sideV1 = sqrt(  pow( v1AB_x, 2)  +  pow( v1AB_y, 2)  );
      double _sideV2 = sqrt(  pow( v2AB_x, 2)  +  pow( v2AB_y, 2)  );
      double cos = (v1AB_x * v2AB_x + v1AB_y * v2AB_y) / (_sideV1*_sideV2);
      //銳角的點積應該是正數
      if (cos > 0 ){return fabs(v1AB_x * v2AB_x + v1AB_y * v2AB_y);}
      return v1AB_x * v2AB_x + v1AB_y * v2AB_y;
    }

    double cross(const TwoDimensionalVector *vec) const {
      double v1ax = _a->x(), v1ay = _a->y(), v1bx = _b->x(), v1by = _b->y();
      double v2ax = vec->a()->x(), v2ay = vec->a()->y(), v2bx = vec->b()->x(), v2by = vec->b()->y();
      double v1AB_x = v1bx - v1ax,  v1AB_y = v1by - v1ay;
      double v2AB_x = v2bx - v2ax,  v2AB_y = v2by - v2ay;
      return v1AB_x * v2AB_y - v1AB_y * v2AB_x;
    }

    std::string info() const {
      return "Vector (" + _a->info() + ", " + _b->info() + ")";
    }
};
