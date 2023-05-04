cmake_minimum_required(VERSION 3.5)
project(los_keeper_ros2)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(los_keeper REQUIRED)

add_library(los_server src/los_server/los_server.cc)
ament_target_dependencies(los_server rclcpp)
target_include_directories(
  los_server PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                    $<INSTALL_INTERFACE:include>)
target_link_libraries(los_server los_keeper)
install(FILES include/${PROJECT_NAME}/los_server/los_server.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}/los_server)

add_executable(los_server_node src/los_server/los_server_node.cc)
target_link_libraries(los_server_node los_server)
install(TARGETS los_server_node DESTINATION lib/${PROJECT_NAME})

enable_testing()
find_package(GTest REQUIRED)

add_executable(los_server_test test/los_server_test.cc)
target_link_libraries(los_server_test los_server GTest::GTest GTest::Main)
add_test(los_server_test los_server_test)

ament_package()
