#include <TestAssetConfigurator.hpp>
#include "TestAssetPaintBuilder.hpp"
namespace map_builder
{

    TestAssetPaintBuilder::TestAssetPaintBuilder(AssetPaintType type, QObject *parent)
    :   AssetPaintBuilder(type, parent)
    {}

    QGraphicsPixmapItem *TestAssetPaintBuilder::createAssetPaint(const QMap<QString, QVariant> &configuration)
    {
        QPixmap pixmap(100, 100);
        pixmap.fill(configuration["color"].value<QColor>());

        return new QGraphicsPixmapItem(pixmap);
    }

    AssetConfigurator *TestAssetPaintBuilder::createConfigurator() {
        return new TestAssetConfigurator();
    }


}
