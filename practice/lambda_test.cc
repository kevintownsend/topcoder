#include "lambda.h"

#include "gtest/gtest.h"

namespace {

TEST(HELLO, WORLD) {
  ASSERT_TRUE(has_uppercase("Hello"));
  ASSERT_FALSE(has_uppercase("hello"));

}

} // namespace
