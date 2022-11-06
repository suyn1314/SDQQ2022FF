#pragma once
#include <algorithm>
#include <set>

#include "point.h"

class BoundingBox {
 private:
   Point *_max;
   Point *_min;

 public:
  BoundingBox(const std::set<const Point*>& points){
    if (points.empty()) { throw; }
    _max = calMaximumPoint(points);
    _min = calMinimumPoint(points);
  }
  const Point* max() { return _max; }

  const Point* min() { return _min; }

  Point* upper_right() const { return _max; }

  Point* lower_left() const { return _min; }

  bool collide(const BoundingBox* const box) const {
    auto right = box->lower_left()->x() > this->upper_right()->x();
    auto reft = box->upper_right()->x() < this->lower_left()->x();
    auto top = box->lower_left()->y() > this->upper_right()->y();
    auto end = box->upper_right()->y() < this->lower_left()->y();
    return !(right || reft || top || end);
  }

  Point *calMaximumPoint(const std::set<const Point *> points){
    auto it = points.begin();
    double maxX = (*it)->x(); 
    double maxY = (*it)->y();
    for (it++; it != points.end(); it++){
        double x = (*it)->x(); 
        maxX = ( x > maxX) ? x : maxX;
        double y = (*it)->y();
        maxY = ( y > maxY) ? y : maxY;
    }
    return new Point(maxX, maxY);
  }

  Point *calMinimumPoint(const std::set<const Point *> points){
    auto it = points.begin();
    double minX = (*it)->x(); 
    double minY = (*it)->y();
    for (it++; it != points.end(); it++){
        double x = (*it)->x();
        minX = (x < minX) ? x : minX;
        double y = (*it)->y();
        minY = (y < minY) ? y : minY;
    }
    return new Point(minX, minY);
  }

};
