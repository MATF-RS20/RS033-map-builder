#ifndef ASSETCATEGORYBUTTON_HPP
#define ASSETCATEGORYBUTTON_HPP

#include <QToolButton>
#include "categoryAsset.hpp"
#include "pop_up_menu.hpp"

namespace map_builder
{

class AssetCategoryButton : public QToolButton
{

private:


public:
    AssetCategoryButton(CategoryAsset category);
    CategoryAsset mCategory;
    pop_up_menu *mAssetItemsMenu;

};


}

#endif // ASSETCATEGORYBUTTON_HPP
