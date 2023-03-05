cmake_minimum_required(VERSION 3.14)

project(google LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(google
  main.cpp
)
target_link_libraries(google Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS google
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


add_executable(tests
  Tests/test.cc
  parser.h
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(tests ${GTEST_BOTH_LIBRARIES})

