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

    private:
       Ui::main_window *ui;
    };
}
#endif
