#ifndef OPTIONS_SCREEN_HPP
#define OPTIONS_SCREEN_HPP

#include <QMainWindow>

namespace Ui {
class options_screen;
}

namespace map_builder
{
    class options_screen : public QMainWindow
    {
    Q_OBJECT

    public:
        explicit options_screen(QWidget *parent = 0);
        ~options_screen();

// Slots for options in options_screen
    private slots:
        void create_new_project();
        void load_project();
        void open_manual();
        void exit();

    private:
        Ui::options_screen *ui;


        void close_window();

    };
}


#endif // OPTIONS_SCREEN_HPP
