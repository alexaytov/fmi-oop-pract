cmake_minimum_required(VERSION 3.10)
project(main_project)

add_executable(main_project main.cpp)

# Specify the path to the mathlib directory
set(MATHLIB_DIR ../mathlib/build)

# Find the mathlib library
find_library(MATHLIB mathlib PATHS ${MATHLIB_DIR})

# Include the mathlib header files
include_directories(${MATHLIB_DIR}/../)

# Link the mathlib library
target_link_libraries(main_project ${MATHLIB})