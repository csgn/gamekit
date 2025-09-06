file(GLOB_RECURSE TEST_SOURCES "*.cpp")
add_executable(gamekit-tests ${TEST_SOURCES})

target_link_libraries(gamekit-tests
        PRIVATE gamekit-static
        gtest_main
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(gamekit-tests)