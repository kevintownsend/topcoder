#include "random_walk.h"
#include "gtest/gtest.h"

using namespace std;

namespace {
TEST(STEP, SIMPLE) {
  RandomWalk walker(10, 10, 10, 10);

  pair<int, int> result = walker.Step(20, 4);

  EXPECT_EQ(result.first, 10);
  EXPECT_EQ(result.second, 1);

}
}
