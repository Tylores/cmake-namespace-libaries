add_library(base STATIC
    echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::base ALIAS base )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${project_name})

target_include_directories(
    base PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>"
)

# install the target and create export-set
install(
    TARGETS base
    EXPORT baseTargets
    FILE baseTargets.cmake
    NAMESPACE ${project_name}::
    DESTINATION lib/cmake
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)