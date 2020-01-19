#ifndef MAP_MAKER_TESTASSETPAINTBUILDER_HPP
#define MAP_MAKER_TESTASSETPAINTBUILDER_HPP

#include "AssetPaintBuilder.hpp"

namespace map_builder
{
   class TestAssetPaintBuilder : public AssetPaintBuilder
   {
   public:
       TestAssetPaintBuilder(AssetPaintType type, QObject *parent);

       QGraphicsPixmapItem *createAssetPaint(const QMap<QString, QVariant> &configuration) override;

       AssetConfigurator *createConfigurator() override;
   };
}
#endif //MAP_MAKER_TESTASSETPAINTBUILDER_HPP
