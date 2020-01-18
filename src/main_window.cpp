#include "main_window.hpp"
#include "ui_main_window.h"
#include "pop_up_menu.hpp"
#include "init_worker.hpp"
#include "utils/start_task.hpp"
#include "comunicator.hpp"
#include "comunication/main_window_communication.hpp"
#include "comunication/splash_screen_comunicatior.hpp"
#include "utils/set_style.hpp"
#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QMenu>
#include <QAction>
#include "utils/set_style.hpp"

namespace map_builder
{

main_window::main_window(QWidget *parent)
    : QMainWindow(parent),
    ui{new Ui::main_window()}
{
    ui->setupUi(this);

    set_style_to_widget(this);
    QWidget::setWindowTitle(QString("Nightscream"));

    // TODO: Make and comment function that makes menu bar/expandable button for assets.
    pop_up_menu *terrain_menu = new pop_up_menu(ui->tool_btn_terrain, this);
    terrain_menu->addAction(QIcon(":/icons/images/icons/land_inverted_2.png"), "Land");
    terrain_menu->addAction(QIcon(":/icons/images/icons/water-inverted.png"), "Sea");
    ui->tool_btn_terrain->setMenu(terrain_menu);

    // Functions for actions in menu_bar.
    connect(ui->ac_new_file, &QAction::triggered, this, &main_window::create_new_project);
    connect(ui->ac_open_file, &QAction::triggered, this, &main_window::open_project);
    connect(ui->ac_save_file, &QAction::triggered, this, &main_window::save_project);
    connect(ui->ac_save_file_as, &QAction::triggered, this, &main_window::save_as_project);
    connect(ui->ac_exit, &QAction::triggered, this, &main_window::exit_project);

}

// Function for creating new project.
void main_window::create_new_project()
{
    QFileDialog dialog;
    dialog.setStyleSheet("style.qss");
    QString new_project = QFileDialog::getSaveFileName(this, tr("Save project"),
                                                       "/Desktop/untitled.txt", "Images (*.jpg)", 0,
                                                       QFileDialog::DontUseNativeDialog);


    utils::start_task<init_worker>(make_comunicator(
            std::make_unique<splash_screen_communication>(),
            std::make_unique<main_window_communication>())
            );

    close_window();
}

// Function for opening another project.
void main_window::open_project()
{
    QFileDialog dialog;
    dialog.setStyleSheet("style.qss");
    QString project = QFileDialog::getOpenFileName(this, "Select project",
                                                       "/Desktop/untitled.txt", "Images (*.jpg)", 0,
                                                       QFileDialog::DontUseNativeDialog);

    utils::start_task<init_worker>(make_comunicator(
            std::make_unique<splash_screen_communication>(),
            std::make_unique<main_window_communication>())
    );

    close_window();
}


// Function for saving existing project.
void main_window::save_project()
{
    QFileDialog dialog;
    dialog.setStyleSheet("style.qss");

    // TODO: Implement saving when format is decided.

    close_window();
}


// Function that saves project as another one.
void main_window::save_as_project()
{
    QFileDialog dialog;
    dialog.setStyleSheet("style.qss");
    QString project = QFileDialog::getOpenFileName(this, "Select project",
                                                       "/Desktop/untitled.txt", "Images (*.jpg)", 0,
                                                       QFileDialog::DontUseNativeDialog);

    utils::start_task<init_worker>(make_comunicator(
            std::make_unique<splash_screen_communication>(),
            std::make_unique<main_window_communication>())
    );

    close_window();
}

// Function for exiting the application.
void main_window::exit_project()
{
    main_window::close();
}

main_window::~main_window()
{
    delete ui;
}

void main_window::close_window()
{
    hide();
    deleteLater();
}


}
