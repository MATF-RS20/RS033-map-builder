
#include <utility>
#include "controller/StateController.hpp"
#include "utils/util.hpp"
#include <QDebug>
#include <QtCore/QFile>
#include <QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include "Asset.hpp"


namespace utils
{
    void adopt_object(QObject *object, QObject *parent)
    {
        if(object != nullptr)
        {
            if(object->parent() == nullptr)
            {
                object->setParent(parent);
            }
        }
    }

    QRectF getRectFromPoint(const QPointF &point)
    {
       constexpr  int distance = map_builder::state::GridState::distanceBetweenCells;
       int row = static_cast<int>(point.y()) / distance;
       int col = static_cast<int>(point.x()) / distance;

       return QRectF(col*distance, row*distance, distance, distance);
    }

    map_builder::Asset* findAssetIfItExists(const QList<QGraphicsItem*> &list)
    {
        map_builder::Asset *asset{nullptr};
        for(auto *item : list)
        {
            asset = dynamic_cast<map_builder::Asset*>(item);
            if(asset != nullptr)
            {
                return asset;
            }
        }
        return nullptr;
    }

    QGraphicsScene *loadFromFile(const QString &fileName)
    {
        QFile jsonFile(fileName);

        if(!jsonFile.exists())
        {
            return new QGraphicsScene;
        }
        if(!jsonFile.open(QFile::ReadOnly))
        {
            return new QGraphicsScene;
        }

        QJsonDocument document(QJsonDocument::fromBinaryData(jsonFile.readAll()));
        if(!document.isArray())
        {
            return new QGraphicsScene;
        }

        QJsonArray arrayOfAssets(document.array());

        bool succes{true};
        QGraphicsScene *scene = new QGraphicsScene;

        std::for_each(arrayOfAssets.begin(), arrayOfAssets.end(),
                [&succes, scene](QJsonValueRef jsonValue)
                {
                    if(!jsonValue.isObject())
                    {
                        succes = false;
                        return ;
                    }

                    auto object{jsonValue.toObject()};
                    if(object["x"].isDouble() && object["y"].isDouble()
                    && object["terrain"].isString() && object["object"].isString())
                    {
                        float x = object["x"].toDouble();
                        float y = object["y"].toDouble();
                        QString terrainPath = object["terrain"].toString();
                        QString objectPath = object["terrain"].toString();

                        QPixmap terrain;
                        terrain.loadFromData(objectPath.toLocal8Bit(),"png");
                        QPixmap objectPixmap;
                        objectPixmap.loadFromData(objectPath.toLocal8Bit(), "png");

                        constexpr  int d = map_builder::state::GridState::distanceBetweenCells;
                        auto *asset = new map_builder::Asset(x, y, d, d);
                        asset->object(new QGraphicsPixmapItem(terrain), nullptr);
                        asset->terrain(new QGraphicsPixmapItem(objectPixmap), nullptr);
                        scene->addItem(asset);
                    }
                    else
                    {
                        succes = false;
                        return  ;
                    }

                });


        if(succes)
        {
            return scene;
        }
        else
        {
            delete scene;
            return nullptr;
        }

    }

    void saveToFile(QGraphicsScene *scene, const QString &filename)
    {
        map_builder::Asset *assetItem{nullptr};
        QJsonArray array;

        for(QGraphicsItem *item : scene->items())
        {
            assetItem = dynamic_cast<map_builder::Asset*>(item);
            if(assetItem != nullptr)
            {
                array.push_back(assetItem->toJsonObject());
            }
        }

        QFile file(filename);
        file.open(QFile::WriteOnly);
        file.write(QJsonDocument{array}.toJson());
        file.close();

    }
}
