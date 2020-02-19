cmake_minimum_required(VERSION 2.8.9)
set( NAME alarmService )

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "*.cpp")

#Generate the static library from the sources
add_library(${NAME} STATIC ${SOURCES})

target_include_directories (${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

