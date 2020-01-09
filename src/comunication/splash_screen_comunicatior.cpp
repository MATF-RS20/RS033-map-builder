
#include "comunication/splash_screen_comunicatior.hpp"
namespace map_builder
{
    namespace details
    {
        void delete_and_hide_splash_screen(splash_screen* &splashScreen);
    }

    splash_screen_communication::splash_screen_communication()
    :   m_splashScreen{nullptr}
    {}

    void splash_screen_communication::make_and_show_splash_screen()
    {
        if(m_splashScreen == nullptr)
        {
            m_splashScreen = new splash_screen();
            m_splashScreen->show();
        }
    }

    void splash_screen_communication::hide_and_destroy_splash_screen()
    {
        details::delete_and_hide_splash_screen(m_splashScreen);
    }

    splash_screen_communication::~splash_screen_communication()
    {
       details::delete_and_hide_splash_screen(m_splashScreen);
    }

    void splash_screen_communication::increase(int amount)
    {
        m_splashScreen->progressChanged(m_splashScreen->progress() + amount);
    }

    namespace details
    {
        void delete_and_hide_splash_screen(splash_screen* &splashScreen)
        {
            if(splashScreen != nullptr)
            {
                splashScreen->hide();
                splashScreen->deleteLater();
                splashScreen = nullptr;
            }
        }
    }

}

