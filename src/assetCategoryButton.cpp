#include "assetCategoryButton.hpp"
#include <QDebug>
#include <QSize>
#include "pop_up_menu.hpp"
#include "categoryAsset.hpp"

namespace  map_builder {

// Constructor.
AssetCategoryButton::AssetCategoryButton(CategoryAsset category) : mCategory(category)
{

    setToolTip(mCategory.name());
    setToolTipDuration(5000);
    setIcon(mCategory.icon());
    mAssetItemsMenu = new pop_up_menu(this, this);

    for (int i = 0; i<mCategory.size(); i++)
    {
        AssetCategoryItemAction *action = mCategory[i].toAction();
        connect(action, &AssetCategoryItemAction::categoryActionActivated, this, &AssetCategoryButton::categoryActionTriggered);

        mAssetItemsMenu->addAction(action);
    }

    setMenu(mAssetItemsMenu);
    setPopupMode(QToolButton::InstantPopup);
    setFixedSize(64, 32);
    setIconSize(QSize(64, 32));
}

void AssetCategoryButton::categoryActionTriggered(AssetPaintBuilder* painter)
{
    emit categoryClicked(painter);
}


}
