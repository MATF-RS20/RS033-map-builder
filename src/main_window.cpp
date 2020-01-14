#include "main_window.hpp"
#include "ui_main_window.h"
#include "pop_up_menu.hpp"
#include <QDebug>
#include <QFile>
#include <QMenu>
#include <QAction>
#include "utils/set_style.hpp"

namespace map_builder {
    main_window::main_window(QWidget *parent)
        : QMainWindow(parent),
        ui{new Ui::main_window()}
    {
        ui->setupUi(this);

        set_style_to_widget(this);

        // TODO: Make and comment function that makes menu bar/expandable button for assets.
        pop_up_menu *terrain_menu = new pop_up_menu(ui->tool_btn_terrain, this);
        terrain_menu->addAction(QIcon(":/icons/images/icons/land_inverted_2.png"), "Land");
        terrain_menu->addAction(QIcon(":/icons/images/icons/water-inverted.png"), "Sea");
        ui->tool_btn_terrain->setMenu(terrain_menu);


    }

    main_window::~main_window()
    {
        delete ui;
    }
}
