
# Get GoogleTest from vcpkg 
find_package(GTest CONFIG REQUIRED)

# Add the testnig executable
add_executable(main_test main_test.cpp)

# Allow the executable to be found by ctest
add_test(MainTest main_test)

# Link googletest libraries
target_link_libraries(main_test
  PRIVATE
  GTest::gtest
  GTest::gtest_main
  GTest::gmock
  GTest::gmock_main)
