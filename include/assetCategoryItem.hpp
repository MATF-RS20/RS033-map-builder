#ifndef ASSETCATEGORYITEM_HPP
#define ASSETCATEGORYITEM_HPP

#include <QString>
#include <QIcon>
#include "GeneralAssetPaintBuilder.hpp"
#include "AssetCategoryItemAction.hpp"

namespace map_builder
{

class AssetCategoryItem
{

private:
    QString mName;
    QIcon mIcon;

public:
    AssetCategoryItem(QString name, QIcon icon, GeneralAssetPaintBuilder* painter);

    QString name();
    QIcon icon();

    GeneralAssetPaintBuilder* mPainter;

    AssetPaintBuilder* painter();
    AssetCategoryItemAction *toAction(QObject* parent = nullptr);
};

}
#endif // ASSETCATEGORYITEM_HPP
