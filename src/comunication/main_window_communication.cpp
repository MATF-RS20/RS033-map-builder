#include <QDebug>
#include "comunication/main_window_communication.hpp"
#include "main_window.hpp"


namespace map_builder
{

    void main_window_communication::make_main_screen()
    {
        if(m_main_window == nullptr)
        {
            m_main_window = new main_window();
            m_main_window->show();
        }
    }
}

