cmake_minimum_required(VERSION 3.5)
project(los_keeper)

find_package(PCL REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Eigen3 REQUIRED NO_MODULE)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
function(add_los_library library_folder dependency_list)
  message("found library: ${library_folder}")
  file(GLOB LIBRARY_SOURCES
       "${CMAKE_CURRENT_SOURCE_DIR}/${library_folder}/*.cpp")
  file(GLOB LIBRARY_HEADERS
       "${CMAKE_CURRENT_SOURCE_DIR}/${library_folder}/*.hpp")
  add_library(${library_folder} SHARED ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
  target_link_libraries(${library_folder} ${dependency_list})
endfunction()

add_los_library(obstacle_manager ${PCL_COMMON} Eigen3::Eigen)
add_los_library(target_manager Eigen3::Eigen)
