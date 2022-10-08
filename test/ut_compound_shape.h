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
}

TEST(CompoundShapeTest, TestBFS) {

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

  Iterator* bfs = c1->createBFSIterator();

  ASSERT_EQ(6, bfs->currentItem()->area());

  Iterator* tri = bfs;

  ASSERT_EQ(6, tri->currentItem()->area());
}


TEST(CompoundShapeTest, AddShape) {
    Shape* circle = new Circle(
      new TwoDimensionalVector(new Point(0, 0), new Point(3, 4)));

    Shape* rectangle = new Rectangle(
      new TwoDimensionalVector(new Point(0, 0),new Point(1, 0)),
      new TwoDimensionalVector(new Point(0, 0),new Point(0, 1)));

    Shape* triangle = new Triangle(
      new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
      new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));

    Shape* shapes1[] = {circle};
    Shape* compoundShape1 = new CompoundShape(shapes1, 1);
    ASSERT_NEAR(78.54 , compoundShape1->area(), 0.01);
    compoundShape1->addShape(rectangle);

    ASSERT_NEAR(78.54 + 1, compoundShape1->area(), 0.01);

    compoundShape1->addShape(triangle);
    ASSERT_NEAR(78.54 + 1 + 6, compoundShape1->area(), 0.01);

    delete compoundShape1;
}

TEST(CompoundShapeTest, DeleteShape) {
// 78.54
    Shape* cir = new Circle(
      new TwoDimensionalVector(new Point(0, 0), new Point(3, 4)));
// 1
    Shape* rec = new Rectangle(
      new TwoDimensionalVector(new Point(0, 0),new Point(1, 0)),
      new TwoDimensionalVector(new Point(0, 0),new Point(0, 1)));
// 4
    Shape* rec1 = new Rectangle(
      new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)),
      new TwoDimensionalVector(new Point(0, 0),new Point(0, 2)));
// 9
    Shape* rec2 = new Rectangle(
      new TwoDimensionalVector(new Point(0, 0),new Point(3, 0)),
      new TwoDimensionalVector(new Point(0, 0),new Point(0, 3)));
// 6
    Shape* tri= new Triangle(
      new TwoDimensionalVector(new Point(3, 4),new Point(0, 0)),
      new TwoDimensionalVector(new Point(3, 0),new Point(0, 0)));

    Shape* shapes1[] = {cir};
    Shape* c4 = new CompoundShape(shapes1, 1);
    c4->addShape(rec);
    c4->addShape(tri);
    Shape* shapes2[] = {c4,rec1};
    Shape* c2 = new CompoundShape(shapes2, 2);
    Shape* c3 = new CompoundShape(&rec2, 1);
    // c3->addShape(rec2);
    Shape* c1 = new CompoundShape(&c2, 1);
    // c1->addShape(c2);
    c1->addShape(c3);
    ASSERT_NEAR(78.54 + 1 + 6, c4->area(), 0.01);
    ASSERT_NEAR(78.54 + 1 + 6 + 4, c2->area(), 0.01);
    ASSERT_NEAR(9, c3->area(), 0.01);
    ASSERT_NEAR(78.54 + 1 + 6 + 4 + 9, c1->area(), 0.01);
    /*
    *                  c1
    *                /    \
    *             c2        c3
    *            /  \         \
    *          c4    rec1     rec2
    *        /  |  \
    *      cir rec tri
    */
    c1->deleteShape(c3);
    //PASS
    ASSERT_NEAR(78.54 + 1 + 6 + 4 + 0, c1->area(), 0.01);
    c1->addShape(c3);
    c1->deleteShape(cir);
    //Fail
    ASSERT_NEAR(0 + 1 + 6 + 4 + 9, c1->area(), 0.01);

    delete c1;
}
