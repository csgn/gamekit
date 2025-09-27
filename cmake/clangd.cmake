# -------------------------------
# Clangd Configuration
# -------------------------------
if(EXISTS "${CMAKE_SOURCE_DIR}/.clangd.in")
    configure_file(
        "${CMAKE_SOURCE_DIR}/.clangd.in"
        "${CMAKE_BINARY_DIR}/.clangd"
        @ONLY
    )

	if(WIN32)
		add_custom_target(clangd_copy ALL
				COMMAND ${CMAKE_COMMAND} -E copy
				${CMAKE_BINARY_DIR}/.clangd
				${CMAKE_SOURCE_DIR}/.clangd
				DEPENDS ${CMAKE_BINARY_DIR}/.clangd
				COMMENT "Copy .clangd into project root (Windows)"
		)
	else()
		add_custom_target(clangd_link ALL
				COMMAND ${CMAKE_COMMAND} -E create_symlink
				${CMAKE_BINARY_DIR}/.clangd
				${CMAKE_SOURCE_DIR}/.clangd
				DEPENDS ${CMAKE_BINARY_DIR}/.clangd
				COMMENT "Symlink .clangd into project root"
		)
	endif()
endif()

