cmake_minimum_required(VERSION 3.5)
project(my_package)
set(LIBRARY_LIST "library_a" "library_b")
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
foreach(LIBRARY ${LIBRARY_LIST})
  if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY})

    file(GLOB LIBRARY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY}/*.cpp")
    file(GLOB LIBRARY_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY}/*.hpp")

    add_library(${LIBRARY} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})

    install(
      TARGETS ${LIBRARY}
      EXPORT ${LIBRARY}
      LIBRARY DESTINATION lib
      INCLUDES
      DESTINATION include)
    install(FILES ${LIBRARY_HEADERS} DESTINATION include/${LIBRARY})
    export(TARGETS ${LIBRARY}
           FILE "${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY}Config.cmake")

    install(
      EXPORT ${LIBRARY}
      FILE "${LIBRARY}Config.cmake"
      DESTINATION share/${LIBRARY}/cmake)
  endif()
endforeach()
