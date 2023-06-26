
#include <algorithm>
#include <ios>
#include <queue>

#include "pathfinder.hpp"

Pathfinder::Pathfinder(int rows, int cols) :
  _start_node{}, _end_node{} {
  // Initialize grid to designated size
  _grid.resize(rows, std::vector<grid_cell>(cols, grid_cell()));

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
       _grid[i][j].row = i;
       _grid[i][j].col = j;
    }
  }
}

void Pathfinder::start(int row, int col) {
  if (!is_in_grid(row, col)) return;

  _grid[row][col].is_end = false;
  _grid[row][col].is_start = true;
  _start_node = &_grid[row][col];
}

void Pathfinder::end(int row, int col) {
  if (!is_in_grid(row, col)) return;
  
  _grid[row][col].is_start = false;
  _grid[row][col].is_end = true;
  _end_node = &_grid[row][col];
}

void Pathfinder::wall(int row, int col) {
  if (!is_in_grid(row, col)) return;
 
  if (_grid[row][col].is_start || _grid[row][col].is_end) return;

  _grid[row][col].is_wall = !_grid[row][col].is_wall;
}

void Pathfinder::Dijkstras() {
  std::priority_queue<std::pair<int, grid_cell*>, std::vector<std::pair<int, grid_cell*>>, std::greater<std::pair<int, grid_cell*>>> pq;

  // Set the distance of the start node to 0 and insert it
  _start_node->distance = 0;
  pq.push({0, _start_node});

  // Main loop of Dijkstras
  while (!pq.empty()) {
    // Get node with smallest distance
    auto current = pq.top().second;
    pq.pop();

    // If current is end, break out of the loop
    if (current == _end_node)
      break;

    // If the current node has already been visited
    if (current->is_visited)
      continue;

    // Set current to be visited
    current->is_visited = true;

    std::vector<std::pair<int, int>> neighbors = {
      {current->row - 1, current->col},
      {current->row + 1, current->col},
      {current->row, current->col - 1},
      {current->row, current->col + 1},
    };

    for (const auto& [row, col] : neighbors) {
      if (!is_in_grid(row, col)) continue;

      auto neighbor = &_grid[row][col];

      if (neighbor->is_wall || neighbor->is_visited)
        continue;

      int new_distance = current->distance + 1;
      if (new_distance < neighbor->distance) {
        neighbor->distance = new_distance;
        neighbor->previous = current;
        pq.push({new_distance, neighbor});
      }
    }
  }

}

std::vector<grid_cell> Pathfinder::path() {
  std::vector<grid_cell> path;

  if (!_end_node->is_end || !_end_node->previous) return path;

  grid_cell* current = _end_node;

  while (current) {
    path.push_back(*current);
    current = current->previous;
  }

  std::reverse(path.begin(), path.end());
  return path;
}

bool Pathfinder::is_in_grid(int row, int col) {
  return row >= 0 && col >= 0 && row < _grid.size() &&
    col < _grid[0].size();
}
