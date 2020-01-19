#include "AssetCategoryItemAction.hpp"

#include "assetCategoryItem.hpp"
#include <QAction>
#include <QDebug>

namespace map_builder
{

AssetCategoryItemAction::AssetCategoryItemAction(AssetCategoryItem& item, QObject* parent) :
                                            QAction(item.icon(), item.name(), parent),
                                            painter(item.painter())
{
    connect(this, &QAction::triggered, this, &AssetCategoryItemAction::actionTriggered);

}

void AssetCategoryItemAction::actionTriggered()
{
    emit categoryActionActivated(painter);
}

}
