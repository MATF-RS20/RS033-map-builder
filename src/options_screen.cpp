#include <memory>
#include <QFile>
#include <QFileDialog>
#include <QDesktopServices>
#include "ui_options_screen.h"
#include "options_screen.hpp"
#include "init_worker.hpp"
#include "utils/start_task.hpp"
#include "comunicator.hpp"
#include "comunication/main_window_communication.hpp"
#include "comunication/splash_screen_comunicatior.hpp"

namespace map_builder
{

options_screen::options_screen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::options_screen)
{
    ui->setupUi(this);

    // TODO: Make and comment function for reading and loading qss style.
    QFile qss(":/styles/style.qss");
    qss.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(qss.readAll());
    setStyleSheet(styleSheet);

    // Buttons for initialization options:
    connect(ui->btn_new, SIGNAL (released()), this, SLOT (create_new_project()));
    connect(ui->btn_load, SIGNAL (released()), this, SLOT (load_project()));
    connect(ui->btn_manual, SIGNAL (released()), this, SLOT(open_manual()));
    connect(ui->btn_exit, SIGNAL (released()), this, SLOT(exit()));

}


// Function for creating new project.
void options_screen::create_new_project()
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

// Function for loading existing project.
void options_screen::load_project()
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

// Function that opens manual of application.
void options_screen::open_manual()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath() + "/manual.txt"));
}

// Function for exiting the application.
void options_screen::exit()
{
    options_screen::close();
}

options_screen::~options_screen()
{
    delete ui;
}

    void options_screen::close_window()
    {
        hide();
        deleteLater();
    }
}
