add_library(Formal STATIC
    formal_echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::Formal ALIAS Formal )

# add include directories
target_include_directories(
    EchoFormal
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>"
)

# install the target and create export-set
install(TARGETS EchoFormal
    EXPORT EchoFormalTargets
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
    EXPORT EchoFormalTargets
    FILE EchoFormalTargets.cmake
    NAMESPACE Echo::
    DESTINATION lib/cmake
)