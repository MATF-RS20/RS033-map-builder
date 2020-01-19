#include "main_window.hpp"
#include "ui_main_window.h"
#include "pop_up_menu.hpp"
#include <QDebug>
#include <QFile>
#include <QMenu>
#include <QAction>
#include <PaintTool.hpp>
#include <TestAssetPaintBuilder.hpp>
#include <GeneralAssetPaintBuilder.hpp>
#include "utils/set_style.hpp"

namespace map_builder {
    main_window::main_window(QWidget *parent)
        : QMainWindow(parent),
        ui{new Ui::main_window()}
    {
        ui->setupUi(this);

        m_state_controller = new controller::StateController(new state::GridState(10, 10), new state::ToolState,this);
        m_grid_controller = new controller::GridController(ui->graphics_view_grid, ui->graphics_view_minimap,
                                                           m_state_controller, this);


        set_style_to_widget(this);

        // TODO: Make and comment function that makes menu bar/expandable button for assets.
        pop_up_menu *terrain_menu = new pop_up_menu(ui->tool_btn_terrain, this);
        terrain_menu->addAction(QIcon(":/icons/images/icons/land_inverted_2.png"), "Land", this, &main_window::activatedTerrain);
        terrain_menu->addAction(QIcon(":/icons/images/icons/water-inverted.png"), "Sea", this, &main_window::activatedObject);
        ui->tool_btn_terrain->setMenu(terrain_menu);
    }

    main_window::~main_window()
    {
        delete ui;
    }

    void main_window::activatedTerrain()
    {
        auto testAssetBuilder = new TestAssetPaintBuilder(AssetPaintType::terrain, this);
        m_state_controller->toolState().currentTool(new PaintTool(testAssetBuilder, ui->verticalLayout_2));
    }

    void main_window::activatedObject()
    {

        auto generalAssetBuilder = new GeneralAssetPaintBuilder({{"Land", QPixmap(":/icons/images/icons/land_inverted_2.png")},
                                                                 {"Sea", QPixmap(":/icons/images/icons/water-inverted.png")}},
                                                                AssetPaintType::object, this);

        auto paintTool = new PaintTool(generalAssetBuilder, ui->verticalLayout_2);
        m_state_controller->toolState().currentTool(paintTool);

    }
}
