find_package(GTest REQUIRED)

add_executable(fileo_tests 
    test_traverse_directory.cpp
)

target_link_libraries(fileo_tests
    PRIVATE
        Boost::filesystem
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(fileo_tests)