#include <QDebug>
#include <QApplication>
#include <QThread>
#include <splash_screen.hpp>
#include <memory>
#include "init_worker.hpp"
#include "linear_executor.hpp"
#include "comunication/communication_config.hpp"
#include "comunication/main_window_communication.hpp"
#include "comunication/splash_screen_comunicatior.hpp"

namespace map_builder
{

    init_worker::init_worker(comunicator_type  *com, QObject *parent)
    :   m_com(com), QObject(parent)
    {}

    void init_worker::start()
    {
        make_linear_executor(
                [](comunicator_type *com)
                {
                    QMetaObject::invokeMethod(com->get<std::unique_ptr<splash_screen_communication>>().get(),
                            "make_and_show_splash_screen");
                   return com;
                },
                [](comunicator_type *com)
                {
                    for(int i = 0; i < 100; ++i)
                    {

                        QMetaObject::invokeMethod(com->get<std::unique_ptr<splash_screen_communication>>().get(),
                                "increase", Q_ARG(int, 1));
                        QThread::msleep(50);
                    }

                    return com;
                },

                [](comunicator_type *com)
                {
                    QMetaObject::invokeMethod(com->get<std::unique_ptr<splash_screen_communication>>().get(),
                    "hide_and_destroy_splash_screen");
                    return com;
                },
                [](comunicator_type *com)
                {
                    QMetaObject::invokeMethod(com->get<std::unique_ptr<main_window_communication>>().get(),
                            "make_main_screen");
                    return com;
                }
                )
        .execute(m_com);
        emit finished();
    }


}
