#include "main_window.hpp"
#include "ui_main_window.h"
#include "pop_up_menu.hpp"
#include <QDebug>
#include <QFile>
#include <QMenu>
#include <QAction>

namespace map_builder {
    main_window::main_window(QWidget *parent)
        : QMainWindow(parent),
        ui{new Ui::main_window()}
    {
        ui->setupUi(this);


        // TODO: Make and comment function for reading and loading qss style.
        QFile qss(":/styles/style.qss");
        qss.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(qss.readAll());
        setStyleSheet(styleSheet);

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
