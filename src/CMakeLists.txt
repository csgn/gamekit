set(SOURCES
	gamekit.cpp
	systems/inventory/dynamic_inventory/dynamic_inventory_api.cpp
)

message(STATUS "Sources: ${SOURCES}")
add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME}
        PUBLIC ${GAMEKIT_INCLUDE_DIR}
        PRIVATE ${GAMEKIT_SOURCE_DIR}
)

add_library(${PROJECT_NAME}-static STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME}-static
        PUBLIC ${GAMEKIT_INCLUDE_DIR}
        PRIVATE ${GAMEKIT_SOURCE_DIR}
)
