cmake_minimum_required(VERSION 3.23)
project(QuadVisuals)

set(CMAKE_CXX_STANDARD 17)

add_executable(QuadVisuals main.cpp)

find_package(nlohmann_json REQUIRED)
target_link_libraries(QuadVisuals PRIVATE nlohmann_json::nlohmann_json)