#pragma once

#include <cmath>

class Point
{
private:
     const double _x;
     const double _y;

public:
    Point(double x, double y) : _x(x), _y(y){}
    ~Point() {}

    double x() const {return _x;}

    double y() const {return _y;}

    bool operator==(const Point &pt) const {
      return (this->_x == pt._x) && (this->_y == pt._y);
    }

    std::string info() const{
      char *p; p = new char[256];
      sprintf(p, "%.2f",_x);
      std::string a = p;
      sprintf(p, "%.2f",_y);
      std::string b = p;
      delete p;
      return "(" + a + ", " + b + ")";}
};
