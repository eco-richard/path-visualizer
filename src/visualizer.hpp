#ifndef PATH_VISUALIZER_SRC_VISUALIZER_HPP
#define PATH_VISUALIZER_SRC_VISUALIZER_HPP

#include <cstdint>

#include <raylib.h>

class Visualizer {
  public:
    static void Init(uint32_t sw, uint32_t sh, uint32_t gs);
    static void Draw();
    static void Update();
    static void Close();
  
  private:
    static uint32_t _screen_width;
    static uint32_t _screen_height;
    static uint32_t _grid_size;

    const Color _start_color = GREEN;
    const Color _end_color = RED;
    const Color _wall_color = GRAY;
    const Color _visited_color = BLUE;
    const Color _path_color = ORANGE;

};

#endif // !PATH_VISUALIZER_SRC_VISUALIZER_HPP

