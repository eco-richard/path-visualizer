
# Get GoogleTest from vcpkg 
find_package(GTest CONFIG REQUIRED)

# Add the testnig executable
add_executable(pathfinder_test pathfinder_test.cpp
  ${PROJECT_SOURCE_DIR}/src/pathfinder.cpp
  )

# Allow the executable to be found by ctest
add_test(PathfinderTest pathfinder_test)

# Link googletest libraries
target_link_libraries(pathfinder_test
  PRIVATE
  GTest::gtest
  GTest::gtest_main
  GTest::gmock
  GTest::gmock_main)

# Add src directory to the include path of the tests
target_include_directories(pathfinder_test
  PRIVATE
  ${PROJECT_SOURCE_DIR}/src)
