/********************************************************************************
** Form generated from reading UI file 'splash_screen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASH_SCREEN_H
#define UI_SPLASH_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_splash_screen
{
public:
    QLabel *lb_loading;
    QLabel *lb_status;
    QProgressBar *pb_loading;

    void setupUi(QDialog *splash_screen)
    {
        if (splash_screen->objectName().isEmpty())
            splash_screen->setObjectName(QStringLiteral("splash_screen"));
        splash_screen->resize(570, 149);
        lb_loading = new QLabel(splash_screen);
        lb_loading->setObjectName(QStringLiteral("lb_loading"));
        lb_loading->setGeometry(QRect(160, 20, 251, 21));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(lb_loading->sizePolicy().hasHeightForWidth());
        lb_loading->setSizePolicy(sizePolicy);
        lb_loading->setLineWidth(1);
        lb_loading->setMidLineWidth(0);
        lb_loading->setAlignment(Qt::AlignCenter);
        lb_status = new QLabel(splash_screen);
        lb_status->setObjectName(QStringLiteral("lb_status"));
        lb_status->setGeometry(QRect(0, 110, 561, 20));
        lb_status->setTextFormat(Qt::AutoText);
        lb_status->setAlignment(Qt::AlignCenter);
        pb_loading = new QProgressBar(splash_screen);
        pb_loading->setObjectName(QStringLiteral("pb_loading"));
        pb_loading->setGeometry(QRect(10, 130, 561, 20));
        pb_loading->setMinimumSize(QSize(0, 0));
        pb_loading->setMaximumSize(QSize(16777215, 20));
        pb_loading->setValue(6);
        pb_loading->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(splash_screen);

        QMetaObject::connectSlotsByName(splash_screen);
    } // setupUi

    void retranslateUi(QDialog *splash_screen)
    {
        splash_screen->setWindowTitle(QApplication::translate("splash_screen", "Dialog", Q_NULLPTR));
        lb_loading->setText(QApplication::translate("splash_screen", "Loading...", Q_NULLPTR));
        lb_status->setText(QApplication::translate("splash_screen", "preparing a valley of plenty", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class splash_screen: public Ui_splash_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASH_SCREEN_H
