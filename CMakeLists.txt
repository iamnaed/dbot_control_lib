cmake_minimum_required(VERSION 3.8)
project(dbot_control_lib)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3 REQUIRED)

# Define a library target
add_library(
  dbot_control_lib
  SHARED
  src/dbot_control.cpp
  src/cartesian.cpp
)

target_compile_features(
  dbot_control_lib 
  PUBLIC
  cxx_std_17
)

target_include_directories(
  dbot_control_lib 
  PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/dbot_control_lib>
)

ament_target_dependencies(dbot_control_lib Eigen3)

# Install the include directory
install(
  DIRECTORY include/
  DESTINATION include/dbot_control_lib
)

install(
  TARGETS dbot_control_lib
  EXPORT export_dbot_control_lib
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

# Line to export the library
ament_export_targets(
  export_dbot_control_lib
  HAS_LIBRARY_TARGET
)

ament_package()