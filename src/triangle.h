#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector *_v1;
    TwoDimensionalVector *_v2;

public:
    Triangle(TwoDimensionalVector *v1, TwoDimensionalVector *v2) : _v1(v1), _v2(v2){
      if(((v1ax=v2ax)&&(v1ay=v2ay)&&(v1by!=v2by)&&(v1bx!=v2bx))||((v1bx=v2bx)&&(v1by=v2by)&&(v1ay!=v2ay)&&(v1ax!=v2ax))){

           throw std::string("This is not a triangle!");
       }
    }
    ~Triangle() {}

    double area() const override {
        //由於兩個向量的叉積的大小等於這兩個向量跨越的平行四邊形的面積
        //並且三角形的面積是平行四邊形的一半
        //所以三角形面積是叉積除以2
        //有向量a, b則: sqrt((a^2)*(b^2)-(a*b)^2)/2
        std::cout<<"area!"<<std::endl;
        double a = _v1->length(), b = _v2->length(), c;
        std::cout<<a<<std::endl;
        std::cout<<b<<std::endl;
      return (sqrt(((a*a)*(b*b))-((a*b)*(a*b))))/2;
    }

    double perimeter() const override {
      return 0;
    }

    std::string info() const override {
      return "Triangle (" + _v1->info() + ", " + _v2->info() + ")";
    }
};
