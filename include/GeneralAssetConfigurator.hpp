#ifndef MAP_MAKER_GENERALASSETCONFIGURATOR_HPP
#define MAP_MAKER_GENERALASSETCONFIGURATOR_HPP

#include <QtWidgets/QComboBox>
#include "AssetConfigurator.hpp"

namespace map_builder
{
    class GeneralAssetConfigurator : public AssetConfigurator
    {
    public:
        GeneralAssetConfigurator(QVector<QString> &&assetVariants, QWidget *parent = nullptr);

        QMap<QString, QVariant> getConfiguration() override;

    private:
        QComboBox mCombo;

    };
}
#endif //MAP_MAKER_GENERALASSETCONFIGURATOR_HPP
