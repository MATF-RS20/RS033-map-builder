#include <QApplication>
#include "main_window.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    map_builder::main_window window;

    window.show();
    return app.exec();
}
