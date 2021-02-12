add_library(Formal STATIC
    formal_echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::Formal ALIAS Formal )

# add include directories
target_include_directories(
    Formal
    PUBLIC
    "$<INSTALL_INTERFACE:include/echo>"
)

# install the target and create export-set
install(TARGETS Formal
    EXPORT FormalTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# install header file
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DESTINATION "include/echo/formal"
    FILES_MATCHING PATTERN "*.h*"
)

# generate and install export file
install(
    EXPORT FormalTargets
    FILE FormalTargets.cmake
    NAMESPACE Echo::
    DESTINATION lib/cmake
)