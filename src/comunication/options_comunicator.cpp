#include <QDebug>
#include "comunication/options_comunicaton.hpp"

namespace map_builder
{
    namespace details
    {
        void delete_and_hide_options_screen(options_screen* &optionsScreen);
    }

    options_communication::options_communication()
    :   m_optionsScreen{nullptr}
    {}

    void options_communication::make_and_show_splash_screen()
    {
        if(m_optionsScreen == nullptr)
        {
            m_optionsScreen = new options_screen();
            m_optionsScreen->show();
        }
    }

    void options_communication::hide_and_destroy_splash_screen()
    {
        details::delete_and_hide_options_screen(m_optionsScreen);
    }

    options_communication::~options_communication()
    {
//       details::delete_and_hide_options_screen(m_optionsScreen);
    }

    namespace details
    {
        void delete_and_hide_options_screen(options_screen* &options_screen)
        {
            if(options_screen != nullptr)
            {
                options_screen->hide();
                options_screen->deleteLater();
                options_screen = nullptr;
            }
        }
    }

}

