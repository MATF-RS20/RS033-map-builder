
#include <utility>
#include "controller/StateController.hpp"
#include "utils/util.hpp"
#include <QDebug>
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
}
