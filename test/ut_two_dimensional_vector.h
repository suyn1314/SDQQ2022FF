#include "../src/point.h"
#include "../src/two_dimensional_vector.h"
#include <gtest/gtest.h>

TEST(TwoPointTestA,Info){
  //TwoDimensionalVector two_dimensional_vector (new Point(-4.468, -3.471), new Point(4.468, 3.471));
  ASSERT_EQ("Vector ((-8.42, 3.42), (-3.38, 4.30))",(new TwoDimensionalVector(new Point(-8.42, 3.42),new Point(-3.38, 4.3)))->info());
}

/*
TEST(TwoDimensionalVectorTeat,ValueA) {
  ASSERT_EQ( 24.5, ( new TwoDimensionalVector(
    new Point(-8.42, 3.42),
    new Point(-3.38, 4.3))->a();
}

TEST(TwoDimensionalVectorTeat,Info) {
  ASSERT_EQ("Vector ((-8.42, 3.42), (-3.38, 4.30))",( new TwoDimensionalVector(new Point(-8.42, 3.42),new Point(-3.38, 4.3))->info();
}
*/
