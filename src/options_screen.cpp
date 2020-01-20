#include <memory>
#include <QTextEdit>
#include <QWidget>
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
#include "utils/set_style.hpp"

namespace map_builder
{

options_screen::options_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::options_screen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    set_style_to_widget(this);

    // Buttons for initialization options:
    connect(ui->btn_new, &QPushButton::released, this, &options_screen::create_new_project);
    connect(ui->btn_load, &QPushButton::released, this,  &options_screen::load_project);
    connect(ui->btn_manual, &QPushButton::released, this,  &options_screen::open_manual);
    connect(ui->btn_exit, &QPushButton::released, this,  &options_screen::exit);

    // Adding preview image to label
    QPixmap pixmap(":/images/images/preview.png");
    pixmap = pixmap.scaled(width()*1.5, height()*1.5, Qt::KeepAspectRatio);
    ui->lb_img->setPixmap(pixmap);

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
    QFile manual(":/manual/manual.txt");
    if (manual.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString text(manual.readAll());
        QTextEdit *edit(new QTextEdit);

        set_style_to_widget(edit);
        edit->setText(text);
        edit->setReadOnly(true);
        edit->setFixedSize(800, 600);
        edit->show();
        manual.close();
    }
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
