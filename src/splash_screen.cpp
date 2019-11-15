
#include <splash_screen.hpp>
#include "ui_splash_screen.h"

namespace map_builder
{
    splash_screen::splash_screen(QWidget *parent)
    :   QDialog(parent),
        ui(new Ui::splash_screen())
    {
        ui->setupUi(this);
        setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    }

    splash_screen::~splash_screen()
    {
        delete ui;
    }

    void splash_screen::progressChanged(int progress)
    {
        ui->pb_loading->setValue(progress);
    }
}
