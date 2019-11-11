cmake_minimum_required(VERSION 3.1.0)

project(map_maker)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui/)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(map_maker
        ui/main_window.ui
        src/main_window.cpp
        include/main_window.hpp
        src/main.cpp
        ./resources.qrc
        )

target_include_directories(map_maker PUBLIC ./include)

target_link_libraries(map_maker Qt5::Core Qt5::Widgets)
