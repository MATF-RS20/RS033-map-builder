
#include "main_window.hpp"
#include "ui_main_window.h"
#include <QDebug>

main_window::main_window(QWidget *parent)
    : QMainWindow(parent),
    ui{new Ui::MainWindow()}
{
    ui->setupUi(this);
}

main_window::~main_window()
{
    delete ui;
}
