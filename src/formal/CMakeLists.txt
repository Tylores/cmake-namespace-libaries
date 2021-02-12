add_library(Formal STATIC
    formal_echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::Formal ALIAS Formal )

# install the target and create export-set
install(TARGETS Formal
    EXPORT FormalTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/${project_name}
)

# install header file
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/${project_name}
    DESTINATION include/${project_name}
    FILES_MATCHING PATTERN "*.h*"
)

# generate and install export file
install(
    EXPORT FormalTargets
    FILE FormalTargets.cmake
    NAMESPACE Echo::
    DESTINATION lib/cmake
)