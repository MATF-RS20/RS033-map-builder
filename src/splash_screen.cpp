#include <splash_screen.hpp>
#include <QFile>
#include "ui_splash_screen.h"
#include "utils/set_style.hpp"

namespace map_builder
{
    splash_screen::splash_screen(QWidget *parent)
    :   QDialog(parent),
        ui(new Ui::splash_screen())
    {
        ui->setupUi(this);
        setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

        set_style_to_widget(this);

    }

    splash_screen::~splash_screen()
    {
        delete ui;
    }

    void splash_screen::progressChanged(int progress)
    {
        ui->pb_loading->setValue(progress);
    }

    int splash_screen::progress()
    {
        ui->pb_loading->value();
    }
}
