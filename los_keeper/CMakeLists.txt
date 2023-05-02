cmake_minimum_required(VERSION 3.5)
project(los_keeper)

find_package(PCL REQUIRED)
find_package(Eigen3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
function(add_los_library library_folder dependency_list)
  message("found library: ${library_folder}")
  list(APPEND ${LIBRARY_LIST} ${library_folder})
  file(GLOB LIBRARY_SOURCES
       "${CMAKE_CURRENT_SOURCE_DIR}/${library_folder}/*.cpp")
  file(GLOB LIBRARY_HEADERS
       "${CMAKE_CURRENT_SOURCE_DIR}/${library_folder}/*.hpp")
  add_library(${library_folder} SHARED ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
  target_link_libraries(${library_folder} ${dependency_list})

  install(
    TARGETS ${library_folder}
    EXPORT ${library_folder}
    LIBRARY DESTINATION lib
    INCLUDES
    DESTINATION include)
  install(FILES ${LIBRARY_HEADERS} DESTINATION include/${LIBRARY})
  export(TARGETS ${library_folder}
         FILE "${CMAKE_CURRENT_BINARY_DIR}/${library_folder}Config.cmake")

  install(
    EXPORT ${library_folder}
    FILE "${library_folder}Config.cmake"
    DESTINATION share/${library_folder}/cmake)

endfunction()

add_los_library(obstacle_manager "${PCL_COMMON}")
add_los_library(target_manager "")

add_library(los_keeper INTERFACE)
target_link_libraries(
  los_keeper
  INTERFACE obstacle_manager
  INTERFACE target_manager)
install(
  TARGETS los_keeper
  EXPORT los_keeper
  LIBRARY DESTINATION lib
  INCLUDES
  DESTINATION include)

export(TARGETS los_keeper
       FILE "${CMAKE_CURRENT_BINARY_DIR}/los_keeperConfig.cmake")
install(
  EXPORT los_keeper
  FILE los_keeperConfig.cmake
  NAMESPACE los_keeper::
  DESTINATION share/los_keeper/cmake)
