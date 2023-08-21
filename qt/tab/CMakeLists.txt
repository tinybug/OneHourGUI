cmake_minimum_required(VERSION 3.19)

project(Button LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Make sure you have the 'find_package' command available for Qt6
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(Tab
  main.cpp
  mainwindow.cpp
  mainwindow.h
)

target_link_libraries(Tab PRIVATE Qt6::Core Qt6::Widgets)
