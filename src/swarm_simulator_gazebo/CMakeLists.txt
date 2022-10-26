cmake_minimum_required(VERSION 3.5)
project(swarm_simulator_gazebo)

# Config
set(CMAKE_CXX_STANDARD 17)

# Dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(gazebo_dev REQUIRED)

# Assets 
install(
  DIRECTORY
    launch
    models
    worlds
  DESTINATION share/${PROJECT_NAME}/
)

# Environment hooks
ament_environment_hooks("${CMAKE_CURRENT_SOURCE_DIR}/env-hooks/${PROJECT_NAME}.dsv.in")

# Testing
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
