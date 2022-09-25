#pragma once

#include "shape.h"
#include "./iterator/dfs_compound_iterator.h"
#include "./iterator/bfs_compound_iterator.h"
#include <iterator>
#include <list>

class CompoundShape : public Shape
{
private:
    std::list<Shape*> _shapes;
public:
  CompoundShape(std::list<Shape*> *shapes) : _shapes(shapes){
    // When there's no shape contain in the compound shape, throw std::string "This is not a compound shape!"
    if( _shapes->size() == 0 ){
      throw std::string ("This is not a compound shape!");
    }
  }~CompoundShape() {}

    double area() const override {
      double sumOfArea = 0;
      std::list<Shape *>::iterator it;
      for( it = _shapes->begin(); it < _shapes->end(); it++ ){
      sumOfArea += (*it)->area();
      }
      return sumOfArea;
    }

    double perimeter() const override {
      double sumOfPerimeter = 0;
      std::list<Shape *>::iterator it;
      for( it = _shapes->begin(); it < _shapes->end(); it++ ){
        sumOfPerimeter += (*it)->perimeter();
      }
      return sumOfPerimeter;
    }

    std::string info() const override {
      std::string information = "CompoundShape (";
      std::list<Shape *>::iterator it;
      for( it = _shapes->begin(); it < _shapes->end(); it++ ){
        information += (*it)->info() + ", ";
      }
      information = information.substr( 0, information.length()-2 ) + ")";
      return information;
    }

    Iterator* createDFSIterator() override {}

    Iterator* createBFSIterator() override {}

    void addShape(Shape* shape) override { _shapes->push_back( shape ); }

    void deleteShape(Shape* shape) override {
      std::list<Shape *>::iterator it;
      for( it = _shapes->begin(); it < _shapes->end(); it++ )
      {
        if( *it == shape)
          _shapes -> erase(it);
      }
};
