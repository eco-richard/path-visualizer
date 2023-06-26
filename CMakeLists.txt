cmake_minimum_required(VERSION 3.21)

# Set C++ Standard to 20
set(CMAKE_CXX_STANDARD 20)

# Require C++ Standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile commands (gives autocomplete for neovim(I use neovim btw))
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project name and language
project(
  path-visualizer
  VERSION 0.1.0
  HOMEPAGE_URL "https://github.com/eco-richard/path-visualizer"
  LANGUAGES CXX)

find_package(raylib CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

enable_testing()

add_subdirectory(test)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  raylib)

