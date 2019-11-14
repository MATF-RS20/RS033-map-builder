#ifndef MAP_MAKER_SPLASH_SCREEN_HPP
#define MAP_MAKER_SPLASH_SCREEN_HPP

#include <QtWidgets/QDialog>

namespace Ui
{
    class splash_screen;
};

class splash_screen: public QDialog
{
    Q_OBJECT
public:
    explicit splash_screen(QWidget *parent= nullptr);
    ~splash_screen() override;

public slots:
    void progressChanged(int progress);


private:
    Ui::splash_screen *ui;
};

#endif //MAP_MAKER_SPLASH_SCREEN_HPP
