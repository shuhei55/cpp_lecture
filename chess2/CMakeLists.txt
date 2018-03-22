cmake_minimum_required(VERSION 3.6)

file(GLOB MAIN_SOURCES ${CMAKE_CURRENT_LIST_DIR} *.cpp)
set(MAIN_SOURCE_DIR init config)
foreach(SOURCE_DIR IN LISTS MAIN_SOURCE_DIR)
    file(GLOB DIR_SOURCES ${CMAKE_CURRENT_LIST_DIR}/${SOURCE_DIR}/*.cpp)
    list(APPEND MAIN_SOURCES ${DIR_SOURCES})
endforeach()
include_directories(${CMAKE_CURRENT_LIST_DIR})

include_directories(${CMAKE_CURRENT_LIST_DIR}/lib/include)

set(SUB_SOURCES_DIR ${CMAKE_CURRENT_LIST_DIR}/lib/src)

file(GLOB SUB_SOURCES ${SUB_SOURCES_DIR}/*.cpp)
list(APPEND MAIN_SOURCES ${SUB_SOURCES})

add_executable(main ${MAIN_SOURCES})
