
#include "main_window.hpp"
#include "ui_main_window.h"
#include <QDebug>
#include <QFile>

main_window::main_window(QWidget *parent)
    : QMainWindow(parent),
    ui{new Ui::MainWindow()}
{
    ui->setupUi(this);


    QFile qss(":/styles/style.qss");
    qss.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(qss.readAll());
    setStyleSheet(styleSheet);

}

main_window::~main_window()
{
    delete ui;
}
