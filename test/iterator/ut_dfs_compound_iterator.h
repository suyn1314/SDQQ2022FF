#include "../../src/iterator/dfs_compound_iterator.h"
#include "../../src/iterator/factory/dfs_iterator_factory.h"
#include "../../src/compound_shape.h"
#include "../../src/shape.h"

class DFSCompoundIteratorTest : public ::testing::Test
{
protected:
    Point *p1, *p2, *p3, *p4, *p5;
    TwoDimensionalVector *vec1, *vec2, *vec3, *vec4;
    CompoundShape *c1, *c2;
    Iterator *it;

    void SetUp() override
    {
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);
        p4 = new Point(0, 3);
        p5 = new Point(3, 0);

        vec1 = new TwoDimensionalVector(p1, p2);//(0, 0)(0, 5)
        vec2 = new TwoDimensionalVector(p1, p3);//(0, 0)(5, 0)
        vec3 = new TwoDimensionalVector(p1, p4);//(0, 0)(0, 3)
        vec4 = new TwoDimensionalVector(p1, p5);//(0, 0)(3, 0)

        Shape* tri = new Triangle(vec3,vec4); //4.5
        Shape* rec = new Rectangle(vec1,vec2);//25
        Shape* cri = new Circle(vec3);       //3*3*M_PI

        Shape* c1 = new CompoundShape(&tri, 1);
        c1->addShape(rec);


        Shape* c2 = new CompoundShape(&c1, 1);
        c2->addShape(cri);
/*
           c2
          /   \
        c1    cri
      /    \
   tri     rec
*/
        it = c2->createIterator(new DFSIteratorFactory());
    }

    void TearDown() override
    {
        delete it;
        delete c1, c2;
        delete p1, p2, p3, p4, p5;
        delete vec1, vec2, vec3, vec4;
    }
};

TEST_F(DFSCompoundIteratorTest, CurrentItemShouldBeCorrect)
{
    ASSERT_EQ(4.5 + 25, it->currentItem()->area());
}

TEST_F(DFSCompoundIteratorTest, NextShouldBeCorrect)
{
    it->next();
    ASSERT_EQ(4.5, it->currentItem()->area());

    it->next();
    ASSERT_EQ(25, it->currentItem()->area());

    it->next();
    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
}

TEST_F(DFSCompoundIteratorTest, IsDoneShouldBeCorrect)
{
    it->next();
    it->next();
    it->next();
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST_F(DFSCompoundIteratorTest, CurrentItemShouldThrowExceptionWhenIsDone)
{
    it->next();
    it->next();
    it->next();
    it->next();
    ASSERT_ANY_THROW(it->currentItem());
}

TEST_F(DFSCompoundIteratorTest, NextShouldThrowExceptionWhenIsDone)
{
    it->next();
    it->next();
    it->next();
    it->next();
    ASSERT_ANY_THROW(it->next());
}
