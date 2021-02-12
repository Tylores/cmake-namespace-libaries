add_library(formal STATIC
    formal_echo.cpp
)

# Create ALIAS targets.
add_library( echo::formal ALIAS formal )

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
    NAMESPACE echo::
    DESTINATION lib/cmake
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)