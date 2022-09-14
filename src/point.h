#pragma once

#include <cmath>

class Point
{
private:
    const double _x;
    const double _y;

public:
    Point(double x, double y) {
      this -> x = _x ;
      this -> y = _y ;
    }
    ~Point() {}

    double x() const {
      return _x
    }

    double y() const {
      return _y
    }

    bool operator==(const Point &pt) const {
      if( _x == pt._x && _y == pt._y)
        ruturn true;
      return false;
    }

    std::string info() const {
      char *p; p = new char[256];
      sprintf(p, "%.3f",_x);
      std::string a = p;
      sprintf(p, "%.3f",_y);
      std::string b = p;
      delete p;
      return "(" ＋ a + "," + b + ")";
    }
};
