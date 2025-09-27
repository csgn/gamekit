# -------------------------------
# Commands
# -------------------------------

# clang-format
find_program(CLANG_FORMAT clang-format-17)
message(STATUS "CLANG_FORMAT = ${CLANG_FORMAT}")
if(CLANG_FORMAT)
    file(GLOB_RECURSE ALL_CXX_SOURCE_FILES *.cpp *.h)
    add_custom_target(
        format
        COMMAND ${CLANG_FORMAT} -i ${ALL_CXX_SOURCE_FILES}
        COMMENT "Formatting all C++ files..."
    )
endif()
