#ifndef ASSETCATEGORYITEMACTION_HPP
#define ASSETCATEGORYITEMACTION_HPP

#include "AssetPaintBuilder.hpp"
#include <QAction>

namespace map_builder
{

class AssetCategoryItem;
class AssetCategoryItemAction : public QAction
{
    Q_OBJECT
private:
    AssetPaintBuilder* painter;

private slots:
    void actionTriggered();

signals:
    void categoryActionActivated(AssetPaintBuilder* painter);

public:
    AssetCategoryItemAction(AssetCategoryItem& item, QObject* parent = nullptr);

};

}

#endif // ASSETCATEGORYITEMACTION_HPP
