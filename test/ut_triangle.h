#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/triangle.h"

TEST(TriangleTest,TriangleArea){
  ASSERT_EQ(6,(new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 0),new Point(0, 0))))->area());
  ASSERT_EQ(6,(new Triangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(3, 0)),
    new TwoDimensionalVector(new Point(3, 4),new Point(3, 0))))->area());
  ASSERT_EQ(6,(new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 4),new Point(3, 0))))->area());
}

TEST(TriangleTest,TrianglePerimeter){
  ASSERT_EQ(12,(new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 0),new Point(0, 0))))->perimeter());
  ASSERT_EQ(12,(new Triangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(3, 0)),
    new TwoDimensionalVector(new Point(3, 4),new Point(3, 0))))->perimeter());
  ASSERT_EQ(12,(new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 4),new Point(3, 0))))->perimeter());
}
TEST(TriangleTest,TriangleInfo) {
  ASSERT_EQ("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))",(new Triangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(3, 0)),
    new TwoDimensionalVector(new Point(3, 4),new Point(3, 0))
))->info());
}

TEST(TriangleTest,NotTriangle){
  try{
    Shape* triangle = new Triangle(
      new TwoDimensionalVector(new Point(0, 0),new Point(0, 0)),
      new TwoDimensionalVector(new Point(0, 0),new Point(0, 0)));
  }catch(std::string e){
    ASSERT_EQ("This is not a triangle!",e);
  }

  try{
    Shape* triangle = new Triangle(
      new TwoDimensionalVector(new Point(1, 2),new Point(3, 4)),
      new TwoDimensionalVector(new Point(1, 2),new Point(3, 4)));
  }catch(std::string e){
    ASSERT_EQ("This is not a triangle!",e);
  }

  try{
    Shape* triangle = new Triangle(
      new TwoDimensionalVector(new Point(0, 2),new Point(3, 0)),
      new TwoDimensionalVector(new Point(1, 0),new Point(0, 4)));
  }catch(std::string e){
    ASSERT_EQ("This is not a triangle!",e);
  }

}
