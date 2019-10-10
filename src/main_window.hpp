#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
};
class main_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit main_window(QWidget *parent= nullptr);
    ~main_window();

private:
   Ui::MainWindow *ui;
};

#endif