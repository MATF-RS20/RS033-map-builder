#ifndef MAP_MAKER_SELECTTOOL_HPP
#define MAP_MAKER_SELECTTOOL_HPP

#include "Tool.hpp"

namespace map_builder
{
    class SelectTool : public Tool
    {
    public:
        void startedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                         Qt::MouseButton button) override;

        void draged(controller::StateController *stateController, QGraphicsScene *scene, QVector2D dragedDirection,
                    Qt::MouseButtons button) override;

        void endedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                       Qt::MouseButton button) override;

        void clicked(controller::StateController *stateController, QGraphicsScene *scene, QPointF point,
                     Qt::MouseButton button) override;

        SelectTool(QLayout *configurationLayout, QObject *parent = nullptr);

        ~SelectTool();

    private:
        QGraphicsScene *mScene;
        QPointF mStartingPoint;
        QPointF mEndPoint;
        QGraphicsRectItem *mRectItem;
    };
}
#endif //MAP_MAKER_SELECTTOOL_HPP
