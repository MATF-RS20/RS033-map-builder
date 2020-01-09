#ifndef MAP_MAKER_SPLASH_SCREEN_COMUNICATIOR_HPP
#define MAP_MAKER_SPLASH_SCREEN_COMUNICATIOR_HPP

#include <QtCore/QObject>
#include "splash_screen.hpp"

namespace map_builder
{
    class splash_screen_communication : public QObject
    {
        Q_OBJECT

    public:
        explicit splash_screen_communication();
        ~splash_screen_communication() override ;
    public slots:
        void make_and_show_splash_screen();
        void hide_and_destroy_splash_screen();
        void increase(int amount);

    private:
        splash_screen *m_splashScreen;

    };
}

#endif //MAP_MAKER_SPLASH_SCREEN_COMUNICATIOR_HPP
