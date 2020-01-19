#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <QMainWindow>

namespace Ui
{
    class main_window;
};

namespace map_builder {
    class main_window : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit main_window(QWidget *parent= nullptr);
        ~main_window() override;

    // Slots for actions in menu_bar.
    private slots:
        void create_new_project();
        void open_project();
        void save_project();
        void save_as_project();
        void exit_project();

    private:
       Ui::main_window *ui;
       void close_window();
    };
}
#endif
