file(GLOB_RECURSE TEST_SOURCES "*.cpp")
add_executable(gamekit-tests ${TEST_SOURCES})

target_link_libraries(gamekit-tests
        PRIVATE gamekit-static
		gtest
		gmock
        gtest_main
		gmock_main
)

gtest_discover_tests(gamekit-tests)
