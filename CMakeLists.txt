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

# 引入库
find_package(Boost REQUIRED)
include_directories( ${Boost_INCLUDE_DIRS} )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# 统一include的路径相对于当前CMakeLists.txt所在路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 收集源文件
file(GLOB_RECURSE PROJ_SOURCES_COLLECTED RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS 
    main.cc
    Engine.cc
    base/*
    message/*
    loop/*
)
message(STATUS "@#@#: ${PROJ_SOURCES_COLLECTED}")

set( PROJ_SOURCES
    main.cc
    Engine.cc
    base/Mutex.hpp
    base/noncopyable.hpp
    loop/EventLoop.cc

    loop/ImageHandle_EventLoop.cc
    loop/ImageRead_EventLoop.cc
    loop/WriteLog_EventLoop.cc

    message/Flag_Message.hpp
    message/Log_Message.hpp
    message/Open_Message.hpp

)

# add_executable(${PROJECT_NAME} ${PROJ_SOURCES_COLLECTED})
add_executable(${PROJECT_NAME} ${PROJ_SOURCES})
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} ${Boost_LIBRARIES})