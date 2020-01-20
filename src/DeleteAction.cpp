#include "DeleteAction.hpp"

#include <QGraphicsItem>

namespace  map_builder
{

    DeleteAction::DeleteAction(QObject*parent)
    : Action(parent)
    {}

    void DeleteAction::applyAction(QGraphicsScene *scene, controller::StateController *stateController)
    {
        for (QGraphicsItem *item : scene->selectedItems()) {
            scene->removeItem(item);
            delete item;
        }
    }

}
