#pragma once

#include "shape.h"
#include "point.h"
#include "two_dimensional_vector.h"
#include "iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"
#include <cmath>

class Rectangle : public Shape
{
private:
    TwoDimensionalVector *_lengthVec;
    TwoDimensionalVector *_widthVec;
    std::string _id = "Rectangle";

    Point Vertex(const Point& commonB, const Point& uncommonA, const Point& uncommonC) const {
      //A + C - B
      double x = uncommonA.x() + uncommonC.x() - commonB.x();
      double y = uncommonA.y() + uncommonC.y() - commonB.y();
      return Point{x, y};
    }
public:
    Rectangle(TwoDimensionalVector *lengthVec, TwoDimensionalVector *widthVec) :_lengthVec(lengthVec) ,_widthVec(widthVec){
      //點積為0，為90度
      if (lengthVec->dot(widthVec) != 0){
        throw std::string("This is not a rectangle!");}
      if (!lengthVec->isConnected(widthVec)){
        throw std::string("This is not a rectangle!");
      }
    }~Rectangle() {}

    double length() const {
      return _lengthVec->length();
    }

    double width() const {
      return _widthVec->length();
    }

    double area() const override {return fabs(_lengthVec->cross(_widthVec));}

    double perimeter() const override {return 2*(length()+width());}

    std::string info() const override {return "Rectangle (" + _lengthVec->info() + ", " + _widthVec->info() + ")";}

    Iterator* createIterator(IteratorFactory *factory) override {return factory->createIterator();}

    void addShape(Shape* const shape) override {throw std::string("Could not AddShape!!");}

    void deleteShape(Shape* shape) override {throw std::string("Could not DeleteShape!!");}

    std::string id() const override {return _id;}

    void accept(ShapeVisitor* visitor) {visitor->visitRectangle(this);};

    std::set<const Point*> getPoints() override {
      const Point common = *FindCommonPoint(*_lengthVec, *_widthVec);
      const Point uncommon_length = *FindUncommonPoint(*_lengthVec, common);
      const Point uncommon_width = *FindUncommonPoint(*_widthVec, common);
      return {new Point{common}, new Point{uncommon_length}, new Point{uncommon_width}, new Point{Vertex(common, uncommon_length, uncommon_width)}};
    }
};
