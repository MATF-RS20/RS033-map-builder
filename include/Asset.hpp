#ifndef MAP_MAKER_ASSET_HPP
#define MAP_MAKER_ASSET_HPP

#include <QtWidgets/QGraphicsItemGroup>
#include "AssetPaintBuilder.hpp"

namespace map_builder
{
    class Asset : public QGraphicsItemGroup
    {
    public:
        Asset(float x, float y, float w, float h, QGraphicsItem *parent = nullptr);
        void terrain(QGraphicsPixmapItem *terrain, AssetPaintBuilder *terrainBuilder);
        void object(QGraphicsPixmapItem *terrain, AssetPaintBuilder *terrainBuilder);

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

        QJsonObject toJsonObject();
    private:
        QGraphicsPixmapItem *mTerrain;
        QGraphicsPixmapItem *mObject;
        AssetPaintBuilder *mTerrainBuilder;
        AssetPaintBuilder *mObjectBuilder;
        QGraphicsRectItem *mSelectRectangle;
        float mWidth;
        float mHeight;
    };
}
#endif //MAP_MAKER_ASSET_HPP
