cmake_minimum_required(VERSION 3.5)
project(my_package_ros2)

find_package(ament_cmake REQUIRED)

find_package(library_a REQUIRED)
find_package(library_b REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(visualizer visualizer/Visualizer.cpp visualizer/Visualizer.hpp)
ament_target_dependencies(visualizer rclcpp)
target_link_libraries(visualizer library_a library_b)

add_library(wrapper wrapper/Wrapper.cpp wrapper/Wrapper.hpp)
ament_target_dependencies(wrapper rclcpp std_msgs)
target_link_libraries(wrapper library_a library_b visualizer)

add_executable(MyRosNode main.cpp)
target_link_libraries(MyRosNode wrapper)
ament_target_dependencies(MyRosNode rclcpp)

install(TARGETS MyRosNode DESTINATION lib/${PROJECT_NAME})
ament_package()
