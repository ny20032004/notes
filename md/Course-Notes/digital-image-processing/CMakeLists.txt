cmake_minimum_required(VERSION 2.8)
project(digital-image-processing CXX)

configure_file(demos/lena.rgb.bmp
               ${CMAKE_CURRENT_BINARY_DIR}/lena.rgb.bmp
               COPYONLY)

configure_file(demos/lena.gray.bmp
               ${CMAKE_CURRENT_BINARY_DIR}/lena.gray.bmp
               COPYONLY)

include_directories(src/)

add_library(base src/base.cpp)
add_library(filter src/filter.cpp)

add_executable(base_processing demos/base_processing.cpp)
add_executable(similar_compare demos/similar_compare.cpp)
add_executable(smooth demos/smooth.cpp)

target_link_libraries(base_processing base)
target_link_libraries(similar_compare base)
target_link_libraries(smooth base filter)
