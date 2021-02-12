# You should always specify a range with the newest
# and oldest tested versions of CMake. 
cmake_minimum_required(VERSION 3.14...3.19)

# set version
set(version 1.0.0)
set(project_name Echo)

# This is your project statement. You should always list languages;
project(
  ${project_name}
  VERSION ${version})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src/base)
add_subdirectory(src/formal)

# include CMakePackageConfigHelpers macro
include(CMakePackageConfigHelpers)

# generate the version file for the config file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${project_name}Config.cmake"
    VERSION "${version}"
    COMPATIBILITY AnyNewerVersion
)

# create config file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in 
    ${CMAKE_CURRENT_BINARY_DIR}/${project_name}Config.cmake
    INSTALL_DESTINATION lib/cmake
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# install config files
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/${project_name}.cmake"
    NAMESPACE ${project_name}::
    DESTINATION lib/cmake
)