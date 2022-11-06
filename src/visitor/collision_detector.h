#pragma once

#include "shape_visitor.h"
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include "../bounding_box.h"
#include "../iterator/factory/bfs_iterator_factory.h"
#include <vector>

class CollisionDetector : public ShapeVisitor
{
private:
    std::vector<Shape *> _collideResult;
    BoundingBox _boundingBox;

public:
    CollisionDetector(Shape *shape) : _boundingBox{shape->getPoints()} {}

    void visitCircle(Circle *circle) override {
      if (circle->id() == "Circle"){VisitSimpleShape(circle);}
    }

    void visitTriangle(Triangle *triangle) override {
      if (triangle->id() == "Triangle"){VisitSimpleShape(triangle);}
    }

    void visitRectangle(Rectangle *rectangle) override {
      if (rectangle->id() == "Rectangle"){VisitSimpleShape(rectangle);}
    }

    void visitCompoundShape(CompoundShape *compoundShape) override {
      if (compoundShape->id() == "CompoundShape"){
        auto boundingBoxDetect = BoundingBox{compoundShape->getPoints()};
        if (_boundingBox.collide(&boundingBoxDetect)) {
          auto factory = ListIteratorFactory{};
          for (auto it = compoundShape->createIterator(&factory); !it->isDone(); it->next()) {
            it->currentItem()->accept(this);
          }
        }
      }
    }

    void VisitSimpleShape(Shape* shape) {
    auto boundingBoxDetect = BoundingBox{shape->getPoints()};
    if (_boundingBox.collide(&boundingBoxDetect)) {
      _collideResult.push_back(shape);
    }
  }

    std::vector<Shape *> collidedShapes() const {return _collideResult;}
};
