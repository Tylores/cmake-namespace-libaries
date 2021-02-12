add_library(Formal STATIC
    formal_echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::Formal ALIAS Formal )

# add include directories
target_include_directories(
    Formal
    PUBLIC
    "$<BUILD_INTERFACE:formal>"
    "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>"
)

# install the target and create export-set
install(TARGETS Formal
    EXPORT FormalTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/formal
)

# install header file
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/formal
    FILES_MATCHING PATTERN "*.h*"
)

# generate and install export file
install(
    EXPORT FormalTargets
    FILE FormalTargets.cmake
    NAMESPACE Echo::
    DESTINATION lib/cmake
)