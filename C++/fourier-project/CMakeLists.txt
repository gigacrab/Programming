cmake_minimum_required(VERSION 3.22)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Ensure Conda environment is active
if(NOT DEFINED ENV{CONDA_PREFIX})
    message(FATAL_ERROR "Conda environment not detected. Please activate it before building.")
endif()
add_compile_options(-Wno-deprecated-declarations)
message(WARNING "Ignored deprecated declarations enabled in CMakeList.txt.")

# Manually set Python paths to Conda
set(Python3_EXECUTABLE "$ENV{CONDA_PREFIX}/bin/python3")
set(Python3_INCLUDE_DIR "$ENV{CONDA_PREFIX}/include/python3.11")
set(Python3_LIBRARY "$ENV{CONDA_PREFIX}/lib/libpython3.11.so")

find_package(Python3 REQUIRED COMPONENTS Interpreter Development NumPy)

include_directories(${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})

# Find SFML
find_package(SFML 3 REQUIRED COMPONENTS Graphics)

# Find matplotlibcpp
#find_path(MATPLOTLIB_CPP_INCLUDE_DIRS matplotlibcpp.h HINTS "/home/littlecrabby/vcpkg/installed/x64-linux/include")
find_path(MATPLOTLIB_CPP_INCLUDE_DIRS "matplotlibcpp.h")

add_executable(main src/main.cpp)

target_include_directories(main PRIVATE ${MATPLOTLIB_CPP_INCLUDE_DIRS})
target_link_libraries(main PRIVATE Python3::Python SFML::Graphics)
target_compile_features(main PRIVATE cxx_std_17)

