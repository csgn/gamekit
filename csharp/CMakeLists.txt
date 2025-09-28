# -----------------------------
# C# Wrapper
# -----------------------------

add_custom_target(${PROJECT_NAME}-csharp
	# build project
    COMMAND dotnet build ${GAMEKIT_CSHARP_PROJECT} 
        -o ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-csharp/bin

	# copy native dynamic library into the csharp bin directory
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${CMAKE_BINARY_DIR}/${PROJECT_NAME}/${GAMEKIT_LIB_NAME}
        ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-csharp/bin/${GAMEKIT_LIB_NAME}

    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Building C# wrapper"
)

add_custom_target(${PROJECT_NAME}-csharp-tests
    COMMAND dotnet build ${GAMEKIT_CSHARP_TEST_PROJECT} 
        -o ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-csharp-tests/bin

	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${CMAKE_BINARY_DIR}/${PROJECT_NAME}/${GAMEKIT_LIB_NAME}
		${CMAKE_BINARY_DIR}/${PROJECT_NAME}-csharp-tests/${GAMEKIT_LIB_NAME}

    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Building C# tests"
)
