#ifndef MAP_MAKER_PAINTTOOL_HPP
#define MAP_MAKER_PAINTTOOL_HPP

#include "Tool.hpp"
#include "AssetPaintBuilder.hpp"

namespace map_builder
{
    class PaintTool : public Tool
    {
    public:
        PaintTool(AssetPaintBuilder *paint, QLayout *configurationLayout, QObject *parent = nullptr);
        ~PaintTool();
        void startedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                         Qt::MouseButton button) override;

        void draged(controller::StateController *stateController, QGraphicsScene *scene, QVector2D dragedDirection,
                    Qt::MouseButtons button) override;

        void endedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                       Qt::MouseButton button) override;

        void clicked(controller::StateController *stateController, QGraphicsScene *scene, QPointF point,
                     Qt::MouseButton button) override;

    private:
        AssetPaintBuilder *mBuilder;
        AssetConfigurator *mConfigurator;
    };
}
#endif //MAP_MAKER_PAINTTOOL_HPP
