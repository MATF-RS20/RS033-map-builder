#include "options_screen.hpp"
#include "ui_options_screen.h"

options_screen::options_screen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::options_screen)
{
    ui->setupUi(this);
}

options_screen::~options_screen()
{
    delete ui;
}
