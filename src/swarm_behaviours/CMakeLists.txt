cmake_minimum_required(VERSION 3.5)
project(swarm_behaviours)

# Config
set(CMAKE_CXX_STANDARD 17)


# Dependencies
find_package(ament_cmake REQUIRED)

add_subdirectory(${PROJECT_SOURCE_DIR}/external/swarm-simulator/swarmsim) # Include swarmsim from the git submodule


# agent.cpp
add_library(agent src/agent.cpp)
target_link_libraries(agent PRIVATE SwarmSim)

# property_panel.cpp
add_library(property_panel src/property_panel.cpp)
target_link_libraries(property_panel PRIVATE SwarmSim agent)

# swarm_simulator.cpp
add_library(swarm_simulator src/swarm_simulator.cpp)
target_link_libraries(swarm_simulator PRIVATE SwarmSim)

# swarm_behaviours.cpp
add_executable(swarm_behaviours src/swarm_behaviours.cpp)
target_include_directories(swarm_behaviours PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>) # Link header files
target_link_libraries(swarm_behaviours PRIVATE SwarmSim agent property_panel swarm_simulator)


# Install
install(
  DIRECTORY include/
  DESTINATION include
)

install(TARGETS 
    agent
    property_panel
    swarm_simulator
    swarm_behaviours
  DESTINATION lib/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()


ament_package()
