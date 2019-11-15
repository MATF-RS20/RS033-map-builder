#include <QDebug>
#include <QApplication>
#include <QThread>
#include <splash_screen.hpp>
#include "init_worker.hpp"
#include "linear_executor.hpp"

namespace map_builder
{

    init_worker::init_worker(QObject *parent)
    :   QObject(parent)
    {}

    void init_worker::start()
    {

        emit finished();
    }


}
