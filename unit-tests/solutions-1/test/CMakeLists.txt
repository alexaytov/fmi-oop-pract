SET(SOURCES
    "../src/functions/functions.cpp"
)

SET(TEST_SOURCES
    addition-test.cpp
    swap-test.cpp
    calculate-perimeter-test.cpp
)

# Add the test executable
add_executable(unit-tests)

target_sources(
    unit-tests
    PRIVATE
    ${TEST_SOURCES} ${SOURCES}
)

# Link Catch2 to the test executable
target_link_libraries(unit-tests PRIVATE Catch2::Catch2WithMain)

# Automatically discover tests in the test executable
catch_discover_tests(unit-tests)
