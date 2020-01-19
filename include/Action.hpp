#ifndef MAP_MAKER_ACTION_HPP
#define MAP_MAKER_ACTION_HPP

#include <QtCore/QObject>
#include <QGraphicsScene>
#include <controller/StateController.hpp>

namespace map_builder
{
    class Action : public QObject
    {
    public:
        Action(QObject *parent = nullptr);

        virtual void applyAction(QGraphicsScene *scene, controller::StateController *stateController) = 0;
    };
}
#endif //MAP_MAKER_ACTION_HPP
