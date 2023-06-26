#ifndef PATH_VISUALIZER_SRC_VISUALIZER_HPP
#define PATH_VISUALIZER_SRC_VISUALIZER_HPP

#include <cstdint>

#include <raylib.h>

class Visualizer {
  public:
    Visualizer();
    static void Init(uint32_t sw, uint32_t sh, uint32_t gs);
    static void DrawGrid();
    static void Loop();

    ~Visualizer();
    
  private:
    const uint32_t _screen_width;
    const uint32_t _screen_height;
    const uint32_t _grid_size;

    const Color _start_color = GREEN;
    const Color _end_color = RED;
    const Color _wall_color = GRAY;
    const Color _visited_color = BLUE;
    const Color _path_color = ORANGE;

};

#endif // !PATH_VISUALIZER_SRC_VISUALIZER_HPP

