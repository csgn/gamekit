set(SOURCES
	gamekit.cpp
)

message(STATUS "Sources: ${SOURCES}")

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME}
        PUBLIC 
			${GAMEKIT_INCLUDE_DIR}
        PRIVATE 
			${GAMEKIT_SOURCE_DIR}
)
target_compile_definitions(${PROJECT_NAME} PRIVATE GAMEKIT_EXPORTS)
