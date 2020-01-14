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
            ui/splash_screen.ui
            ui/options_screen.ui
            src/main_window.cpp
            src/options_screen.cpp
            include/main_window.hpp
            include/linear_executor.hpp
            include/mp/make_index.hpp
            src/main.cpp
            ./resources.qrc
            include/mp/pack.hpp
            include/mp/list.hpp
            include/mp/function_traits.hpp
            include/mp/types.hpp
            include/splash_screen.hpp
            include/options_screen.hpp
            src/splash_screen.cpp
            include/init_worker.hpp
            src/init_worker.cpp
            include/comunicator.hpp
            include/mp/utils.hpp
            include/mp/algorithm.hpp
            include/comunication/splash_screen_comunicatior.hpp
            src/comunication/splash_screen_comunicatior.cpp
            include/comunication/main_window_communication.hpp
            src/comunication/main_window_communication.cpp
            include/pop_up_menu.hpp
            src/pop_up_menu.cpp
            include/comunication/options_comunicaton.hpp
            src/comunication/options_comunicator.cpp
            include/comunication/communication_config.hpp
        )

target_include_directories(map_builder PUBLIC ./include)
set_property(TARGET map_builder PROPERTY CXX_STANDARD 17)

target_link_libraries(map_builder Qt5::Core Qt5::Widgets)
