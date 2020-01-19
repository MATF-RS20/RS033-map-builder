#ifndef MAP_MAKER_GENERALASSETPAINTBUILDER_HPP
#define MAP_MAKER_GENERALASSETPAINTBUILDER_HPP

#include <QVector>
#include <QString>
#include <QPair>
#include "AssetPaintBuilder.hpp"

namespace map_builder
{
    class GeneralAssetPaintBuilder : public AssetPaintBuilder
    {
    public:
        GeneralAssetPaintBuilder(QVector<QPair<QString, QPixmap>> &&assetVariants, AssetPaintType type, QObject *parent);
        GeneralAssetPaintBuilder(const QVector<QPair<QString, QPixmap>>  &assetVariants, AssetPaintType type, QObject *parent);

        QGraphicsPixmapItem *createAssetPaint(const QMap<QString, QVariant> &configuration) override;

        AssetConfigurator *createConfigurator() override;

    private:
        QVector<QPair<QString, QPixmap>> mAssetVarians;
    };
}
#endif //MAP_MAKER_GENERALASSETPAINTBUILDER_HPP
