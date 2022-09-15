#include "../src/point.h"

TEST(PointTest,PointInfo) {
  ASSERT_EQ("(4.59, 3.47)",( new Point(4.586, 3.471))->info());
}

TEST(PointTest,PointInfo1){
  Point point(-4.468, -3.471);
  ASSERT_EQ("(-4.47, -3.47)",point.info());
}
