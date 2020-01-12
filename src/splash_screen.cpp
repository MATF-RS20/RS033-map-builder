#include <splash_screen.hpp>
#include "ui_splash_screen.h"
#include <QFile>

namespace map_builder
{
    splash_screen::splash_screen(QWidget *parent)
    :   QDialog(parent),
        ui(new Ui::splash_screen())
    {
        ui->setupUi(this);
        setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

        // TODO: Make and comment function for reading and loading qss style.
        QFile qss(":/styles/style.qss");
        qss.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(qss.readAll());
        setStyleSheet(styleSheet);

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
