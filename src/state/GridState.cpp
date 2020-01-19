#include <state/GridState.hpp>
#include <QVector2D>

namespace map_builder::state
{
    GridState::GridState(int w, int h, QObject *parent)
    : QObject(parent),
      mWidth{w}, mHeight{h},
      mSceneRect(0, 0, w*distanceBetweenCells, h*distanceBetweenCells)
    {}

    void GridState::zoom(float factor)
    {
       mSceneRect.setWidth(mSceneRect.width() * factor);
       mSceneRect.setHeight(mSceneRect.height() * factor);
       emit sceneRectChanged(mSceneRect);
    }

    void GridState::zoom(float factor, const QPointF &point_to_zoom_in)
    {
        zoom(factor);
        mSceneRect.moveCenter(point_to_zoom_in);
        emit sceneRectChanged(mSceneRect);
    }

    void GridState::moveSceneRect(const QVector2D &move_vector)
    {
        mSceneRect.moveCenter((QVector2D(mSceneRect.center()) + move_vector).toPointF());
        emit sceneRectChanged(mSceneRect);
    }

}

