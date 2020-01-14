#ifndef OPTIONS_COMUNICATON_HPP
#define OPTIONS_COMUNICATON_HPP
#include <QtCore/QObject>
#include "options_screen.hpp"

namespace map_builder
{
    class options_communication : public QObject
    {
        Q_OBJECT

    public:
        explicit options_communication();
        ~options_communication() override ;
    public slots:
        void make_and_show_splash_screen();
        void hide_and_destroy_splash_screen();
    private:
        options_screen *m_optionsScreen;

    };
}

#endif // OPTIONS_COMUNICATON_HPP
