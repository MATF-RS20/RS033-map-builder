#ifndef MAP_MAKER_GRIDCONTROLLER_HPP
#define MAP_MAKER_GRIDCONTROLLER_HPP

#include <QtWidgets/QGraphicsView>
#include <QObject>
#include <QVector2D>
#include <QSize>
#include "StateController.hpp"

namespace map_builder::controller
{
    class GridController : public QObject
    {
        Q_OBJECT
    public:
        GridController(QGraphicsView *map, QGraphicsView *minimap, controller::StateController *state_controller, QObject *parent = nullptr);
    private:
        QGraphicsView *mMap;
        QGraphicsView *mMinimap;
        QGraphicsScene *mScene;
        StateController *mStateController;

    private slots:
        void startedGridDrag(QPoint point, Qt::MouseButton button);
        void gridDraged(QVector2D dragDirection, Qt::MouseButton button);
        void endedGridDrag(QPoint point, Qt::MouseButton button);
        void gridClicked(QPoint point, Qt::MouseButton button);
        void gridResized(QSize size);
        void sceneRectChanged(const QRectF &sceneRect);
        void gridScrolled(int direction, QPoint point);
    };
}

#endif //MAP_MAKER_GRIDCONTROLLER_HPP
