#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "pathfinder.hpp"

TEST(PathfinderTest, TestStartAndEnd) {
  // Initialize pathfinder
  Pathfinder pf(10, 10);

  pf.start(0, 0); // Start at top corner
  pf.end(9, 9); // End at bottom corner

  auto path = pf.path();

  ASSERT_EQ(path.size(), 0); // Path has not been calculated yet

  pf.Dijkstras(); // running path finding algorithm

  path = pf.path();
  
  ASSERT_EQ(path.size(), 19);

  ASSERT_TRUE(path.front().is_start);
  ASSERT_TRUE(path.back().is_end);

}

TEST(PathfinderTest, TestWall) {
  Pathfinder pf(10, 10);

  pf.start(0, 0);
  pf.end(9, 9);

  // Set a wall between the start and end nodes
  for (int i = 1; i < 9; i++) {
      pf.wall(i, i);
  }

  pf.Dijkstras();

  auto path = pf.path();
  ASSERT_EQ(path.size(), 27); // Path length should be 27 for the given grid with walls

  ASSERT_TRUE(path.front().is_start);
  ASSERT_TRUE(path.back().is_end);
}

