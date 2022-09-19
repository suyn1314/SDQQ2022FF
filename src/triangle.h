#pragma once
#include "shape.h"
#include "two_dimensional_vector.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector *_v1;
    TwoDimensionalVector *_v2;
    double ax, ay, bx, by, cx, cy;
    double _sideAB, _sideAC, _sideBC;
    double vAB_x,vAB_y,vAC_x,vAC_y,vBC_x,vBC_y,vCB_x,vCB_y,vCA_x,vCA_y;
public:
    Triangle(TwoDimensionalVector *v1, TwoDimensionalVector *v2) : _v1(v1), _v2(v2){
        //三角形的兩個向量應該在頭側或尾側連接,找共同點a
        // v1, v2的a點相同
        if((_v1->a()->x() == _v2->a()->x()) && (_v1->a()->y() == _v2->a()->y())){
            ax = _v1->a()->x(); ay = _v1->a()->y();
            bx = _v1->b()->x(); by = _v1->b()->y();
            cx = _v2->b()->x(); cy = _v2->b()->y();

            //定義向量座標
            vAB_x =  bx - ax;  vAB_y =  by - ay;
            vAC_x =  cx - ax;  vAC_y =  cy - ay;
            vBC_x =  cx - bx;  vBC_y =  cy - by;

            //定義向量大小(邊長)
            _sideAB = sqrt(  pow( vAB_y, 2)  +  pow( vAB_x, 2)  );
            _sideAC = sqrt(  pow( vAC_y, 2)  +  pow( vAC_x, 2)  );
            _sideBC = sqrt(  pow( vBC_y, 2)  +  pow( vBC_x, 2)  );

            //兩邊之合不得大於等於第三邊，邊長不得為零
            if (_sideAB + _sideAC < _sideBC ||
            _sideBC + _sideAC < _sideAB ||
            _sideAB + _sideBC < _sideAC ||
            _sideAB <= 0 || _sideAC <= 0 || _sideBC <= 0 ){
              throw std::string("This is not a triangle!");
            }
           }
        // v1, v2的b點相同
        else if((_v1->b()->x() == _v2->b()->x()) && (_v1->b()->y() == _v2->b()->y())){
            ax = _v1->a()->x(); ay = _v1->a()->y();
            bx = _v1->b()->x(); by = _v1->b()->y();
            cx = _v2->a()->x(); cy = _v2->a()->y();

            //定義向量座標
            vAB_x =  bx - ax;  vAB_y =  by - ay;
            vCB_x =  bx - cx;  vCB_y =  by - cy;
            vAC_x =  cx - ax;  vAC_y =  cy - ay;

            //定義向量大小(邊長)
            _sideAB = sqrt(  pow( vAB_y, 2)  +  pow( vAB_x, 2)  );
            _sideAC = sqrt(  pow( vCB_y, 2)  +  pow( vCB_x, 2)  );
            _sideBC = sqrt(  pow( vAC_x, 2)  +  pow( vAC_y, 2)  );

            //兩邊之合不得大於等於第三邊，邊長不得為零
            if (_sideAB + _sideAC < _sideBC ||
            _sideBC + _sideAC < _sideAB ||
            _sideAB + _sideBC < _sideAC ||
            _sideAB <= 0 || _sideAC <= 0 || _sideBC <= 0 ){
              throw std::string("This is not a triangle!");
            }
           }
        // v1的a與v2的b點相同
        else if((_v1->a()->x() == _v2->b()->x()) && (_v1->a()->y() == _v2->b()->y())){
            ax = _v1->a()->x(); ay = _v1->a()->y();
            bx = _v1->b()->x(); by = _v1->b()->y();
            cx = _v2->a()->x(); cy = _v2->a()->y();

            //定義向量座標
            vAB_x = bx - ax;  vAB_y = by - ay;
            vCA_x = ax - cx;  vCA_y = ay - cy;
            vCB_x = bx - cx;  vCB_y = by - cy;

            //定義向量大小(邊長)
            _sideAB = sqrt(  pow( vAB_y, 2)  +  pow( vAB_x, 2)  );
            _sideAC = sqrt(  pow( vCA_x, 2)  +  pow( vCA_y, 2)  );
            _sideBC = sqrt(  pow( vCB_x, 2)  +  pow( vCB_y, 2)  );

            //兩邊之合不得大於等於第三邊，邊長不得為零
            if (_sideAB + _sideAC < _sideBC ||
            _sideBC + _sideAC < _sideAB ||
            _sideAB + _sideBC < _sideAC ||
            _sideAB <= 0 || _sideAC <= 0 || _sideBC <= 0 ){
              throw std::string("This is not a triangle!");
            }
           }
        // v1的b與v2的a點相同
        else if((_v1->b()->x() == _v2->a()->x()) && (_v1->b()->y() == _v2->a()->y())){
            ax = _v1->a()->x(); ay = _v1->a()->y();
            bx = _v1->b()->x(); by = _v1->b()->y();
            cx = _v2->b()->x(); cy = _v2->b()->y();

            //定義向量座標
            vAB_x = bx - ax;  vAB_y = by - ay;
            vBC_x = cx - bx;  vBC_y = cy - by;
            vCA_x = cx - ax;  vCA_y = ay - cy;

            //定義向量大小(邊長)
            _sideAB = sqrt(  pow( vAB_y, 2)  +  pow( vAB_x, 2)  );
            _sideAC = sqrt(  pow( vBC_x, 2)  +  pow( vBC_y, 2)  );
            _sideBC = sqrt(  pow( vCA_x, 2)  +  pow( vCA_y, 2)  );

            //兩邊之合不得大於等於第三邊，邊長不得為零
            if (_sideAB + _sideAC < _sideBC ||
            _sideBC + _sideAC < _sideAB ||
            _sideAB + _sideBC < _sideAC ||
            _sideAB <= 0 || _sideAC <= 0 || _sideBC <= 0 ){
              //throw std::string("This is not a triangle!");
            }
        else{throw std::string("This is not a triangle!");}
      }
    }~Triangle() {}

    //三角形面積是叉積除以2
    double area() const override {return fabs((_v1->cross(_v2))/2);}

    double perimeter() const override {return _sideAB + _sideAC + _sideBC;}

    std::string info() const override {
      return "Triangle (" + _v1->info() + ", " + _v2->info() + ")";
    }
};
