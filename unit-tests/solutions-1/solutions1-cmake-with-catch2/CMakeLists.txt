cmake_minimum_required(VERSION 3.14)

# Project name and version
project(MyProject VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include FetchContent module
include(FetchContent)

# Configure Catch2 using FetchContent
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0 # Replace with the latest stable version if needed
)
FetchContent_MakeAvailable(Catch2)

SET(SOURCES
    functions.cpp
)

SET(TEST_SOURCES
    tests/addition-test.cpp
    tests/swap-test.cpp
    tests/calculate-perimeter-test.cpp
)

# Add the main executable
add_executable(MyApp main.cpp ${SOURCES})

# Add the test executable
add_executable(tests ${TEST_SOURCES} ${SOURCES})

# Link Catch2 to the test executable
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# Enable testing and automatically register tests with CTest
include(CTest)
include(Catch)
catch_discover_tests(tests)
