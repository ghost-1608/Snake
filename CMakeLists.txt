cmake_minimum_required(VERSION 3.24)
project(Snake)

set(CMAKE_CXX_STANDARD 23)

add_executable(Snake src/main.cpp src/Engine.cpp src/draw.cpp src/input.cpp src/SnakeSection.cpp headers/Engine.hpp headers/SnakeSection.hpp src/update.cpp src/Apple.cpp headers/Apple.hpp headers/MACROS.hpp)

# set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/Program Files/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(headers "C:/Program Files/SFML-2.5.1/include")
target_link_libraries(Snake sfml-system sfml-window sfml-graphics sfml-audio)