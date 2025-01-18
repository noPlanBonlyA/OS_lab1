#include <gtest/gtest.h>

#include "dmitrievmyshell/HelloWorld.hpp"

namespace dmitrievmyshell {

TEST(HelloWorld, ExactMatch) {
  ASSERT_EQ(HelloWorld(), "Hello, World!");
}

}  // namespace dmitrievmyshell
