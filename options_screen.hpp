#ifndef OPTIONS_SCREEN_HPP
#define OPTIONS_SCREEN_HPP

#include <QMainWindow>

namespace Ui {
class options_screen;
}

class options_screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit options_screen(QWidget *parent = 0);
    ~options_screen();

private:
    Ui::options_screen *ui;
};

#endif // OPTIONS_SCREEN_HPP
