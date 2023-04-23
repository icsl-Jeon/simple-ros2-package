cmake_minimum_required(VERSION 3.5)
project(my_package_ros2)

find_package(ament_cmake REQUIRED)

ament_package()

find_package(my_package_core REQUIRED)
