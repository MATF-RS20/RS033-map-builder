#include <Asset.hpp>
#include <QGraphicsScene>
#include <QDebug>

namespace map_builder
{
    void Asset::select()
    {
        if(mSelectRectangle)
        {
            addToGroup(mSelectRectangle);
        }
    }

    void Asset::unselect()
    {
        if(mSelectRectangle)
        {
            removeFromGroup(mSelectRectangle);
        }
    }

    void Asset::terrain(QGraphicsPixmapItem *terrain, AssetPaintBuilder *terrainBuilder)
    {
        if(mTerrain)
        {
            removeFromGroup(mTerrain);
            mTerrain->setParentItem(nullptr);
            mTerrain->scene()->removeItem(mTerrain);
            delete mTerrain;
        }

        mTerrain = terrain;
        mTerrainBuilder = terrainBuilder;

        mTerrain->setPixmap(mTerrain->pixmap().scaled(mWidth, mHeight, Qt::KeepAspectRatio));
        mTerrain->setPos(pos());
        mTerrain->setZValue(1);
        mTerrain->setFlag(QGraphicsItem::ItemIsMovable, false);
        addToGroup(mTerrain);
    }

    void Asset::object(QGraphicsPixmapItem *object, AssetPaintBuilder *objectBuilder)
    {
        if(mObject)
        {
            removeFromGroup(mObject);
            mObject->setParentItem(nullptr);
            mObject->scene()->removeItem(mObject);
            delete mObject;
        }

        mObject = object;
        mObjectBuilder = objectBuilder;

        mObject->setPixmap(mObject->pixmap().scaled(mWidth, mHeight, Qt::KeepAspectRatio));
        mObject->setPos(pos());
        mObject->setZValue(2);
        addToGroup(mObject);
    }


    Asset::Asset(float x, float y, float w, float h, QGraphicsItem *parent)
    :   QGraphicsItemGroup(parent) ,
        mObject{nullptr},
        mTerrain{nullptr},
        mTerrainBuilder{nullptr},
        mObjectBuilder{nullptr},
        mSelectRectangle{new QGraphicsRectItem(boundingRect(), this)},
        mWidth{w},
        mHeight{h}

    {

        setX(x);
        setY(y);
    }


}

