add_library(Base STATIC
    echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::Base ALIAS Base )

# add include directories
target_include_directories(
    Base
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>"
)

# install the target and create export-set
install(
    TARGETS Base
    EXPORT BaseTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)


install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DESTINATION include/echo/base
    FILES_MATCHING PATTERN "*.h*"
)

# generate and install export file
install(
    EXPORT BaseTargets
    FILE BaseTargets.cmake
    NAMESPACE Echo::
    DESTINATION lib/cmake
)
