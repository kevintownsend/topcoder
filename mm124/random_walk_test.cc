#include "random_walk.h"
#include "gtest/gtest.h"

using namespace std;

namespace {
TEST(STEP, SIMPLE) {
  RandomWalk walker;

  pair<int, int> result = walker.Step();

  EXPECT_EQ(result.first, -1);

}
}
