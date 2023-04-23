cmake_minimum_required(VERSION 3.5)
project(my_package_core)

set(LIBRARY_NAME core_library)

file(GLOB HEADER_FILES "include/my_package_core/*.hpp")
file(GLOB SOURCE_FILES "src/*.cpp")

set(LIBRARY_SOURCES "")
list(APPEND LIBRARY_SOURCES ${SOURCE_FILES} ${HEADER_FILES})

include_directories(include)
add_library(${LIBRARY_NAME} SHARED ${LIBRARY_SOURCES})
install(
  TARGETS ${LIBRARY_NAME}
  EXPORT ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib)
install(FILES ${HEADER_FILES} DESTINATION include/${PROJECT_NAME})

export(TARGETS ${LIBRARY_NAME}
       FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake")

install(
  EXPORT ${PROJECT_NAME}
  FILE "${PROJECT_NAME}Config.cmake"
  DESTINATION share/${PROJECT_NAME}/cmake)
