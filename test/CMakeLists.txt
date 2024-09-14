add_executable(fileo_tests 
    test_traverse_directory.cpp
)
target_link_libraries(fileo_tests
    PRIVATE
        Boost::filesystem
)