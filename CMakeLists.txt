cmake_minimum_required(VERSION 3.1.0)

project(map_maker)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
include_directories(cmake-build-debug/map_maker_autogen/include)
add_executable(map_maker
        src/main_window.ui
        src/main_window.cpp
        src/main.cpp
#        resources.qrc
        )

target_link_libraries(map_maker Qt5::Widgets)