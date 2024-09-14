#include <vector>
#include <iostream>
#include <boost/filesystem.hpp>
#include <gtest/gtest.h>

// Tests that Foo does Xyz.
TEST(TestTraverseDirectory, DoesXyz) {
    std::cout << boost::filesystem::current_path() << std::endl;
}
