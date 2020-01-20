#include <QVector2D>
#include "SelectTool.hpp"
#include "utils/util.hpp"
#include "Asset.hpp"
#include <QDebug>
#include <cmath>


namespace map_builder
{

    SelectTool::SelectTool(QLayout *configurationLayout, QObject *parent)
    :   Tool(configurationLayout, parent),
        mScene{nullptr},
        mRectItem{nullptr}
    {}

    void SelectTool::startedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                                 Qt::MouseButton button)
    {
        mScene = scene;
        mStartingPoint = point;
        mEndPoint = point;
        mRectItem = new QGraphicsRectItem(mStartingPoint.x(), mStartingPoint.y(), 0, 0);
        mRectItem->setPen(QPen(QBrush("#ffbf00"), 5));
        mScene->addItem(mRectItem);
    }

    void
    SelectTool::draged(controller::StateController *stateController, QGraphicsScene *scene, QVector2D dragedDirection,
                       Qt::MouseButtons button)
    {
        auto endPoint = QVector2D(mEndPoint) + dragedDirection;
        mEndPoint = QPointF(endPoint.x(), endPoint.y());

        mRectItem->setRect(mStartingPoint.x(), mStartingPoint.y(), fabs(mEndPoint.x() - mStartingPoint.x()), fabs(mEndPoint.y()-  mStartingPoint.y()));
    }

    void SelectTool::endedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                               Qt::MouseButton button)
    {
        scene->removeItem(mRectItem);
        delete mRectItem;
        mRectItem = nullptr;

        QPainterPath path;
        path.addRect(mStartingPoint.x(), mStartingPoint.y(), fabs(mEndPoint.x() - mStartingPoint.x()), fabs(mEndPoint.y()-  mStartingPoint.y()));
        scene->setSelectionArea(path);
    }

    void SelectTool::clicked(controller::StateController *stateController, QGraphicsScene *scene, QPointF point,
                             Qt::MouseButton button)
    {
        auto items = scene->items(point);
        Asset *asset  = utils::findAssetIfItExists(items);
        if(asset)
        {
            QPainterPath selectionArea;
            scene->setSelectionArea(selectionArea, Qt::AddToSelection, Qt::IntersectsItemShape);
        }
    }

    SelectTool::~SelectTool()
    {
        if(mScene)
        {
            mScene->clearSelection();
        }

    }
}
