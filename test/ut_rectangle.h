#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/rectangle.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/list_iterator_factory.h"
#include "../src/iterator/iterator.h"

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

  Iterator *it = rectangle->createIterator(new BFSIteratorFactory());

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
  Iterator *it = rectangle->createIterator(new DFSIteratorFactory());

  ASSERT_ANY_THROW(it->first());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());
  ASSERT_TRUE(it->isDone());

  delete it;
}

TEST(RectangleTest, CreateListIterator) {
  Shape* rectangle = new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));
  Iterator *it = rectangle->createIterator(new ListIteratorFactory());

  ASSERT_ANY_THROW(it->first());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());
  ASSERT_TRUE(it->isDone());

  delete it;
}

TEST(RectangleTest, AddShapeTest) {
  Shape* rectangle = new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));
  Shape* rectangle1 = new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));
  try {
      rectangle->addShape(rectangle1);
  }
  catch(std::string e) {
      ASSERT_EQ(std::string("Could not AddShape!!"), e);
  }
}

TEST(RectangleTest, DeleteShapeTest) {
  Shape* rectangle = new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));
  Shape* rectangle1 = new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));
  try {
      rectangle->deleteShape(rectangle1);
  }
  catch(std::string e) {
      ASSERT_EQ(std::string("Could not DeleteShape!!"), e);
  }
}

//hw3
TEST(RectangleTest, GetPointsTeat) {
  Point* A = new Point(20, 13);
  Point* B = new Point(16, 14);
  Point* C = new Point(15, 10);
  Point* D = new Point(19, 9);
  TwoDimensionalVector* v1 = new TwoDimensionalVector(A, B);
  TwoDimensionalVector* v2 = new TwoDimensionalVector(B, C);
  Shape* rectangle = new Rectangle(v1, v2);

  std::set<const Point *> points = rectangle->getPoints();

  std::set<const Point *, bool (*)(const Point *, const Point *)> actualPoints(
       points.begin(), points.end(),
       [](const Point *p1, const Point *p2) -> bool
       {
           return p1->x() < p2->x() || (p1->x() == p2->x() && p1->y() < p2->y());
       });
  ASSERT_TRUE(actualPoints.find(A) != actualPoints.end());
  ASSERT_TRUE(actualPoints.find(B) != actualPoints.end());
  ASSERT_TRUE(actualPoints.find(C) != actualPoints.end());
  ASSERT_TRUE(actualPoints.find(D) != actualPoints.end());
  ASSERT_FALSE(rectangle->getPoints().empty());
  ASSERT_EQ(4,rectangle->getPoints().size());
}
