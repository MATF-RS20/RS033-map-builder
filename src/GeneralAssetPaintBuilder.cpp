#include <QPixmap>
#include <GeneralAssetConfigurator.hpp>
#include "GeneralAssetPaintBuilder.hpp"
#include <algorithm>

namespace map_builder
{

    QGraphicsPixmapItem *GeneralAssetPaintBuilder::createAssetPaint(const QMap<QString, QVariant> &configuration)
    {
        return new QGraphicsPixmapItem(mAssetVarians[configuration["index"].toInt()].second);
    }

    AssetConfigurator *GeneralAssetPaintBuilder::createConfigurator()
    {
        QVector<QString> names;
        std::transform(mAssetVarians.begin(), mAssetVarians.end(), std::back_inserter(names),
                [](const auto &pair)
                {
                    return pair.first;
                });

        return new GeneralAssetConfigurator(std::move(names));
    }

    GeneralAssetPaintBuilder::GeneralAssetPaintBuilder(QVector<QPair<QString, QPixmap>> &&assetVariants, AssetPaintType type,
                                                       QObject *parent)
    :   AssetPaintBuilder(type, parent),
        mAssetVarians(std::move(assetVariants))
    {
    }

    GeneralAssetPaintBuilder::GeneralAssetPaintBuilder(const QVector<QPair<QString, QPixmap>> &assetVariants, AssetPaintType type,
                                                       QObject *parent)
    :   AssetPaintBuilder(type, parent),
        mAssetVarians(assetVariants)
    {
    }
}
