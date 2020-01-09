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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    auto *loading_thread{new QThread()};

    auto * communication = map_builder::make_comunicator(
            std::make_unique<map_builder::splash_screen_communication>(),
            std::make_unique<map_builder::main_window_communication>()
    );



    auto *worker{new map_builder::init_worker(communication)};

    worker->moveToThread(loading_thread);
    //Thread starts worker
    QObject::connect(loading_thread, &QThread::started, worker, &map_builder::init_worker::start);
    //When worker finishes it stops the thread
    QObject::connect(worker, &map_builder::init_worker::finished, loading_thread, &QThread::quit);
    //When thread is killed it deletes worker
    QObject::connect(loading_thread, &QThread::finished, worker, &map_builder::init_worker::deleteLater);
    //When thread is killed it deletes itself
    QObject::connect(loading_thread, &QThread::finished, loading_thread, &QThread::deleteLater);
    //When thread is killed it deletes communication chanel
    QObject::connect(loading_thread, &QThread::finished, communication, &QObject::deleteLater);

    loading_thread->start();


    return QApplication::exec();
}