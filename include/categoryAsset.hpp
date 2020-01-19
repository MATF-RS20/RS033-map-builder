#ifndef CATEGORYASSET_HPP
#define CATEGORYASSET_HPP

#include "assetCategoryItem.hpp"
#include <QString>
#include <QIcon>
#include <vector>

namespace  map_builder
{

class CategoryAsset
{

private:
    QString mName;
    QIcon mIcon;

    std::vector<AssetCategoryItem> mItems;

public:
    CategoryAsset(QString name, QIcon icon, std::vector<AssetCategoryItem> items);

    QString name();
    QIcon icon();

    int size();

    AssetCategoryItem& operator[](size_t pos);

};

}

#endif // CATEGORYASSET_HPP
