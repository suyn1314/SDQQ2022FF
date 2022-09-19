#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/circle.h"

TEST(CircleTest,CircleRadius){
  ASSERT_EQ(5,(new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(3, 4))))->radius());
  ASSERT_EQ(5,(new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(-3, -4))))->radius());
  ASSERT_NEAR(16.12,(new Circle(new TwoDimensionalVector(new Point(-5, -10), new Point(3, 4))))->radius(),0.1);
  ASSERT_NEAR(9.21,(new Circle(new TwoDimensionalVector(new Point(-1, -1), new Point(-7, -8))))->radius(),0.1);
}
TEST(CircleTest,CircleArea) {
  ASSERT_NEAR(78.54,(new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(3, 4))))->area(),0.1);
}
TEST(CircleTest,CirclePerimeter) {
  ASSERT_NEAR(31.42,(new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(3, 4))))->perimeter(),0.1);
}
TEST(CircleTest,CircleInfo) {
  ASSERT_EQ("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))",(new Circle(new TwoDimensionalVector(new Point(-4.284, 0.264), new Point(-4.827, 0.728))))->info());
}
