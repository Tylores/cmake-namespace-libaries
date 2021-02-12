add_library(base STATIC
    echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::base ALIAS base )

# install the target and create export-set
install(
    TARGETS Base
    EXPORT BaseTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION ${project_name}
)


install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/echo
    DESTINATION ${project_name}
    FILES_MATCHING PATTERN "*.h*"
)

# generate and install export file
install(
    EXPORT BaseTargets
    FILE BaseTargets.cmake
    NAMESPACE ${project_name}::
    DESTINATION lib/cmake
)
