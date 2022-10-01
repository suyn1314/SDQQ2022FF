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

TEST(CompoundShapeTest, TestDFS) {

  Shape* rectangle1 = new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));

  Shape* rectangle2 = new Rectangle(
    new TwoDimensionalVector(new Point(0, 0),new Point(1, 0)),
    new TwoDimensionalVector(new Point(0, 0),new Point(0, 1)));

  Shape* triangle1 = new Triangle(
    new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
    new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));

  Shape* triangle2 = new Triangle(
    new TwoDimensionalVector(new Point(1, 1),new Point(0, 0)),
    new TwoDimensionalVector(new Point(1, 0),new Point(0, 0)));

  Shape* shapes1[] = {triangle1};
  Shape* shapes2[] = {triangle2, rectangle1, rectangle2};
  Shape* c2 = new CompoundShape(shapes1, 1);
  Shape* c3 = new CompoundShape(shapes2, 3);
  Shape* shapes3[] = {c2, c3};
  Shape* c1 = new CompoundShape(shapes3, 2);

  Iterator* dfs = c1->createDFSIterator();

  ASSERT_EQ(6, dfs->currentItem()->area());

  Iterator* tri = dfs;

  ASSERT_EQ(6, tri->currentItem()->area());

  dfs->next();

  ASSERT_EQ(0.5 + 6 + 1, dfs->currentItem()->area());


}
