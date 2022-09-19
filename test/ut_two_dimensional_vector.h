#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include <gtest/gtest.h>

TEST(TwoDimensionalVectorTeat,Info){
  ASSERT_EQ("Vector ((-8.42, 3.42), (-3.38, 4.30))",(new TwoDimensionalVector(new Point(-8.419, 3.422222),new Point(-3.379999999, 4.3)))->info());
}


TEST(TwoDimensionalVectorTeat,Value) {
  ASSERT_EQ( -8.42 ,(new TwoDimensionalVector(new Point(-8.42, 3.42),new Point(-3.38, 4.3)))->a()->x());
  ASSERT_EQ( 3.42 ,(new TwoDimensionalVector(new Point(-8.42, 3.42),new Point(-3.38, 4.3)))->a()->y());
  ASSERT_EQ( -3.38 ,(new TwoDimensionalVector(new Point(-8.42, 3.42),new Point(-3.38, 4.3)))->b()->x());
  ASSERT_EQ( 4.3 ,(new TwoDimensionalVector(new Point(-8.42, 3.42),new Point(-3.38, 4.3)))->b()->y());
}

TEST(TwoDimensionalVectorTeat,length){
  ASSERT_EQ(2,(new TwoDimensionalVector(new Point(0, 0),new Point(2, 0)))->length());
  ASSERT_EQ(4,(new TwoDimensionalVector(new Point(2, 0),new Point(-2, 0)))->length());
  ASSERT_NEAR(13.51,(new TwoDimensionalVector(new Point(-4.3, 3.42),new Point(2.22, -8.42)))->length(),2);
}

TEST(TwoDimensionalVectorTeat,dot){
  ASSERT_EQ(15,(new TwoDimensionalVector(new Point(0, 0),new Point(5, 1)))->dot((new TwoDimensionalVector(new Point(0, 0),new Point(5, -10)))));
  ASSERT_EQ(-34,(new TwoDimensionalVector(new Point(7, 2),new Point(1, 1)))->dot((new TwoDimensionalVector(new Point(1, 1),new Point(7, -1)))));
}

TEST(TwoDimensionalVectorTeat,DotProductWithAcuteAngleShouldBePositive){
  ASSERT_EQ(16,(
    new TwoDimensionalVector(new Point(0, 0),new Point(4, 4)))->dot((
    new TwoDimensionalVector(new Point(0, 0),new Point(4, 0)))));
  ASSERT_EQ(16,(
    new TwoDimensionalVector(new Point(0, 0),new Point(-4, -4)))->dot((
    new TwoDimensionalVector(new Point(0, 0),new Point(0, -4)))));
  ASSERT_EQ(16,(
    new TwoDimensionalVector(new Point(4, 4),new Point(0, 0)))->dot((
    new TwoDimensionalVector(new Point(4, 0),new Point(0, 0)))));
  ASSERT_EQ(-16,(
    new TwoDimensionalVector(new Point(-2, 4),new Point(2, 4)))->dot((
    new TwoDimensionalVector(new Point(2, 2),new Point(-2, 0)))));
}

TEST(TwoDimensionalVectorTeat,cross){
  ASSERT_EQ(-14,(new TwoDimensionalVector(new Point(0, 0),new Point(1, 3)))->cross((new TwoDimensionalVector(new Point(0, 0),new Point(5, 1)))));
}
