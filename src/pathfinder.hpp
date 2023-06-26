#ifndef PATH_VISUALIZER_SRC_PATHFINDER_HPP
#define PATH_VISUALIZER_SRC_PATHFINDER_HPP

#include <cstdint>
#include <limits>
#include <vector>

struct grid_cell {
  uint32_t row;
  uint32_t col;
  bool is_wall;
  bool is_visited;
  bool is_start;
  bool is_end;
  uint32_t distance;
  grid_cell* previous;
  grid_cell() :
    row(0), col(0), is_wall(false), is_visited(false), is_start(false), 
    is_end(false), distance(std::numeric_limits<uint32_t>::max()),
    previous(nullptr) {}
};

class Pathfinder {
  public:
    using Grid = std::vector<std::vector<grid_cell>>;

  public:
    Pathfinder(int rows, int cols);

    void start(int row, int col);
    void end(int row, int col);
    void wall(int row, int col);
    
    void Dijkstras();
    std::vector<grid_cell> path();

  private:
    bool is_in_grid(int row, int col);

  private:
    Grid _grid;
    grid_cell* _start_node;
    grid_cell* _end_node;
};

#endif // PATH_VISUALIZER_SRC_PATHFINDER_HPP
