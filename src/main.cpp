#include <QApplication>
#include <QtCore/QThread>
#include <QDebug>
#include <options_screen.hpp>
#include "main_window.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    map_builder::options_screen *screen{new map_builder::options_screen};
    screen->show();


    return QApplication::exec();
}
