add_library(Base STATIC
    echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::Base ALIAS Base )

target_include_directories(
    Base PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>"
)

# install the target and create export-set
install(
    TARGETS Base
    EXPORT BaseTargets
    FILE BaseTargets.cmake
    NAMESPACE ${project_name}::
    DESTINATION lib/cmake
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)