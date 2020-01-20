#ifndef MAP_MAKER_MOVETOOL_HPP
#define MAP_MAKER_MOVETOOL_HPP

#include "Tool.hpp"

namespace map_builder
{
    class MoveTool : public Tool
    {
    public:
        MoveTool(QLayout *configurationLayout, QObject *parent = nullptr);

        void startedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                         Qt::MouseButton button) override;

        void draged(controller::StateController *stateController, QGraphicsScene *scene, QVector2D dragedDirection,
                    Qt::MouseButtons button) override;

        void endedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                       Qt::MouseButton button) override;

        void clicked(controller::StateController *stateController, QGraphicsScene *scene, QPointF point,
                     Qt::MouseButton button) override;
    };
}
#endif //MAP_MAKER_MOVETOOL_HPP
