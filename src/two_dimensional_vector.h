#pragma once
#include <cmath>
#include <set>
#include "point.h"

class TwoDimensionalVector
{
private:
    //指標變數_a指向函數Point
    const Point *_a;
    const Point *_b;

public:
    TwoDimensionalVector(const Point *a, const Point *b) : _a(a) , _b(b) {}
    ~TwoDimensionalVector() {}
    //指標函數a回傳指標變數_a
    const Point *a() const {return _a;}

    const Point *b() const {return _b;}

    double length() const {
      double ax = _a->x(), ay = _a->y(), bx = _b->x() ,by = _b->y();
      //向量長度公式:|v| = sqrt(x^2 + y^2)
      return sqrt((ax - bx)*(ax - bx)+(ay - by)*(ay - by));
    }

    double dot(const TwoDimensionalVector *vec) const {
      double v1ax = _a->x(), v1ay = _a->y(), v1bx = _b->x(), v1by = _b->y();
      double v2ax = vec->a()->x(), v2ay = vec->a()->y(), v2bx = vec->b()->x(), v2by = vec->b()->y();
      double vAB_x, vAC_x, vAB_y, vAC_y;
      double ax, ay, bx, by, cx, cy;
      // v1, v2的a點相同

      if((v1ax == v2ax) && (v1ay == v2ay)){
          //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2bx; cy = v2by;
         }
      // v1, v2的b點相同
      else if((v1bx == v2bx) && (v1by == v2by)){
          //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1bx; ay = v1by;
          bx = v1ax; by = v1ay;
          cx = v2ax; cy = v2ay;
         }
      // v1的a與v2的b點相同
      else if((v1ax == v2bx) && (v1ay == v2by)){
             //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2ax; cy = v2ay;
         }
      // v1的b與v2的a點相同
      else if((v1bx == v2ax) && (v1by == v2ay)){
            //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1bx; ay = v1by;
          bx = v1ax; by = v1ay;
          cx = v2bx; cy = v2by;
          }
      //定義向量座標
      vAB_x = bx - ax;  vAB_y = by - ay;
      vAC_x = cx - ax;  vAC_y = cy - ay;
      //直角點積應為零
      //內積運算 : a . b = x1*x2 + y1*y2
      double result = vAB_x * vAC_x + vAB_y * vAC_y;
      //四捨五入到小數後第3位
      double dotresult = round(result*1000)/1000;
      return dotresult;
    }

    double cross(const TwoDimensionalVector *vec) const {
      double v1ax = _a->x(), v1ay = _a->y(), v1bx = _b->x(), v1by = _b->y();
      double v2ax = vec->a()->x(), v2ay = vec->a()->y(), v2bx = vec->b()->x(), v2by = vec->b()->y();
      double vAB_x, vAC_x, vAB_y, vAC_y;
      double ax, ay, bx, by, cx, cy;
      // v1, v2的a點相同

      if((v1ax == v2ax) && (v1ay == v2ay)){
          //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2bx; cy = v2by;
         }
      // v1, v2的b點相同
      else if((v1bx == v2bx) && (v1by == v2by)){
          //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1bx; ay = v1by;
          bx = v1ax; by = v1ay;
          cx = v2ax; cy = v2ay;
         }
      // v1的a與v2的b點相同
      else if((v1ax == v2bx) && (v1ay == v2by)){
             //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2ax; cy = v2ay;
         }
      // v1的b與v2的a點相同
      else if((v1bx == v2ax) && (v1by == v2ay)){
            //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1bx; ay = v1by;
          bx = v1ax; by = v1ay;
          cx = v2bx; cy = v2by;
          }
      //定義向量座標
      vAB_x = bx - ax;  vAB_y = by - ay;
      vAC_x = cx - ax;  vAC_y = cy - ay;
      //外積運算 : a x b = ax*by - bx*ay
      return vAB_x * vAC_y - vAC_x * vAB_y ;
    }

    std::string info() const {
      return "Vector (" + _a->info() + ", " + _b->info() + ")";
    }
};
