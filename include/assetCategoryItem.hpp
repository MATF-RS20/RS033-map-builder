#ifndef ASSETCATEGORYITEM_HPP
#define ASSETCATEGORYITEM_HPP

#include <QString>
#include <QIcon>

namespace map_builder
{

class AssetCategoryItem
{

private:
    QString mName;
    QIcon mIcon;

public:
    AssetCategoryItem(QString name, QIcon icon);

    QString name();
    QIcon icon();

};

}
#endif // ASSETCATEGORYITEM_HPP
