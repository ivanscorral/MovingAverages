cmake_minimum_required(VERSION 3.1.0)
project(MovingAverages VERSION 0.1.0)

# --- use C++11

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/MovingAverages)

include_directories()

add_executable(main ${SRC_DIR}/main.cpp)

target_include_directories(main PUBLIC
                            ${PROJECT_SOURCE_DIR}/include/MovingAverages)
target_include_directories(main PUBLIC
                            ${PROJECT_SOURCE_DIR}/src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
