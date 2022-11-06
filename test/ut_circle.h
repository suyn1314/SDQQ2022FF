#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include "../src/circle.h"
#include "../src/iterator/factory/bfs_iterator_factory.h"
#include "../src/iterator/factory/dfs_iterator_factory.h"
#include "../src/iterator/factory/list_iterator_factory.h"
#include "../src/iterator/iterator.h"
#include <set>

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

TEST(CircleTest, AddShapeTest) {
  Shape* circle = new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(3, 4)));
  Shape* circle1 = new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(3, 4)));

  try {
      circle->addShape(circle1);
  }
  catch(std::string e) {
      ASSERT_EQ(std::string("Could not AddShape!!"), e);
  }
}

TEST(CircleTest, DeleteShapeTest) {
  Shape* circle = new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(3, 4)));
  Shape* circle1 = new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(3, 4)));
  try {
      circle->deleteShape(circle1);
  }
  catch(std::string e) {
      ASSERT_EQ(std::string("Could not DeleteShape!!"), e);
  }
}

TEST(CircleTest, CreateBFSIteratorFactoryTest) {
  Shape* circle = new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(0, 1)));
  Iterator *it = circle->createIterator(new BFSIteratorFactory());
  ASSERT_TRUE(it->isDone());
  delete it;
}

TEST(CircleTest, CreateDFSIteratorFactoryTest) {
  Shape* circle = new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(0, 1)));
  Iterator *it = circle->createIterator(new DFSIteratorFactory());
  ASSERT_TRUE(it->isDone());
  delete it;
}

TEST(CircleTest, CreateListIteratorFactoryTest) {
  Shape* circle = new Circle(new TwoDimensionalVector(new Point(0, 0), new Point(0, 1)));
  Iterator *it = circle->createIterator(new ListIteratorFactory());
  ASSERT_TRUE(it->isDone());
  delete it;
}

//hw3
TEST(CircleTest, GetPointsTeat) {
  Point*  A = new Point(14, 2);
  Point*  B = new Point(18, -4);
  TwoDimensionalVector*  v1 = new TwoDimensionalVector(A, B);
  Shape* circle = new Circle(v1);

  double radius = v1->length();

  std::set<const Point *> points = circle->getPoints();
  std::set<const Point *, bool (*)(const Point *, const Point *)> actualPoints(
      points.begin(), points.end(),
      [](const Point *p1, const Point *p2) -> bool
      {
          return p1->x() < p2->x() || (p1->x() == p2->x() && p1->y() < p2->y());
      });

  ASSERT_TRUE(actualPoints.size() == 2);

  const Point * pMax = new Point(A->x() + radius, A->y() + radius);
  const Point * pMin = new Point(A->x() - radius, A->y() - radius);

  ASSERT_TRUE(actualPoints.find(pMax) != actualPoints.end());
  ASSERT_TRUE(actualPoints.find(pMin) != actualPoints.end());
  ASSERT_TRUE(actualPoints.find(new Point(A->x() + radius, A->y() - radius)) == actualPoints.end());
  ASSERT_TRUE(actualPoints.find(new Point(A->x() - radius, A->y() + radius)) == actualPoints.end());
  ASSERT_FALSE(circle->getPoints().empty());
  ASSERT_EQ(2,circle->getPoints().size());
}
