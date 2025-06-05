cmake_minimum_required(VERSION 3.10)

project(MyWxWidgetsApp)

# Find wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Add the wxWidgets flags to the compiler and linker
include(${wxWidgets_USE_FILE})

# Define the source files
set(SOURCES
    src/main.cpp
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link wxWidgets to your executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

