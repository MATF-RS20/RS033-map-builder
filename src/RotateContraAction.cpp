#include "RotateContraAction.hpp"

#include <QGraphicsItem>

namespace map_builder
{

    RotateContraAction::RotateContraAction(QObject* parent)
    : Action(parent)
    {}

    void RotateContraAction::applyAction(QGraphicsScene *scene, controller::StateController *stateController)
    {
        foreach(QGraphicsItem *item, scene->selectedItems())
        {
            QPointF offset;
            QTransform t;
            offset = item->sceneBoundingRect().center();

            t.translate(offset.x(), offset.y());
            t.rotate(90);
            t.translate(-offset.x(), -offset.y());

            item->setPos(t.map(item->pos()));
            item->setRotation(item->rotation() + 90);
        }
    }

}
