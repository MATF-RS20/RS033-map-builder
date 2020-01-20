#ifndef MAP_MAKER_UTIL_HPP
#define MAP_MAKER_UTIL_HPP

#include <QObject>
namespace map_builder
{
    class Asset;
}
namespace utils
{
    /**
    * Sets parent of the object if it is not already set
    * @param object  - object whoes parent will be set if it does not have one already
    * @param parent  - parent to be
    */
    void adopt_object(QObject *object, QObject *parent);
    QRectF getRectFromPoint(const QPointF &point);
    map_builder::Asset* findAssetIfItExists(const QList<QGraphicsItem*> &list);

}

#endif //MAP_MAKER_UTIL_HPP
