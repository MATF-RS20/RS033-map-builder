#ifndef ASSETCATEGORYBUTTON_HPP
#define ASSETCATEGORYBUTTON_HPP

#include <QToolButton>
#include "categoryAsset.hpp"
#include "pop_up_menu.hpp"

namespace map_builder
{

class AssetCategoryButton : public QToolButton
{

    Q_OBJECT
private:

signals:
    void categoryClicked(AssetPaintBuilder* painter);

private slots:
    void categoryActionTriggered(AssetPaintBuilder* painter);

public:
    AssetCategoryButton(CategoryAsset category);
    CategoryAsset mCategory;
    pop_up_menu *mAssetItemsMenu;

};


}

#endif // ASSETCATEGORYBUTTON_HPP
