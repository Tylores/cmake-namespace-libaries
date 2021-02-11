add_library(Base STATIC
    echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::Base ALIAS Base )

# add include directories
target_include_directories(
    EchoBase
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>"
)

# install the target and create export-set
install(
    TARGETS EchoBase
    EXPORT EchoBaseTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# install header file
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*"
)

# generate and install export file
install(
    EXPORT EchoBaseTargets
    FILE EchoBaseTargets.cmake
    NAMESPACE Echo::
    DESTINATION lib/cmake
)
