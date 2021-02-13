add_library(Base STATIC
    echo.cpp
)

# Create ALIAS targets.
add_library( ${project_name}::Base ALIAS Base )

target_include_directories(
    Base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/include/${project_name}
)

# install the target and create export-set
install(
    TARGETS Base
    EXPORT BaseTargets
    NAMESPACE ${project_name}::
    DESTINATION lib/cmake
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/${project_name}
)
