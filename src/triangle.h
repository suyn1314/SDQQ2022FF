#pragma once
#include "shape.h"
#include "two_dimensional_vector.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector *_v1;
    TwoDimensionalVector *_v2;
    double ax, ay, bx, by, cx, cy;
    double vAB_x, vAC_x, vAB_y, vAC_y,vBC_x, vBC_y;
    double _sideAB, _sideAC, _sideBC;
public:
    Triangle(TwoDimensionalVector *v1, TwoDimensionalVector *v2) : _v1(v1), _v2(v2){
        //三角形的兩個向量應該在頭側或尾側連接,找共同點a
        // v1, v2的a點相同
        if((_v1->a()->x() == _v2->a()->x()) && (_v1->a()->y() == _v2->a()->y())){
            //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
            ax = _v1->a()->x(); ay = _v1->a()->y();
            bx = _v1->b()->x(); by = _v1->b()->y();
            cx = _v2->b()->x(); cy = _v2->b()->y();
           }
        // v1, v2的b點相同
        else if((_v1->b()->x() == _v2->b()->x()) && (_v1->b()->y() == _v2->b()->y())){
            //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
            ax = _v1->b()->x(); ay = _v1->b()->y();
            bx = _v1->a()->x(); by = _v1->a()->y();
            cx = _v2->a()->x(); cy = _v2->a()->y();
           }
        else{
            throw std::string("This is not a triangle!");
        }
        //定義向量座標
        vAB_x = fabs( bx - ax );  vAB_y = fabs( by - ay );
        vAC_x = fabs( cx - ax );  vAC_y = fabs( cy - ay );
        vBC_x = fabs( cx - bx );  vBC_y = fabs( cy - by );

        //定義向量大小(長度)
        _sideAB = sqrt(  pow( vAB_y, 3)  +  pow( vAB_x, 3)  );
        _sideAC = sqrt(  pow( vAC_y, 3)  +  pow( vAC_x, 3)  );
        _sideBC = sqrt(  pow( vBC_y, 3)  +  pow( vBC_x, 3)  );

        //兩邊之合不得大於等於第三邊，邊長不得為零
        if (_sideAB + _sideAC < _sideBC ||
        _sideBC + _sideAC < _sideAB ||
        _sideAB + _sideBC < _sideAC ||
        _sideAB <= 0 || _sideAC <= 0 || _sideBC <= 0 ){ throw std::string("This is not a triangle!");
        }
    }~Triangle() {}


    double area() const override {
        //三角形面積是叉積除以2
        //EX: _AB = (3, 0), _AC = (3, 4) , area = ( _AB * _AC ) / 2
            return fabs( ( vAB_x * vAC_y ) - ( vAC_x * vAB_y ) ) / 2;
    }

    double perimeter() const override {
      return _sideAB + _sideAC + _sideBC;
    }

    std::string info() const override {
      return "Triangle (" + _v1->info() + ", " + _v2->info() + ")";
    }
};
