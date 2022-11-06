#pragma once

#include "shape.h"
#include "point.h"
#include "two_dimensional_vector.h"
#include "iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"
#include <cmath>

class Circle : public Shape
{
private:
    TwoDimensionalVector *_radiusVec;
    std::string _id = "Circle";

public:
    Circle(TwoDimensionalVector *radiusVec) : _radiusVec(radiusVec) {}
    ~Circle() {}

    double radius() const {return _radiusVec->length();}

    double area() const override {return M_PI *radius()*radius();}

    double perimeter() const override {return 2*radius()*M_PI;}

    std::string info() const override {return "Circle (" + _radiusVec->info() + ")";}

    Iterator* createIterator(IteratorFactory *factory) override {return factory->createIterator();}

    void addShape(Shape* const shape) override {throw std::string("Could not AddShape!!");}

    void deleteShape(Shape* shape) override {throw std::string("Could not DeleteShape!!");}

    std::string id() const override {return _id;}

    void accept(ShapeVisitor* visitor) {visitor->visitCircle(this);};

    std::set<const Point*> getPoints() override {
      std::set<const Point*> _getPoints;
      double centerX = _radiusVec->a()->x(), centerY = _radiusVec->a()->y();
      _getPoints.insert(new Point(centerX + this->radius(), centerY + this->radius()));
      _getPoints.insert(new Point(centerX - this->radius(), centerY - this->radius()));
      return _getPoints;
    };

};
