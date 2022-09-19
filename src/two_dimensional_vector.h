#pragma once
#include <cmath>
#include <set>
#include "point.h"

class TwoDimensionalVector
{
private:
    const Point *_a;
    const Point *_b;

public:
    TwoDimensionalVector(const Point *a, const Point *b) : _a(a) , _b(b) {}
    ~TwoDimensionalVector() {}

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
          double _sideAB = sqrt(  pow( vAB_y, 2)  +  pow( vAB_x, 2)  );
          double _sideAC = sqrt(  pow( vAC_y, 2)  +  pow( vAC_x, 2)  );
          //double _sideBC = sqrt(  pow( vBC_y, 2)  +  pow( vBC_x, 2)  );
          double cos = (vAB_x * vAC_x + vAB_y * vAC_y) / (_sideAB*_sideAC);
          //銳角的點積應該是正數
          if (cos > 0 ){
            return fabs(vAB_x * vAC_x + vAB_y * vAC_y);
          }
          else {return vAB_x * vAC_x + vAB_y * vAC_y;}
         }
      // v1, v2的b點相同
      else if((v1bx == v2bx) && (v1by == v2by)){
          //相同的點為a其餘的為b,c :a(ax, ay), b(bx,by), c(cx,cy)
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2ax; cy = v2ay;
          double vAB_x = bx - ax,  vAB_y = by - ay;
          double vCB_x = bx - cx,  vCB_y = by - cy;
          double _sideAB = sqrt(  pow( vAB_x, 2)  +  pow( vAB_y, 2)  );
          double _sideCB = sqrt(  pow( vCB_x, 2)  +  pow( vCB_y, 2)  );
          //double _sideBC = sqrt(  pow( vBC_y, 2)  +  pow( vBC_x, 2)  );
          double cos = (vAB_x * vCB_x + vAB_y * vCB_y) / (_sideAB*_sideCB);
          //銳角的點積應該是正數
          if (cos > 0 ){
            return fabs(vAB_x * vCB_x + vAB_y * vCB_y);
          }
          else {return vAB_x * vCB_x + vAB_y * vCB_y;}
         }
      // v1的a與v2的b點相同
      else if((v1ax == v2bx) && (v1ay == v2by)){
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2ax; cy = v2ay;
          double vAB_x = bx - ax, vAB_y = by - ay;
          double vCA_x = ax - cx, vCA_y = ay - cy;
          double _sideAB = sqrt(  pow( vAB_y, 2)  +  pow( vAB_x, 2)  );
          double _sideCA = sqrt(  pow( vCA_x, 2)  +  pow( vCA_y, 2)  );
          //double _sideBC = sqrt(  pow( vBC_y, 2)  +  pow( vBC_x, 2)  );
          double cos = (vAB_x * vCA_x + vAB_y * vCA_y) / (_sideAB*_sideCA);
          //銳角的點積應該是正數
          if (cos > 0 ){
            return fabs(vAB_x * vCA_x + vAB_y * vCA_y);
          }
          else {return vAB_x * vCA_x + vAB_y * vCA_y;}
         }
      // v1的b與v2的a點相同
      else if((v1bx == v2ax) && (v1by == v2ay)){
          ax = v1ax; ay = v1ay;
          bx = v1bx; by = v1by;
          cx = v2bx; cy = v2by;
          double vAB_x = bx - ax,  vAB_y = by - ay;
          double vBC_x = cx - bx,  vBC_y = cy - by;
          double _sideAB = sqrt(  pow( vAB_y, 2)  +  pow( vAB_x, 2)  );
          double _sideBC = sqrt(  pow( vBC_x, 2)  +  pow( vBC_y, 2)  );
          //double _sideBC = sqrt(  pow( vBC_y, 2)  +  pow( vBC_x, 2)  );
          double cos = (vAB_x * vBC_x + vAB_y * vBC_y) / (_sideAB*_sideBC);
          //銳角的點積應該是正數
          if (cos > 0 ){
            return fabs(vAB_x * vBC_x + vAB_y * vBC_y);
          }
          else {return vAB_x * vBC_x + vAB_y * vBC_y;}
          }
      // 4點座標不同
      double v1AB_x = v1bx - v1ax,  v1AB_y = v1by - v1ay;
      double v2AB_x = v2bx - v2ax,  v2AB_y = v2by - v2ay;
      double _sideV1 = sqrt(  pow( v1AB_x, 2)  +  pow( v1AB_y, 2)  );
      double _sideV2 = sqrt(  pow( v2AB_x, 2)  +  pow( v2AB_y, 2)  );
      //double _sideBC = sqrt(  pow( vBC_y, 2)  +  pow( vBC_x, 2)  );
      double cos = (v1AB_x * v2AB_x + v1AB_y * v2AB_y) / (_sideV1*_sideV2);
      //銳角的點積應該是正數
      if (cos > 0 ){
        return fabs(v1AB_x * v2AB_x + v1AB_y * v2AB_y);
      }
      return v1AB_x * v2AB_x + v1AB_y * v2AB_y;
    }

    double cross(const TwoDimensionalVector *vec) const {
      double v1ax = _a->x(), v1ay = _a->y(), v1bx = _b->x(), v1by = _b->y();
      double v2ax = vec->a()->x(), v2ay = vec->a()->y(), v2bx = vec->b()->x(), v2by = vec->b()->y();
      double v1AB_x = v1bx - v1ax,  v1AB_y = v1by - v1ay;
      double v2AB_x = v2bx - v2ax,  v2AB_y = v2by - v2ay;
      double _sideV1 = sqrt(  pow( v1AB_x, 2)  +  pow( v1AB_y, 2)  );
      double _sideV2 = sqrt(  pow( v2AB_x, 2)  +  pow( v2AB_y, 2)  );
      double sin = (v1AB_x * v2AB_y - v1AB_y * v2AB_x) / (_sideV1*_sideV2);
      return v1AB_x * v2AB_y - v1AB_y * v2AB_x;
    }

    std::string info() const {
      return "Vector (" + _a->info() + ", " + _b->info() + ")";
    }
};
