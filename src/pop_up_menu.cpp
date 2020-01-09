#include "pop_up_menu.hpp"
#include <QMenu>

namespace map_builder {
    // Constructor for pop_up_menu
    pop_up_menu::pop_up_menu(QToolButton* button, QWidget* parent) : QMenu(parent), b(button)
    {}

    // Function that makes the options from pop-up menu show on the right side of it.
    void pop_up_menu::showEvent(QShowEvent* e)
    {
        QPoint p = this->pos();
        QRect geo = b->geometry();
        this->move(p.x()+geo.width(), p.y()-geo.height());
    }

    // Destructor for pop_up_menu
    pop_up_menu::~pop_up_menu()
    {}
}
