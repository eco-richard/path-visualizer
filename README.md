# Path Visualizer

WIP

A minimal pathfinder visualizer using C++ and [raylib](https://www.raylib.com/).

## Building 

To build make sure you have [CMake](https://cmake.org/download/) and [vcpkg](https://vcpkg.io/en/getting-started.html) installed.

```sh
$ git clone https://github.com/eco-richard/path-visualizer.git
$ cd path-visualizer
$ mkdir build && cd build
$ cmake .. -DCMAKE_TOOLCHAIN_FILE="<PATH_TO_VCPKG>/scripts/buildsystems/vcpkg.cmake"
$ make
```

Then to run the binary, run

```sh
$ ./path-visualizer 
```

## Credit

Thank you to [Clément Mihailescu](https://www.youtube.com/channel/UCaO6VoaYJv4kS-TQO_M-N_g) for the idea.
