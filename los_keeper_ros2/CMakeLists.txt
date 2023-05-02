cmake_minimum_required(VERSION 3.5)
project(los_keeper_ros2)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(los_keeper REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

function(add_los_ros2_library library_folder dependency_list)
  message("found library: ${library_folder}")
  file(GLOB LIBRARY_SOURCES
       "${CMAKE_CURRENT_SOURCE_DIR}/${library_folder}/*.cpp")
  file(GLOB LIBRARY_HEADERS
       "${CMAKE_CURRENT_SOURCE_DIR}/${library_folder}/*.hpp")
  add_library(${library_folder} SHARED ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
  ament_target_dependencies(${library_folder} rclcpp)
  target_link_libraries(${library_folder} ${dependency_list})
endfunction()

add_los_ros2_library(los_server los_keeper::target_manager
                     los_keeper::obstacle_manager)
ament_package()
