#ifndef MAP_MAKER_TESTASSETCONFIGURATOR_HPP
#define MAP_MAKER_TESTASSETCONFIGURATOR_HPP

#include <QtWidgets/QLineEdit>
#include "AssetConfigurator.hpp"

namespace map_builder
{
   class TestAssetConfigurator : public AssetConfigurator
   {
   public:
       TestAssetConfigurator(QWidget *parent = nullptr);

       QMap<QString, QVariant> getConfiguration() override;

   private:
       QLineEdit *mLineEdit;
   };
}
#endif //MAP_MAKER_TESTASSETCONFIGURATOR_HPP
