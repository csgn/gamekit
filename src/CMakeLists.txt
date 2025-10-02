set(SOURCES
	gamekit.cpp

	# api
	api/systems/inventory/base_inventory_api.cpp
	api/systems/inventory/base_inventory_settings_api.cpp
	api/systems/inventory/base_inventory_slot_api.cpp

	api/systems/inventory/static_inventory/static_inventory_api.cpp
	api/systems/inventory/static_inventory/static_inventory_settings_api.cpp
	api/systems/inventory/static_inventory/static_inventory_slot_api.cpp

	api/systems/inventory/dynamic_inventory/dynamic_inventory_api.cpp
	api/systems/inventory/dynamic_inventory/dynamic_inventory_settings_api.cpp
	api/systems/inventory/dynamic_inventory/dynamic_inventory_slot_api.cpp
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
