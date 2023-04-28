project(library_b)
cmake_minimum_required(VERSION 3.5)
include_directories(${ROOT_DIR})
add_library(${PROJECT_NAME} SHARED LibraryB.cpp LibraryB.hpp)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  INCLUDES
  DESTINATION include/${PROJECT_NAME})
install(FILES LibraryB.hpp DESTINATION include/my_package/${PROJECT_NAME})

export(TARGETS ${PROJECT_NAME}
       FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake")
install(
  EXPORT ${PROJECT_NAME}
  FILE "${PROJECT_NAME}Config.cmake"
  DESTINATION share/${PROJECT_NAME}/cmake)
