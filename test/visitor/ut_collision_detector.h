#include "../../src/point.h"
#include "../../src/two_dimensional_vector.h"
#include "../../src/triangle.h"
#include "../../src/rectangle.h"
#include "../../src/circle.h"
#include "../../src/compound_shape.h"
#include "../../src/visitor/shape_visitor.h"
#include "../../src/visitor/collision_detector.h"

class CollisionDetectorTest : public ::testing::Test
{
protected:
    Point *p0, *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11;
    TwoDimensionalVector *v1, *v2, *v3, *v4, *v5, *v6;
    Triangle *tri;
    Rectangle *rec;
    Circle *cri, *cri1;
    CompoundShape *c1, *c2, *c3;
    CollisionDetector *detector;

    void SetUp() override
    {
        p0 = new Point(0, 0);
        p1 = new Point(8, 2);
        p2 = new Point(0, 0);
        p3 = new Point(2, 0);
        p4 = new Point(2, 2);
        p5 = new Point(3, 2);
        p6 = new Point(2, 2);
        p7 = new Point(2, 7);
        p8 = new Point(2, 6);
        p9 = new Point(1, 6);
        p10 = new Point(8, 5);
        p11 = new Point(-1, -1);
        v1 = new TwoDimensionalVector(p0, p1);
        v2 = new TwoDimensionalVector(p2, p3);
        v3 = new TwoDimensionalVector(p4, p5);
        v4 = new TwoDimensionalVector(p6, p7);
        v5 = new TwoDimensionalVector(p8, p9);
        v6 = new TwoDimensionalVector(p10, p11);
        tri = new Triangle(v1, v2);
        rec = new Rectangle(v3, v4);
        cri = new Circle(v5);
        cri1 = new Circle(v6);

        Shape *shapes2[] = {tri};
        c2 = new CompoundShape(shapes2, 1);
        Shape *shapes3[] = {rec, cri, tri};
        c3 = new CompoundShape(shapes3, 3);
        Shape *shapes1[] = {c2, c3};
        c1 = new CompoundShape(shapes1, 2);

        detector = new CollisionDetector(cri1);
    }

    void TearDown() override
    {
        delete p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, v1, v2, v3, v4, v5, v6, tri, rec, cri, cri1, c2, c3, c1;
    }
};

TEST_F(CollisionDetectorTest, VisitCircleTest)
{
    detector->visitCircle(cri);
    std::vector<Shape *> collidedShapes = detector->collidedShapes();
    ASSERT_EQ(1, collidedShapes.size());
    ASSERT_EQ(cri, collidedShapes[0]);

}

TEST_F(CollisionDetectorTest, VisitTriangleTest)
{
    detector->visitTriangle(tri);
    std::vector<Shape *> collidedShapes = detector->collidedShapes();
    ASSERT_EQ(1, collidedShapes.size());
    ASSERT_EQ(tri, collidedShapes[0]);
}

TEST_F(CollisionDetectorTest, VisitRectangleTest)
{
    detector->visitRectangle(rec);
    std::vector<Shape *> collidedShapes = detector->collidedShapes();
    ASSERT_EQ(1, collidedShapes.size());
    ASSERT_EQ(rec, collidedShapes[0]);
}

TEST_F(CollisionDetectorTest, VisitCompoundShapeTest)
{
    detector->visitCompoundShape(c3);
    std::vector<Shape *> collidedShapes = detector->collidedShapes();
    ASSERT_EQ(3, collidedShapes.size());
    ASSERT_EQ(rec, collidedShapes[0]);
    ASSERT_EQ(cri, collidedShapes[1]);
    ASSERT_EQ(tri, collidedShapes[2]);
}

TEST_F(CollisionDetectorTest, VisitTriangleOnUncollidedShouldHaveCollidedShapesEmptyTest)
{
    CollisionDetector *visitorTriangle = new CollisionDetector(tri);
    visitorTriangle->visitCircle(cri);
    std::vector<Shape *> collidedShapes = visitorTriangle->collidedShapes();
    ASSERT_TRUE(collidedShapes.empty());
}

TEST_F(CollisionDetectorTest, VisitConstructorDoesNotThrowException)
{
    ASSERT_NO_THROW(new CollisionDetector(tri));
    ASSERT_NO_THROW(new CollisionDetector(rec));
    ASSERT_NO_THROW(new CollisionDetector(cri));
    ASSERT_NO_THROW(new CollisionDetector(c2));
    ASSERT_NO_THROW(new CollisionDetector(c1));
}
