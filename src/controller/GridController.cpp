#include <state/GridState.hpp>
#include <QDebug>
#include <utils/ImportantEventFilter.hpp>
#include "controller/GridController.hpp"
#include <QVector2D>

namespace map_builder::controller
{

    namespace details
    {
        void drawGrid(QGraphicsScene *scene, int w, int h);
        void updateSceneRect(QGraphicsView *map, const QRectF &sceneRect);
    }

    GridController::GridController(QGraphicsView *map, QGraphicsView *minimap,
                                   controller::StateController *state_controller, QObject *parent)
    :
            QObject(parent),
            mMap{map},
            mMinimap{minimap},
            mScene{new QGraphicsScene(mMap)},
            mStateController(state_controller)
    {
        mMap->setScene(mScene);
        mMinimap->setScene(mScene);


        mMap->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mMap->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        auto *eventFilter = new ImportantEventFilter(this);

        mMap->viewport()->installEventFilter(eventFilter);

        QObject::connect(eventFilter, &ImportantEventFilter::dragedEvent, this, &GridController::gridDraged);
        QObject::connect(eventFilter, &ImportantEventFilter::mouseClickedEvent, this, &GridController::gridClicked);
        QObject::connect(eventFilter, &ImportantEventFilter::resizedEvent, this, &GridController::gridResized);
        QObject::connect(eventFilter, &ImportantEventFilter::scrollWheelEvent, this, &GridController::gridScrolled);
        QObject::connect(eventFilter, &ImportantEventFilter::startDragEvent, this, &GridController::startedGridDrag);
        QObject::connect(eventFilter, &ImportantEventFilter::endDragEvent, this, &GridController::endedGridDrag);

        if(mStateController)
        {
            details::drawGrid(mScene, mStateController->gridState().width(), mStateController->gridState().height());
            QObject::connect(&mStateController->gridState(), &state::GridState::sceneRectChanged, this, &GridController::sceneRectChanged);
        }
    }

    void GridController::gridDraged(QVector2D dragDirection, Qt::MouseButton button)
    {
        if(mStateController)
        {
            if(button == Qt::MidButton)
            {
                const QVector2D slowedDownVector = dragDirection / 7;
                mStateController->gridState().moveSceneRect(-slowedDownVector);
            }
        }

    }

    void GridController::gridClicked(QPoint point, Qt::MouseButton button)
    {
        if(mStateController && mScene)
        {
            qDebug() << point;
            mStateController->toolState().currentTool().clicked(mStateController, mScene, mMap->mapToScene(point),
                                                                button);
        }
    }

    void GridController::gridResized(QSize size)
    {
        details::updateSceneRect(mMap, mStateController->gridState().sceneRect());
    }

    void GridController::sceneRectChanged(const QRectF &sceneRect)
    {
        details::updateSceneRect(mMap, sceneRect);
    }

    void GridController::gridScrolled(int direction, QPoint point)
    {
        if(mStateController)
        {
            mStateController->gridState().zoom(direction < 0 ?
                                               state::GridState::zoom_out_factor : state::GridState::zoom_in_factor);
        }
    }

    void GridController::endedGridDrag(QPoint point, Qt::MouseButton button)
    {

        if(mStateController && mScene)
        {
            mStateController->toolState().currentTool().endedDrag(point, button);
        }
    }

    void GridController::startedGridDrag(QPoint point, Qt::MouseButton button)
    {
        if(mStateController && mScene)
        {
            mStateController->toolState().currentTool().startedDrag(point, button);
        }
    }

    namespace details
    {
        void drawGrid(QGraphicsScene *scene, int w, int h)
        {
            const int step = state::GridState::distanceBetweenCells;
            QLineF originalLine(0, 0, 0, h*step);
            for(int i = 0; i <= w; ++i)
            {
                scene->addLine(originalLine);
                originalLine.translate(step, 0);
            }

            originalLine = QLineF(0, 0, w*step, 0);
            for(int i = 0; i <= h; ++i)
            {
                scene->addLine(originalLine);
                originalLine.translate(0, step);
            }
        }

        void updateSceneRect(QGraphicsView *map, const QRectF &sceneRect)
        {
            if(map)
            {
                QRectF rect(sceneRect);
                QSizeF size(map->width(), map->height());

                size.scale(rect.width(), rect.height(), Qt::KeepAspectRatio);
                rect.setSize(size);

                map->setSceneRect(rect);
                map->fitInView(map->sceneRect(), Qt::KeepAspectRatio);
            }
        }
    }
}
