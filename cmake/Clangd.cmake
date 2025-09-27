# -------------------------------
# Clangd Configuration
# -------------------------------
if(EXISTS "${CMAKE_SOURCE_DIR}/.clangd.in")
    configure_file(
        "${CMAKE_SOURCE_DIR}/.clangd.in"
        "${CMAKE_BINARY_DIR}/.clangd"
        @ONLY
    )

	add_custom_target(clangd_link ALL
			COMMAND ${CMAKE_COMMAND} -E create_symlink
					${CMAKE_BINARY_DIR}/.clangd
					${CMAKE_SOURCE_DIR}/.clangd
			DEPENDS ${CMAKE_BINARY_DIR}/.clangd
			COMMENT "Symlink .clangd into project root"
	)
endif()

