cmake_minimum_required(VERSION 3.8)
project(ur5_teaching_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)

add_executable(test_move_arm_cpp src/test_move_arm.cpp)
ament_target_dependencies(test_move_arm_cpp rclcpp moveit_ros_planning_interface)

install(TARGETS test_move_arm_cpp
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
