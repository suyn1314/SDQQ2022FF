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
      double ax, ay, bx, by, cx, cy;
      // v1, v2的a點相同
      if((v1ax == v2ax) && (v1ay == v2ay)){
          //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2bx; cy = v2by;
          double vAB_x = bx - ax,  vAB_y = by - ay;
          double vAC_x = cx - ax,  vAC_y = cy - ay;
          return vAB_x * vAC_x + vAB_y * vAC_y;
         }
      // v1, v2的b點相同
      else if((v1bx == v2bx) && (v1by == v2by)){
          //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2ax; cy = v2ay;
          double vAB_x = bx - ax,  vAB_y = by - ay;
          double vCB_x = bx - cx,  vCB_y = by - cy;
          return vAB_x * vCB_x + vAB_y * vCB_y;
         }
      // v1的a與v2的b點相同
      else if((v1ax == v2bx) && (v1ay == v2by)){
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2ax; cy = v2ay;
          double vAB_x = bx - ax, vAB_y = by - ay;
          double vCA_x = ax - cx, vCA_y = ay - cy;
          return vAB_x * vCA_x + vAB_y * vCA_y;
         }
      // v1的b與v2的a點相同
      else if((v1bx == v2ax) && (v1by == v2ay)){
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2bx; cy = v2by;
          double vAB_x = bx - ax,  vAB_y = by - ay;
          double vBC_x = cx - bx,  vBC_y = cy - by;
          return vAB_x * vBC_x + vAB_y * vBC_y;
          }
      //銳角的點積應該是正數
      //內積運算 : a . b = x1*x2 + y1*y2
      //四捨五入到小數後第3位
      //double dotresult = round(result*1000)/1000;
      //return dotresult;
      return 0;
    }

    double cross(const TwoDimensionalVector *vec) const {
      double v1ax = _a->x(), v1ay = _a->y(), v1bx = _b->x(), v1by = _b->y();
      double v2ax = vec->a()->x(), v2ay = vec->a()->y(), v2bx = vec->b()->x(), v2by = vec->b()->y();
      double ax, ay, bx, by, cx, cy;
      // v1, v2的a點相同

      if((v1ax == v2ax) && (v1ay == v2ay)){
          //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2bx; cy = v2by;
          double vAB_x = bx - ax,  vAB_y = by - ay;
          double vAC_x = cx - ax,  vAC_y = cy - ay;
          return vAB_x * vAC_y - vAC_x * vAB_y ;
         }
      // v1, v2的b點相同
      else if((v1bx == v2bx) && (v1by == v2by)){
          ax = v1ax; ay = v1ay;
          bx = v2ax; by = v2ay;
          cx = v1bx; cy = v1by;
          double vAB_x = bx - ax,  vAB_y = by - ay;
          double vCB_x = bx - cx,  vCB_y = by - cy;
          return vAB_x * vCB_y - vCB_x * vAB_y ;
         }
      // v1的a與v2的b點相同
      else if((v1ax == v2bx) && (v1ay == v2by)){
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2ax; cy = v2ay;
          double vAB_x = bx - ax, vAB_y = by - ay;
          double vCA_x = ax - cx, vCA_y = ay - cy;
          return vAB_x * vCA_y - vCA_x * vAB_y ;
         }
      // v1的b與v2的a點相同
      else if((v1bx == v2ax) && (v1by == v2ay)){
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2bx; cy = v2by;
          double vAB_x = bx - ax,  vAB_y = by - ay;
          double vBC_x = cx - bx,  vBC_y = cy - by;
          return vAB_x * vBC_y - vBC_x * vAB_y ;
          }
      //定義向量座標
      //cos<a,b>=(a.*b)/norm(a)/norm(b);
      //兩個逆時針向量的叉積應該是正的
      //兩個向量順時針的叉積應該是負數
      //外積運算 : a x b = ax*by - bx*ay
      return 0;
    }

    std::string info() const {
      return "Vector (" + _a->info() + ", " + _b->info() + ")";
    }
};
