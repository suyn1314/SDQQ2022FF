#include "../src/point.h"

TEST(PointTest,PointValue){
  Point point(-4.468, -3.471);
  ASSERT_EQ(-4.468,point.x());
  ASSERT_EQ(-3.471,point.y());
}

TEST(PointTest,PointInfo) {
  ASSERT_EQ("(4.59, 3.47)",( new Point(4.586, 3.471))->info());
}

TEST(PointTest,PointInfo1){
  Point point(-4.468, -3.471);
  ASSERT_EQ("(-4.47, -3.47)",point.info());
}

TEST(PointTest,PointOperator){
  Point pointA (-4.468, -3.471);
  ASSERT_EQ(false,( new Point(4.586, 3.471))->operator==(pointA));
  ASSERT_EQ(true,( new Point(-4.468, -3.471))->operator==(pointA));

}
