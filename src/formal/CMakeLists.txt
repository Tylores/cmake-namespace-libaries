add_library(formal STATIC
    formal_echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::formal ALIAS formal )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${project_name})

target_include_directories(
    formal PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>"
)

# install the target and create export-set
install(
    TARGETS formal
    EXPORT formalTargets
    FILE formalTargets.cmake
    NAMESPACE ${project_name}::
    DESTINATION lib/cmake
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)