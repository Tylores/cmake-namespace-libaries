add_library(Base STATIC
    echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::Base ALIAS Base )

# add include directories
target_include_directories(
    Base
    PUBLIC
    "$<BUILD_INTERFACE:echo>"
    "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>"
)

# install the target and create export-set
install(
    TARGETS Base
    EXPORT BaseTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/echo
)


install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/echo
    FILES_MATCHING PATTERN "*.h*"
)

# generate and install export file
install(
    EXPORT BaseTargets
    FILE BaseTargets.cmake
    NAMESPACE Echo::
    DESTINATION lib/cmake
)
