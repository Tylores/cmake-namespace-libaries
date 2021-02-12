add_library(Formal STATIC
    formal_echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::Formal ALIAS Formal )

target_include_directories(
    Formal PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>"
)

# install the target and create export-set
install(
    TARGETS Formal
    EXPORT FormalTargets
    FILE FormalTargets.cmake
    NAMESPACE ${project_name}::
    DESTINATION lib/cmake
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)