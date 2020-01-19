#include "assetCategoryItem.hpp"
#include "GeneralAssetPaintBuilder.hpp"

namespace  map_builder
{

// Constructor.
AssetCategoryItem::AssetCategoryItem(QString name, QIcon icon, GeneralAssetPaintBuilder* painter)
    : mName(name),
      mIcon(icon),
      mPainter(painter)
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

AssetPaintBuilder* AssetCategoryItem::painter()
{
    return mPainter;
}

AssetCategoryItemAction *AssetCategoryItem::toAction(QObject* parent)
{
    return new AssetCategoryItemAction(*this, parent);
}




}
