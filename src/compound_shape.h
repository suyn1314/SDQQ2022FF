#pragma once

#include "iterator/factory/iterator_factory.h"
#include "iterator/iterator.h"
#include "shape.h"
#include <list>

class CompoundShape : public Shape
{
private:
    std::list<Shape *> _shapes;
    std::string _id = "CompoundShape";

public:
    CompoundShape(Shape **shapes, int size) : _shapes(shapes, shapes + size){}~CompoundShape() {}
    CompoundShape(const std::list<Shape*>& shapes) : _shapes{shapes.begin(), shapes.end()} {}

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
      information.pop_back();
      information.pop_back();
      return "CompoundShape (" + information + ")";
    }

  Iterator* createIterator(IteratorFactory *factory) override {
    return factory->createIterator(_shapes.begin(),_shapes.end());
  }

   void addShape(Shape* const shape) override {_shapes.push_back(shape);}

   void deleteShape(Shape* shape) override {
      _shapes.remove(shape);
      for (auto shape_ptr : _shapes) {
        if (shape_ptr->id() == "CompoundShape") {
                shape_ptr->deleteShape(shape);
            }
      }
  }
   std::string id() const override {return _id;}

   void accept(ShapeVisitor* visitor) {visitor->visitCompoundShape(this);}

   std::set<const Point*> getPoints() override {
     //包含的所有形狀的所有頂點
     std::set<const Point*> points;
        for (auto shape : _shapes)
            for (auto point : shape->getPoints())
                points.insert(point);
        return points;
   }

};
