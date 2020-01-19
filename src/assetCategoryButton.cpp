#include "assetCategoryButton.hpp"
#include <QDebug>
#include <QSize>
#include "pop_up_menu.hpp"
#include "categoryAsset.hpp"

namespace  map_builder {

// Constructor.
AssetCategoryButton::AssetCategoryButton(CategoryAsset category) : mCategory(category)
{
    // U mainu fake category sa biklo kijim iconom
    // bilo koji ajtemui

    setToolTip(mCategory.name());
    setToolTipDuration(5000);
    setIcon(mCategory.icon());
    mAssetItemsMenu = new pop_up_menu(this, this);

    for (int i = 0; i<mCategory.size(); i++)
    {
        mAssetItemsMenu->addAction(mCategory[i].icon(), mCategory[i].name());
    }

    setMenu(mAssetItemsMenu);
    setPopupMode(QToolButton::InstantPopup);
    setFixedSize(64, 32);
    setIconSize(QSize(64, 32));
}

}
