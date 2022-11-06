#include <set>
#include "../src/point.h"
#include "../src/bounding_box.h"

class BoundingBoxTest : public ::testing::Test
{
protected:
    const double dif = 0.001;
    Point *p0, *p1, *p2, *p3, *p4, *p5;
    Point *A, *B, *C, *D, *E, *F, *G, *H, *I, *J;
    Point *K, *M, *O, *N, *P, *Q, *R, *S, *T, *U;
    std::vector<BoundingBox *> boxes;
    std::vector<Rectangle *> recs;

    void SetUp()
    {
      A = new Point(-1, -1);
      B = new Point(1, -1);
      C = new Point(1, 1);
      D = new Point(-1, 1);
      E = new Point(-3, 1);
      F = new Point(-1, 3);
      G = new Point(-3, 3);
      H = new Point(3, 1);
      I = new Point(3, 3);
      J = new Point(1, 3);
      K = new Point(0, -1);
      M = new Point(0, -3);
      N = new Point(1, -2);
      O = new Point(2, -1);
      P = new Point(2, -3);
      Q = new Point(3, -2);
      R = new Point(-2, -1);
      S = new Point(-3, -2);
      T = new Point(-2, -3);
      U = new Point(-1, -2);
      p0 = new Point(0, 0);
      p1 = new Point(-44, 15);
      p2 = new Point(-6, 3);
      p3 = new Point(22, 6);
      p4 = new Point(-5, -10);
      p5 = new Point(-15, -7);

      recs = {
        new Rectangle( // 0
            new TwoDimensionalVector(G, F),
            new TwoDimensionalVector(F, D)),
        new Rectangle( // 1
            new TwoDimensionalVector(D, C),
            new TwoDimensionalVector(D, A)),
        new Rectangle( // 2
            new TwoDimensionalVector(C, J),
            new TwoDimensionalVector(I, J)),
        new Rectangle( // 3
            new TwoDimensionalVector(R, S),
            new TwoDimensionalVector(S, T)),
        new Rectangle( // 4
            new TwoDimensionalVector(M, U),
            new TwoDimensionalVector(M, N)),
        new Rectangle( // 5
            new TwoDimensionalVector(Q, O),
            new TwoDimensionalVector(P, Q))};

      boxes = {
        new BoundingBox(recs[0]->getPoints()),
        new BoundingBox(recs[1]->getPoints()),
        new BoundingBox(recs[2]->getPoints()),
        new BoundingBox(recs[3]->getPoints()),
        new BoundingBox(recs[4]->getPoints()),
        new BoundingBox(recs[5]->getPoints()),
};
    }

    void TearDown()
    {
        delete p0, p1, p2, p3, p4, p5;
        delete A, B, C, D, E, F, G, H, I, J;
        delete K, M, O, N, P, Q, R, S, T, U;
    }
};

TEST_F(BoundingBoxTest, MaxPointExpectedly)
{
    Point *points[] = {p0, p1, p2, p3, p4, p5};
    std::set<const Point *> pointsSet(points, points + 6);
    BoundingBox *boundingBox = new BoundingBox(pointsSet);

    const Point *maxPoint = boundingBox->max();
    ASSERT_NEAR(p3->x(), maxPoint->x(), dif);
    ASSERT_NEAR(p1->y(), maxPoint->y(), dif);
}

TEST_F(BoundingBoxTest, MinPointExpectedly)
{
    Point *points[] = {p0, p1, p2, p3, p4, p5};
    std::set<const Point *> pointsSet(points, points + 6);
    BoundingBox *boundingBox = new BoundingBox(pointsSet);

    const Point *minPoint = boundingBox->min();
    ASSERT_NEAR(p1->x(), minPoint->x(), dif);
    ASSERT_NEAR(p4->y(), minPoint->y(), dif);
}

TEST_F(BoundingBoxTest, CalculateMaxTest)
{
    Point *points[] = {p0, p1, p2, p3, p4, p5};
    std::set<const Point *> pointsSet(points, points + 6);
    BoundingBox *boundingBox = new BoundingBox(pointsSet);

    Point *maxPoint = boundingBox->calMaximumPoint(pointsSet);
    ASSERT_NEAR(p3->x(), maxPoint->x(), dif);
    ASSERT_NEAR(p1->y(), maxPoint->y(), dif);
}

TEST_F(BoundingBoxTest, CalculateMinTest)
{
    Point *points[] = {p0, p1, p2, p3, p4, p5};
    std::set<const Point *> pointsSet(points, points + 6);
    BoundingBox *boundingBox = new BoundingBox(pointsSet);

    Point *minPoint = boundingBox->calMinimumPoint(pointsSet);
    ASSERT_NEAR(p1->x(), minPoint->x(), dif);
    ASSERT_NEAR(p4->y(), minPoint->y(), dif);
}

TEST_F(BoundingBoxTest, ConstructorDoesNotThrowException)
{
    Point *points[] = {p0, p1, p2, p3, p4, p5};
    std::set<const Point *> pointsSet(points, points + 6);
    ASSERT_NO_THROW(new BoundingBox(pointsSet));
}

TEST_F(BoundingBoxTest, TwoAdjacentRectanglesShouldCollide)
{
    ASSERT_TRUE(boxes[0]->collide(boxes[1]));

    ASSERT_TRUE(boxes[1]->collide(boxes[1]));
    ASSERT_TRUE(boxes[1]->collide(boxes[2]));
    ASSERT_TRUE(boxes[1]->collide(boxes[3]));
    ASSERT_TRUE(boxes[1]->collide(boxes[4]));
    ASSERT_TRUE(boxes[1]->collide(boxes[5]));

    ASSERT_TRUE(boxes[2]->collide(boxes[1]));

    ASSERT_TRUE(boxes[3]->collide(boxes[1]));
    ASSERT_TRUE(boxes[3]->collide(boxes[4]));

    ASSERT_TRUE(boxes[4]->collide(boxes[1]));
    ASSERT_TRUE(boxes[4]->collide(boxes[3]));
    ASSERT_TRUE(boxes[4]->collide(boxes[4]));
    ASSERT_TRUE(boxes[4]->collide(boxes[5]));

    ASSERT_TRUE(boxes[5]->collide(boxes[1]));
    ASSERT_TRUE(boxes[5]->collide(boxes[4]));
}

TEST_F(BoundingBoxTest, TwoNonAdjacentRectanglesShouldNotCollide)
{
    ASSERT_FALSE(boxes[0]->collide(boxes[2]));
    ASSERT_FALSE(boxes[0]->collide(boxes[3]));
    ASSERT_FALSE(boxes[0]->collide(boxes[4]));
    ASSERT_FALSE(boxes[0]->collide(boxes[5]));

    ASSERT_FALSE(boxes[2]->collide(boxes[0]));
    ASSERT_FALSE(boxes[2]->collide(boxes[3]));
    ASSERT_FALSE(boxes[2]->collide(boxes[4]));
    ASSERT_FALSE(boxes[2]->collide(boxes[5]));

    ASSERT_FALSE(boxes[3]->collide(boxes[0]));
    ASSERT_FALSE(boxes[3]->collide(boxes[2]));
    ASSERT_FALSE(boxes[3]->collide(boxes[5]));

    ASSERT_FALSE(boxes[4]->collide(boxes[0]));
    ASSERT_FALSE(boxes[4]->collide(boxes[2]));

    ASSERT_FALSE(boxes[5]->collide(boxes[0]));
    ASSERT_FALSE(boxes[5]->collide(boxes[2]));
    ASSERT_FALSE(boxes[5]->collide(boxes[3]));
}
