#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <QMainWindow>
#include "controller/StateController.hpp"
#include "controller/GridController.hpp"

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

    public slots:
        void activatedTerrain();
        void activatedObject();
    private:
       Ui::main_window *ui;
       controller::StateController *m_state_controller;
       controller::GridController *m_grid_controller;

    };
}
#endif
