#ifndef MAP_MAKER_ASSETPAINTBUILDER_HPP
#define MAP_MAKER_ASSETPAINTBUILDER_HPP
#include <QObject>
#include <QGraphicsPixmapItem>
#include "AssetConfigurator.hpp"

namespace map_builder
{
    enum class AssetPaintType
    {
        terrain, object
    };

    class AssetPaintBuilder : public QObject
    {
    public:
        AssetPaintBuilder(AssetPaintType  type, QObject *parent);

        virtual QGraphicsPixmapItem* createAssetPaint(const QMap<QString, QVariant> &configuration) = 0;
        virtual AssetConfigurator* createConfigurator() = 0;

        inline AssetPaintType type()
        {
            return mTypeOfAsset;
        }


        AssetPaintBuilder& operator=(const AssetPaintBuilder& other) = delete;
        AssetPaintBuilder& operator=(AssetPaintBuilder &&other) = delete;

    private:
        AssetPaintType mTypeOfAsset;
    };
}

#endif //MAP_MAKER_ASSETPAINTBUILDER_HPP
