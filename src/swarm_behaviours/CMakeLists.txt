cmake_minimum_required(VERSION 3.5)
project(swarm_behaviours)

# Config
set(CMAKE_CXX_STANDARD 17)


# Dependencies
find_package(ament_cmake REQUIRED)


# swarm_behaviours.cpp
add_executable(swarm_behaviours src/swarm_behaviours.cpp)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/swarm-simulator/swarmsim) # Include swarmsim from the git submodule
target_link_libraries(swarm_behaviours PRIVATE SwarmSim)
target_include_directories(swarm_behaviours PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>) # Link header files


# Install
install(TARGETS 
    swarm_behaviours
  DESTINATION lib/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()


ament_package()
