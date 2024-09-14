#include <boost/filesystem.hpp>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

// Tests that Foo does Xyz.
TEST(TestTraverseDirectory, DoesXyz) {
  std::cout << boost::filesystem::current_path() << std::endl;
}
