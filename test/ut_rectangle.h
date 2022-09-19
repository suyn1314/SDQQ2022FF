#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/rectangle.h"
TEST(RectangleTest,RectangleValue){
  ASSERT_EQ(2,(new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 3))))->length());
  ASSERT_EQ(3,(new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 3))))->width());

}

TEST(RectangleTest,RectangleArea){
  ASSERT_EQ(6,(new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 3))))->area());
  ASSERT_EQ(9,(new Rectangle(
    new TwoDimensionalVector(new Point(1, 1),new Point(4, 1)),
    new TwoDimensionalVector(new Point(1, 1),new Point(1, 4))))->area());
  ASSERT_EQ(12,(new Rectangle(
    new TwoDimensionalVector(new Point(1, 1),new Point(1, 4)),
    new TwoDimensionalVector(new Point(1, 1),new Point(-3, 1))))->area());
  ASSERT_EQ(15,(new Rectangle(
    new TwoDimensionalVector(new Point(1, 1),new Point(1, -4)),
    new TwoDimensionalVector(new Point(1, 1),new Point(4, 1))))->area());
  ASSERT_EQ(20,(new Rectangle(
    new TwoDimensionalVector(new Point(1, 1),new Point(1, -4)),
    new TwoDimensionalVector(new Point(1, 1),new Point(-3, 1))))->area());
}

TEST(RectangleTest,RectanglePerimeter){
  ASSERT_EQ(20,(new Rectangle(
    new TwoDimensionalVector(new Point(0, 5),new Point(0, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(5, 0))))->perimeter());
  ASSERT_EQ(20,(new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 5)),
    new TwoDimensionalVector(new Point(5, 0),new Point(0, 0))))->perimeter());
  ASSERT_EQ(20,(new Rectangle(
    new TwoDimensionalVector(new Point(0, 5),new Point(0, 0)),
    new TwoDimensionalVector(new Point(5, 0),new Point(0, 0))))->perimeter());
  ASSERT_EQ(20,(new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(5, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 5))))->perimeter());
}
TEST(RectangleTest,RectangleInfo) {
  ASSERT_EQ("Rectangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((0.00, 0.00), (0.00, 4.00)))",(new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(3, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 4))
))->info());
}
