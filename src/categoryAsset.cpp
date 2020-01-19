#include "categoryAsset.hpp"
#include <vector>
#include <QString>
#include <QIcon>

namespace map_builder
{

// Constructor.
CategoryAsset::CategoryAsset(QString name, QIcon icon, std::vector<AssetCategoryItem> items)
        : mName(name),
          mIcon(icon),
          mItems(items)
    {}

// Getter for name.
QString CategoryAsset::name()
{
    return mName;
}

// Getter for icon.
QIcon CategoryAsset::icon()
{
    return mIcon;
}

// Getter for size of category.
int CategoryAsset::size()
{
    return mItems.size();
}


AssetCategoryItem& CategoryAsset::operator[](size_t pos)
{
    return mItems[pos];
}

}
