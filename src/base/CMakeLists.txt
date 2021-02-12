add_library(base STATIC
    echo.cpp
)

# Create ALIAS targets.
add_library( echo::base ALIAS base )

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
    NAMESPACE echo::
    DESTINATION lib/cmake
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)