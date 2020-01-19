#include "MoveTool.hpp"
#include "controller/StateController.hpp"
#include "state/GridState.hpp"
#include <QVector2D>

namespace map_builder
{

    MoveTool::MoveTool(QLayout *configurationLayout, QObject *parent)
    : Tool(configurationLayout, parent)
    {}

    void MoveTool::startedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                               Qt::MouseButton button)
    {

    }

    void
    MoveTool::draged(controller::StateController *stateController, QGraphicsScene *scene, QVector2D dragedDirection,
                     Qt::MouseButtons button)
    {

        stateController->gridState().moveSceneRect(-dragedDirection *
        (button == Qt::MouseButton::RightButton ? 2.0f : 1.0f));
    }

    void MoveTool::endedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                             Qt::MouseButton button)
    {

    }

    void MoveTool::clicked(controller::StateController *stateController, QGraphicsScene *scene, QPointF point,
                           Qt::MouseButton button)
    {

    }
}
