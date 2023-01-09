cmake_minimum_required(VERSION 3.1.0)
project(MovingAverages VERSION 0.1.0)

# --- use C++11

set (CMAKE_CXX_STANDARD 11)

# --- auto-ignore build directory

include(CTest)
enable_testing()

add_executable(MovingAverages include/generate_data.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
