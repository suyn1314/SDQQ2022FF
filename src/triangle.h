#pragma once
#include "shape.h"
#include "two_dimensional_vector.h"
#include "iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector *_v1;
    TwoDimensionalVector *_v2;
    double ax, ay, bx, by, cx, cy;
    double _sideAB, _sideAC, _sideBC;
    double vAB_x,vAB_y,vAC_x,vAC_y,vBC_x,vBC_y;
    std::string _id = "Triangle";

public:
    Triangle(TwoDimensionalVector *v1, TwoDimensionalVector *v2) : _v1(v1), _v2(v2){
        //兩個向量的叉積等於零，則它們平行
        if ((_v1->cross(_v2) == 0) || (_v2->cross(_v1) == 0)){
          throw std::string("This is not a triangle!");
        }
        if (!v1->isConnected(v2)){
          throw std::string("This is not a triangle!");
        }
        //三角形的兩個向量應該在頭側或尾側連接,找共同點a
        // v1, v2的a點相同
        if((_v1->a()->x() == _v2->a()->x()) && (_v1->a()->y() == _v2->a()->y())){
            ax = _v1->a()->x(); ay = _v1->a()->y();
            bx = _v1->b()->x(); by = _v1->b()->y();
            cx = _v2->b()->x(); cy = _v2->b()->y();}
        // v1, v2的b點相同
        else if((_v1->b()->x() == _v2->b()->x()) && (_v1->b()->y() == _v2->b()->y())){
            ax = _v1->a()->x(); ay = _v1->a()->y();
            bx = _v1->b()->x(); by = _v1->b()->y();
            cx = _v2->a()->x(); cy = _v2->a()->y();}
        // v1的a與v2的b點相同
        else if((_v1->a()->x() == _v2->b()->x()) && (_v1->a()->y() == _v2->b()->y())){
            ax = _v1->a()->x(); ay = _v1->a()->y();
            bx = _v1->b()->x(); by = _v1->b()->y();
            cx = _v2->a()->x(); cy = _v2->a()->y();}
        // v1的b與v2的a點相同
        else if((_v1->b()->x() == _v2->a()->x()) && (_v1->b()->y() == _v2->a()->y())){
            ax = _v1->a()->x(); ay = _v1->a()->y();
            bx = _v1->b()->x(); by = _v1->b()->y();
            cx = _v2->b()->x(); cy = _v2->b()->y();}
        //定義向量座標
        vAB_x = fabs( bx - ax );  vAB_y = fabs( by - ay );
        vAC_x = fabs( cx - ax );  vAC_y = fabs( cy - ay );
        vBC_x = fabs( cx - bx );  vBC_y = fabs( cy - by );

        //定義向量大小(邊長)
        _sideAB = sqrt(  pow( vAB_y, 2)  +  pow( vAB_x, 2)  );
        _sideAC = sqrt(  pow( vAC_y, 2)  +  pow( vAC_x, 2)  );
        _sideBC = sqrt(  pow( vBC_y, 2)  +  pow( vBC_x, 2)  );

    }~Triangle() {}

    //三角形面積是叉積除以2
    double area() const override {return fabs((_v1->cross(_v2))/2);}

    double perimeter() const override {return _sideAB + _sideAC + _sideBC;}

    std::string info() const override {return "Triangle (" + _v1->info() + ", " + _v2->info() + ")";}

    Iterator* createIterator(IteratorFactory *factory) override {return factory->createIterator();}

    void addShape(Shape* const shape) override {throw std::string("Could not AddShape!!");}

    void deleteShape(Shape* shape) override {throw std::string("Could not DeleteShape!!");}

    std::string id() const override {return _id;}

    void accept(ShapeVisitor* visitor) {visitor->visitTriangle(this);};

    std::set<const Point*> getPoints() override {
      const Point common = *FindCommonPoint(*_v1, *_v2);
      const Point uncommon = *FindUncommonPoint(*_v2, common);
      return {new Point{_v1->head()}, new Point{_v1->tail()}, new Point{uncommon}};
    }
};
