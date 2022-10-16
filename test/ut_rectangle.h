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

TEST(RectangleTest,NotRectangle){
  try{
    Shape* rectangle = new Rectangle(
      new TwoDimensionalVector(new Point(0, 0),new Point(0, 0)),
      new TwoDimensionalVector(new Point(0, 0),new Point(0, 0)));
  }catch(std::string e){
    ASSERT_EQ("This is not a rectangle!",e);
  }
  try{
    Shape* rectangle = new Rectangle(
      new TwoDimensionalVector(new Point(1, 2),new Point(3, 4)),
      new TwoDimensionalVector(new Point(1, 2),new Point(3, 4)));
  }catch(std::string e){
    ASSERT_EQ("This is not a rectangle!",e);
  }
  try{
    Shape* rectangle = new Rectangle(
      new TwoDimensionalVector(new Point(0, 2),new Point(3, 0)),
      new TwoDimensionalVector(new Point(1, 0),new Point(0, 4)));
  }catch(std::string e){
    ASSERT_EQ("This is not a rectangle!",e);
  }
}

TEST(RectangleTest, CreateBFSIterator) {
  Shape* rectangle = new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));
  Iterator *it = rectangle->createBFSIterator();

  ASSERT_ANY_THROW(it->first());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());
  ASSERT_TRUE(it->isDone());

  delete it;
}


TEST(RectangleTest, CreateDFSIterator) {
  Shape* rectangle = new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));
  Iterator *it = rectangle->createDFSIterator();
  
  ASSERT_ANY_THROW(it->first());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());
  ASSERT_TRUE(it->isDone());

  delete it;
}
