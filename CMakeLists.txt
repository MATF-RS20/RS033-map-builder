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

add_executable(map_builder
        ui/main_window.ui
        src/main_window.cpp
        include/main_window.hpp
        include/linear_executor.hpp
        include/utils.hpp
        src/main.cpp
        ./resources.qrc
        )

target_include_directories(map_builder PUBLIC ./include)
set_property(TARGET map_builder PROPERTY CXX_STANDARD 17)

target_link_libraries(map_builder Qt5::Core Qt5::Widgets)
