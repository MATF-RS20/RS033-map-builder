#include <QApplication>
#include <memory>
#include <init_worker.hpp>
#include <QtCore/QThread>
#include <QObject>
#include <QDebug>
#include "comunicator.hpp"
#include "main_window.hpp"
#include "linear_executor.hpp"
#include "comunication/splash_screen_comunicatior.hpp"
#include "comunication/main_window_communication.hpp"
#include "utils/start_task.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    map_builder::utils::start_task<map_builder::init_worker>(map_builder::make_comunicator(
            std::make_unique<map_builder::splash_screen_communication>(),
            std::make_unique<map_builder::main_window_communication>()
                    ));


    return QApplication::exec();
}