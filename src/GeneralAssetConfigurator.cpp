#include "GeneralAssetConfigurator.hpp"

namespace map_builder
{

    GeneralAssetConfigurator::GeneralAssetConfigurator(QVector<QString> &&assetVariants, QWidget *parent)
    :  AssetConfigurator(parent),
        mCombo{QComboBox(this)}
    {
        for(int i = 0; i < assetVariants.size(); ++i)
        {
            mCombo.addItem(assetVariants[i], QVariant(i));
        }
    }

    QMap<QString, QVariant> GeneralAssetConfigurator::getConfiguration()
    {
        return QMap<QString, QVariant>({{"index", mCombo.currentData(Qt::UserRole)}});
    }
}