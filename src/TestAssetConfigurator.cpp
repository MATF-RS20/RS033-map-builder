#include "TestAssetConfigurator.hpp"

namespace map_builder
{

    QMap<QString, QVariant> TestAssetConfigurator::getConfiguration()
    {
        QMap<QString, QVariant> map;
        map["color"] = QColor(mLineEdit->text());
        return map;
    }

    TestAssetConfigurator::TestAssetConfigurator(QWidget *parent)
    :   AssetConfigurator(parent),
        mLineEdit{new QLineEdit(this)}
    {
    }
}
