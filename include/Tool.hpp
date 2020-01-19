#ifndef MAP_MAKER_TOOL_HPP
#define MAP_MAKER_TOOL_HPP

#include <QtCore/QObject>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QLayout>

namespace map_builder
{
    namespace controller
    {
        class StateController;
    }

    class Tool : public QObject
    {
    public:
        Tool(QLayout *configurationLayout, QObject *parent = nullptr);
        virtual void startedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                                 Qt::MouseButton button) = 0;
        virtual void draged(controller::StateController *stateController, QGraphicsScene *scene, QVector2D dragedDirection,
                            Qt::MouseButtons button) = 0;
        virtual void endedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                               Qt::MouseButton button) = 0;
        virtual void clicked(controller::StateController *stateController, QGraphicsScene *scene,
                            QPointF point, Qt::MouseButton button) = 0;

        inline QLayout* configurationLayout()
        {
            return mConfigurationLayout;
        }

        Tool& operator=(const Tool &other) = delete;
        Tool& operator=(Tool &&other) = delete;

    private:
        QLayout *mConfigurationLayout;
    };
}
#endif //MAP_MAKER_TOOL_HPP
