#include <gtest/gtest.h>

#include "foo.hpp"

TEST(UnitTest, foo) {
  EXPECT_EQ(foo(), 42);
}

