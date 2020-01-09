#ifndef MAP_MAKER_MAIN_WINDOW_COMMUNICATION_HPP
#define MAP_MAKER_MAIN_WINDOW_COMMUNICATION_HPP

#include <QObject>
#include "main_window.hpp"

namespace map_builder
{
    class main_window_communication : public QObject
    {

    Q_OBJECT

    public slots:
        void make_main_screen();

    private:
        main_window *m_main_window;

    };
}

#endif //MAP_MAKER_MAIN_WINDOW_COMMUNICATION_HPP
