#include "../src/compound_shape.h"

TEST(CompoundShapeTest, TestArea) {
    Shape* circle = new Circle(
      new TwoDimensionalVector(new Point(0, 0), new Point(3, 4)));

    Shape* rectangle = new Rectangle(
      new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
      new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));

    Shape* triangle = new Triangle(
      new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
      new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));

    Shape* shapes1[] = {circle};
    Shape* compoundShape1 = new CompoundShape(shapes1, 1);
    ASSERT_NEAR(78.54 , compoundShape1->area(), 0.01);

    Shape* shapes2[] = {circle, rectangle};
    Shape* compoundShape2 = new CompoundShape(shapes2, 2);
    ASSERT_NEAR(78.54 + 6, compoundShape2->area(), 0.01);

    Shape* shapes3[] = {circle, rectangle, triangle};
    Shape* compoundShape3 = new CompoundShape(shapes3, 3);
    ASSERT_NEAR(78.54 + 6 + 6, compoundShape3->area(), 0.01);

    delete compoundShape1, compoundShape2, compoundShape3;
}

TEST(CompoundShapeTest, TestPerimeter) {
    Shape* circle = new Circle(
      new TwoDimensionalVector(new Point(0, 0), new Point(3, 4)));

    Shape* rectangle = new Rectangle(
      new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
      new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));

    Shape* triangle = new Triangle(
      new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
      new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));

    Shape* shapes1[] = {circle};
    Shape* compoundShape1 = new CompoundShape(shapes1, 1);
    ASSERT_NEAR(31.42 , compoundShape1->perimeter(), 0.01);

    Shape* shapes2[] = {circle, rectangle};
    Shape* compoundShape2 = new CompoundShape(shapes2, 2);
    ASSERT_NEAR(31.42 + 10, compoundShape2->perimeter(), 0.01);

    Shape* shapes3[] = {circle, rectangle, triangle};
    Shape* compoundShape3 = new CompoundShape(shapes3, 3);
    ASSERT_NEAR(31.42 + 10 + 12, compoundShape3->perimeter(), 0.01);

    delete compoundShape1, compoundShape2, compoundShape3;
}

TEST(CompoundShapeTest, TestInfo) {
    Shape* circle = new Circle(
      new TwoDimensionalVector(new Point(0, 0), new Point(3, 4)));

    Shape* rectangle = new Rectangle(
      new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
      new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));

    Shape* triangle = new Triangle(
      new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
      new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));

    Shape* shapes1[] = {circle};
    Shape* compoundShape1 = new CompoundShape(shapes1, 1);
    ASSERT_EQ("CompoundShape (Circle (Vector ((0.00, 0.00), (3.00, 4.00))))" , compoundShape1->info());

    Shape* shapes2[] = {circle, rectangle};
    Shape* compoundShape2 = new CompoundShape(shapes2, 2);
    ASSERT_EQ("CompoundShape (Circle (Vector ((0.00, 0.00), (3.00, 4.00))), Rectangle (Vector ((0.00, 0.00), (2.00, 0.00)), Vector ((0.00, 0.00), (0.00, 3.00))))", compoundShape2->info());

    Shape* shapes3[] = {circle, rectangle, triangle};
    Shape* compoundShape3 = new CompoundShape(shapes3, 3);
    ASSERT_EQ("CompoundShape (Circle (Vector ((0.00, 0.00), (3.00, 4.00))), Rectangle (Vector ((0.00, 0.00), (2.00, 0.00)), Vector ((0.00, 0.00), (0.00, 3.00))), Triangle (Vector ((3.00, 4.00), (0.00, 0.00)), Vector ((3.00, 0.00), (0.00, 0.00))))", compoundShape3->info());

    delete compoundShape1, compoundShape2, compoundShape3;
}
