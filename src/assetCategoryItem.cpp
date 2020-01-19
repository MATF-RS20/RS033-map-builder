#include "assetCategoryItem.hpp"

namespace  map_builder
{

// Constructor.
AssetCategoryItem::AssetCategoryItem(QString name, QIcon icon)
    : mName(name),
      mIcon(icon)
{}


// Getter for name.
QString AssetCategoryItem::name()
{
    return mName;
}

// Getter for icon.
QIcon AssetCategoryItem::icon()
{
    return mIcon;
}



}
