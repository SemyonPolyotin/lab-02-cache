// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <cache.hpp>

TEST(Example, EmptyTest) {
  Experiment cache;
  cache.Strait();
  std::cout << cache;
  cache.Reverse();
  std::cout << cache;
  cache.Random();
  std::cout << cache;
  EXPECT_TRUE(true);
}
