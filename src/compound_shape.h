#pragma once

#include "shape.h"
#include "./iterator/dfs_compound_iterator.h"
#include "./iterator/bfs_compound_iterator.h"

#include <list>

class CompoundShape : public Shape
{
private:
    std::list<Shape *> _shapes;

public:
    CompoundShape(Shape **shapes, int size) : _shapes(shapes, shapes + size){

    }~CompoundShape() {}

    double area() const override {
      double result = 0;
      for (auto shape_ptr : _shapes) {
          result += shape_ptr->area();
      }
      return result;
    }

    double perimeter() const override {
      double result = 0;
      for (auto shape_ptr : _shapes) {
          result += shape_ptr->perimeter();
      }
      return result;
    }

    std::string info() const override {
      auto information = std::string{};
      for (const auto& shape : _shapes) {
        information += shape->info() + ", ";
      }
      /* remove the last ", " */
      information.pop_back();
      information.pop_back();
      return "CompoundShape (" + information + ")";
    }

//    Iterator* createDFSIterator() override {return 0;}

//    Iterator* createBFSIterator() override {return 0;}

//    void addShape(Shape* shape) override {}

//    void deleteShape(Shape* shape) override {}
};
