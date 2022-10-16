#pragma once
#include <exception>
class Iterator;
class Shape{
public:
  virtual ~Shape() {}
  virtual std::string id() const = 0;
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual std::string info() const = 0;

  virtual Iterator* createDFSIterator() = 0;

  virtual Iterator* createBFSIterator() = 0;

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
