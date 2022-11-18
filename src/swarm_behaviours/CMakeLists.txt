cmake_minimum_required(VERSION 3.5)
project(swarm_behaviours)

# Config
set(CMAKE_CXX_STANDARD 17)


# Dependencies
find_package(ament_cmake REQUIRED)


add_subdirectory(${PROJECT_SOURCE_DIR}/external/swarm-simulator/swarmsim) # Include swarmsim from the git submodule



## boids library
add_library(boids src/boids.cpp)
target_include_directories(boids PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(boids PRIVATE SwarmSim)
ament_export_targets(boids HAS_LIBRARY_TARGET)
# ament_export_dependencies(rclcpp)


# # boids.cpp
# target_link_libraries(boids PRIVATE SwarmSim)
# target_include_directories(boids PUBLIC
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#   $<INSTALL_INTERFACE:include>) # Link header files

# # swarm_behaviours.cpp
# add_executable(swarm_behaviours src/swarm_behaviours.cpp)
# target_link_libraries(swarm_behaviours PRIVATE SwarmSim boids)
# target_include_directories(swarm_behaviours PUBLIC
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#   $<INSTALL_INTERFACE:include>) # Link header files


install(
  DIRECTORY include/
  DESTINATION include
)

include_directories(include)
ament_export_include_directories(include)

# Libraries
install(
  TARGETS boids
  EXPORT boids 
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)


# # Install
# install(TARGETS 
#     swarm_behaviours
#   DESTINATION lib/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()


ament_package()
