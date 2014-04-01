project(listener)
cmake_minimum_required(VERSION 2.6)
add_definitions(-DMYSQL_DIR)
include_directories("." ${MYSQL_DIR}/include)
link_directories("." ${MYSQL_DIR}/libmysql)

aux_source_directory(. SRCS)
add_library(listener SHARED ${SRCS})
add_library(listener_static STATIC ${SRCS})

SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")
