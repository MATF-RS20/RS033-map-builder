#ifndef MAP_MAKER_ASSETCONFIGURATOR_HPP
#define MAP_MAKER_ASSETCONFIGURATOR_HPP

#include <QtWidgets/QWidget>

namespace map_builder
{
    class AssetConfigurator : public QWidget
    {
        Q_OBJECT
    public:
        AssetConfigurator(QWidget *parent);

        virtual QMap<QString, QVariant> getConfiguration() = 0;

    signals:
        void configurationChanged(const QMap<QString, QVariant> &configuration);

    };
}
#endif //MAP_MAKER_ASSETCONFIGURATOR_HPP
