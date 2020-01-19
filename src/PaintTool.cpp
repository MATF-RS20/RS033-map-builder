
#include <QtCore/QPoint>
#include <controller/StateController.hpp>
#include <Asset.hpp>
#include <QVector2D>
#include "PaintTool.hpp"
#include "utils/util.hpp"
#include <QDebug>

namespace map_builder
{
    namespace details
    {
        Asset* findAssetIfItExists(const QList<QGraphicsItem*> &list)
        {
            Asset *asset{nullptr};
            for(auto *item : list)
            {
                asset = dynamic_cast<Asset*>(item);
                if(asset != nullptr)
                {
                    return asset;
                }
            }
            return nullptr;
        }
    }
    void PaintTool::startedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                                Qt::MouseButton button)
    {

    }

    void PaintTool::draged(controller::StateController *stateController, QGraphicsScene *scene, QVector2D dragedDirection,
                           Qt::MouseButtons button)
    {

    }

    void PaintTool::endedDrag(controller::StateController *stateController, QGraphicsScene *scene, QPoint point,
                              Qt::MouseButton button)
    {

    }

    void PaintTool::clicked(controller::StateController *stateController, QGraphicsScene *scene,
                            QPointF point, Qt::MouseButton button)
    {
        QList<QGraphicsItem *>items = scene->items(point);


        Asset *asset = details::findAssetIfItExists(items);
        qDebug() << asset;
        if(!asset)
        {
            QRectF rect = utils::getRectFromPoint(point);
            asset = new Asset(rect.x(), rect.y(), rect.width(), rect.height());
            scene->addItem(asset);
        }

        if(mBuilder->type() == AssetPaintType::terrain)
        {
            asset->terrain(mBuilder->createAssetPaint(mConfigurator->getConfiguration()), mBuilder);
        }
        else
        {
            asset->object(mBuilder->createAssetPaint(mConfigurator->getConfiguration()), mBuilder);
        }
    }

    PaintTool::PaintTool(AssetPaintBuilder *paint, QLayout *configurationLayout, QObject *parent)
    :   Tool(configurationLayout, parent),
        mBuilder(paint),
        mConfigurator{paint->createConfigurator()}
    {
        qDebug() << configurationLayout;
        if(this->configurationLayout())
        {
            this->configurationLayout()->addWidget(mConfigurator);
        }

    }

    PaintTool::~PaintTool()
    {
        qDebug() << "Hello";
        if(configurationLayout())
        {
            configurationLayout()->removeWidget(mConfigurator);
        }
        mConfigurator->deleteLater();
    }
}

