#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/triangle.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/list_iterator_factory.h"
#include "../src/iterator/iterator.h"

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

TEST(TriangleTest, CreateBFSIterator) {
  Shape* triangle = new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));
  Iterator *it = triangle->createIterator(new BFSIteratorFactory());

  ASSERT_ANY_THROW(it->first());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());
  ASSERT_TRUE(it->isDone());

  delete it;
}

TEST(TriangleTest, CreateDFSIterator) {
  Shape* triangle = new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));
  Iterator *it = triangle->createIterator(new DFSIteratorFactory());

  ASSERT_ANY_THROW(it->first());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());
  ASSERT_TRUE(it->isDone());

  delete it;
}

TEST(TriangleTest, CreateListIterator) {
  Shape* triangle = new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));
  Iterator *it = triangle->createIterator(new ListIteratorFactory());

  ASSERT_ANY_THROW(it->first());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());
  ASSERT_TRUE(it->isDone());

  delete it;
}


TEST(TriangleTest, AddShapeTest) {
  Shape* triangle = new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));
  Shape* triangle1 = new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));
  try {
      triangle->addShape(triangle1);
  }
  catch(std::string e) {
      ASSERT_EQ(std::string("Could not AddShape!!"), e);
  }
}

TEST(TriangleTest, DeleteShapeTest) {
  Shape* triangle = new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));
  Shape* triangle1 = new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));
  try {
      triangle->deleteShape(triangle1);
  }
  catch(std::string e) {
      ASSERT_EQ(std::string("Could not DeleteShape!!"), e);
  }
}

//hw3
TEST(TriangleTest, GetPointsTeat) {
  Point* A = new Point(20, 13);
  Point* B = new Point(16, 14);
  Point* C = new Point(15, 10);
  TwoDimensionalVector* v1 = new TwoDimensionalVector(A, B);
  TwoDimensionalVector* v2 = new TwoDimensionalVector(B, C);
  Shape* triangle = new Triangle(v1, v2);

  std::set<const Point *> points = triangle->getPoints();

  std::set<const Point *, bool (*)(const Point *, const Point *)> actualPoints(
       points.begin(), points.end(),
       [](const Point *p1, const Point *p2) -> bool
       {
           return p1->x() < p2->x() || (p1->x() == p2->x() && p1->y() < p2->y());
       });
  ASSERT_TRUE(actualPoints.size() == 3);
  ASSERT_TRUE(actualPoints.find(A) != actualPoints.end());
  ASSERT_TRUE(actualPoints.find(B) != actualPoints.end());
  ASSERT_TRUE(actualPoints.find(C) != actualPoints.end());
  ASSERT_FALSE(triangle->getPoints().empty());
  ASSERT_EQ(3,triangle->getPoints().size());
}
