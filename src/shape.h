#pragma once

#include "point.h"
#include "iterator/factory/iterator_factory.h"
#include "iterator/iterator.h"
#include "visitor/shape_visitor.h"
#include <stdexcept>
#include <exception>
#include <set>
#include <string>

//<Interface>
class Shape{
public:
  virtual ~Shape() {}
  virtual void accept(ShapeVisitor* visitor) = 0;
  virtual std::set<const Point*> getPoints() = 0;
  virtual Iterator* createIterator(IteratorFactory * factory) = 0;

  virtual std::string id() const = 0;
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual std::string info() const = 0;

  virtual void addShape(Shape* shape) {
      throw ShapeException{"Could not AddShape!!"};
    }
  virtual void deleteShape(Shape* shape) {
      throw ShapeException{"Could not DeleteShape!!"};
    }

  class ShapeException : public std::runtime_error {
      using std::runtime_error::runtime_error;
    };
 };
