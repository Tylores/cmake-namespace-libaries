add_library(Base STATIC
    echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::Base ALIAS Base )

# install the target and create export-set
install(
    TARGETS Base
    EXPORT BaseTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/${project_name}
)


install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/base
    DESTINATION include/${project_name}
    FILES_MATCHING PATTERN "*.h*"
)

# generate and install export file
install(
    EXPORT BaseTargets
    FILE BaseTargets.cmake
    NAMESPACE Echo::
    DESTINATION lib/cmake
)
