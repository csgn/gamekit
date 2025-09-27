file(GLOB_RECURSE SOURCES "*.cpp")

add_library(gamekit SHARED ${SOURCES})
target_include_directories(gamekit
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        PRIVATE ${PROJECT_SOURCE_DIR}/src
)

add_library(gamekit-static STATIC ${SOURCES})
target_include_directories(gamekit-static
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        PRIVATE ${PROJECT_SOURCE_DIR}/src
)
