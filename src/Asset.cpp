#include <Asset.hpp>
#include <QGraphicsScene>
#include <QDebug>
#include <QPainter>
#include <QJsonObject>
#include <QtCore/QBuffer>

namespace map_builder
{

    void Asset::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
        QGraphicsItemGroup::paint(painter, option, widget);
        if(isSelected())
        {
            painter->setPen(QPen(QBrush(QColor("#ffbf00")), 5));
            painter->drawRect(boundingRect());
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
        setFlag(QGraphicsItem::ItemIsSelectable);
    }

    QJsonObject Asset::toJsonObject()
    {
        QJsonObject object;
        object["x"] = x();
        object["y"] = y();
        QBuffer buffer;
        buffer.open(QIODevice::WriteOnly);
        mTerrain->pixmap().save(&buffer);
        object["terrain"] = QString(buffer.data().toBase64());

        QBuffer buffer1;
        buffer1.open(QIODevice::WriteOnly);
        mObject->pixmap().save(&buffer1);
        object["object"] = QString(buffer.data().toBase64());

        return object;

    }


}

