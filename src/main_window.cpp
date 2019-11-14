#include "main_window.hpp"
#include "ui_main_window.h"
#include <QDebug>
#include <QFile>
#include <QMenu>
#include <QAction>

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
    QMenu* terrain_menu = new QMenu();
    terrain_menu->addAction(QIcon(":/icons/images/icons/preview.png"), "Land");
    ui->tool_btn_terrain->setMenu(terrain_menu);


}

main_window::~main_window()
{
    delete ui;
}
