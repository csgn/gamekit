if(WIN32)
	set(GAMEKIT_CSHARP_PROJECT ${GAMEKIT_CSHARP_PROJECT_DIR}/Gamekit.Win64.csproj)
	set(GAMEKIT_CSHARP_TEST_PROJECT ${GAMEKIT_CSHARP_TEST_DIR}/${PROJECT_NAME_FIRST_CAPITALIZED}Tests.Win64.csproj)
else()
	set(GAMEKIT_CSHARP_PROJECT ${GAMEKIT_CSHARP_PROJECT_DIR}/Gamekit.Posix.csproj)
	set(GAMEKIT_CSHARP_TEST_PROJECT ${GAMEKIT_CSHARP_TEST_DIR}/${PROJECT_NAME_FIRST_CAPITALIZED}Tests.Posix.csproj)
endif()

# -----------------------------
# C# Wrapper
# -----------------------------
add_custom_target(${PROJECT_NAME}-csharp ALL
    COMMAND dotnet build ${GAMEKIT_CSHARP_PROJECT} 
        -o ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-csharp/bin
    COMMAND ${CMAKE_COMMAND} -E copy
		${CMAKE_BINARY_DIR}/${PROJECT_NAME}/${GAMEKIT_LIB_NAME}
        ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-csharp/bin/${GAMEKIT_LIB_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Building C# wrapper"
)

# -----------------------------
# C# Tests
# -----------------------------
add_custom_target(${PROJECT_NAME}-csharp-tests ALL
    COMMAND dotnet build ${GAMEKIT_CSHARP_TEST_PROJECT} 
        -o ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-csharp-tests/bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Building C# tests"
)
