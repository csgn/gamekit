include(FetchContent)

# GTest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.17.0
)
FetchContent_MakeAvailable(googletest)

set(TEST_SOURCES
	base_inventory_unittest.cpp
)
message(STATUS "Test sources: ${TEST_SOURCES}")

add_executable(${PROJECT_NAME}-tests ${TEST_SOURCES})

target_link_libraries(${PROJECT_NAME}-tests
        PRIVATE ${PROJECT_NAME}-static
		gtest
		gmock
        gtest_main
		gmock_main
)

enable_testing()
add_test(NAME ${PROJECT_NAME}-tests COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-tests)
