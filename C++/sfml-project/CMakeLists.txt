cmake_minimum_required(VERSION 3.22)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SFML 3 REQUIRED COMPONENTS Graphics)
find_path(MATPLOTLIB_CPP_INCLUDE_DIRS "matplotlibcpp.h")
target_include_directories(main PRIVATE ${MATPLOTLIB_CPP_INCLUDE_DIRS})

add_executable(main src/main.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)