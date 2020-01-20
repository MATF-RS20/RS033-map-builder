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
        include/main_window.hpp
        include/linear_executor.hpp
        include/mp/make_index.hpp
        include/categoryAsset.hpp
        include/assetCategoryItem.hpp
        include/assetCategoryButton.hpp
        include/AssetCategoryItemAction.hpp
        src/main.cpp
        ./resources.qrc
        include/mp/pack.hpp
        include/mp/list.hpp
        include/mp/function_traits.hpp
        include/mp/types.hpp
        include/splash_screen.hpp
        src/splash_screen.cpp
        src/categoryAsset.cpp
        src/assetCategoryItem.cpp
        src/assetCategoryButton.cpp
        src/AssetCategoryItemAction.cpp
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
        include/utils/start_task.hpp
        include/options_screen.hpp
        src/options_screen.cpp
        include/utils/set_style.hpp
        src/utils/set_style.cpp
        src/controller/StateController.cpp
        include/controller/StateController.hpp
        include/state/GridState.hpp
        src/state/GridState.cpp
        src/controller/GridController.cpp
        include/controller/GridController.hpp
        include/utils/ImportantEventFilter.hpp
        src/utils/ImportantEventFilter.cpp
        include/Tool.hpp
        src/Tool.cpp
        include/ToolState.hpp
        src/ToolState.cpp
        include/utils/util.hpp
        src/utils/util.cpp
        include/AssetPaintBuilder.hpp
        src/AssetPaintBuilder.cpp
        include/Asset.hpp
        include/AssetConfigurator.hpp
        src/Asset.cpp
        src/AssetConfigurator.cpp
        include/PaintTool.hpp
        src/PaintTool.cpp
        include/TestAssetConfigurator.hpp
        include/TestAssetPaintBuilder.hpp
        src/TestAssetConfigurator.cpp
        src/TestAssetPaintBuilder.cpp
        include/GeneralAssetConfigurator.hpp
        include/GeneralAssetPaintBuilder.hpp
        src/GeneralAssetConfigurator.cpp
        src/GeneralAssetPaintBuilder.cpp
        include/Action.hpp
        src/Action.cpp
        include/controller/ActionAndToolController.hpp
        src/controller/ActionAndToolController.cpp
        src/MoveTool.cpp
        include/MoveTool.hpp
        include/ZoomInAction.hpp
        include/ZoomOutAction.hpp
        include/RotateContraAction.hpp
        include/RotateClockAction.hpp
        include/DeleteAction.hpp
        src/RotateContraAction.cpp
        src/RotateClockAction.cpp
        src/ZoomInAction.cpp
        src/SelectTool.cpp
        src/DeleteAction.cpp
        include/SelectTool.hpp
        src/ZoomOutAction.cpp
        )

target_include_directories(map_builder PUBLIC ./include)
set_property(TARGET map_builder PROPERTY CXX_STANDARD 17)

target_link_libraries(map_builder Qt5::Core Qt5::Widgets)
