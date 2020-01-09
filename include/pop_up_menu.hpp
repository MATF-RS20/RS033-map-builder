#ifndef POP_UP_MENU_HPP
#define POP_UP_MENU_HPP

#include <QMenu>
#include <QToolButton>

class QToolButton;
class QWidget;

namespace map_builder {
    class pop_up_menu : public QMenu
    {
        Q_OBJECT
    public:
        explicit pop_up_menu(QToolButton* button, QWidget* parent = 0);
        void showEvent(QShowEvent* event) override;
        ~pop_up_menu() override;
    private:
        QToolButton* b;
    };
}

#endif // POP_UP_MENU_HPP
