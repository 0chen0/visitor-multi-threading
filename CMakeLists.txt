cmake_minimum_required(VERSION 2.8)
project( visitor-multi-threading )
# set(CMAKE_CXX_STANDARD 11)

list(APPEND TEMP_CXX_FLAGS
-std=c++11
-pthread
)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${TEMP_CXX_FLAGS}")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")

message(STATUS "@#@#: ${CMAKE_CXX_FLAGS}")
message(STATUS "@#@#: ${TEMP_CXX_FLAGS}")

find_package(Boost REQUIRED)
include_directories( ${Boost_INCLUDE_DIRS} )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# 统一include的路径相对于当前CMakeLists.txt所在路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 收集源文件
file(GLOB_RECURSE PROJ_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS 
    main.cc
    Engine.cc
    base/*
    message/*.hpp
    visitor/*.cc
)
message(STATUS "@#@#: ${PROJ_SOURCES}")

add_executable(${PROJECT_NAME} ${PROJ_SOURCES})
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} ${Boost_LIBRARIES})