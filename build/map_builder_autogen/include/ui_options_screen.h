/********************************************************************************
** Form generated from reading UI file 'options_screen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_SCREEN_H
#define UI_OPTIONS_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_options_screen
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphics_view_preview;
    QGridLayout *gridLayout;
    QPushButton *btn_new;
    QPushButton *btn_load;
    QPushButton *btn_manual;
    QPushButton *btn_exit;

    void setupUi(QMainWindow *options_screen)
    {
        if (options_screen->objectName().isEmpty())
            options_screen->setObjectName(QStringLiteral("options_screen"));
        options_screen->resize(431, 321);
        centralwidget = new QWidget(options_screen);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphics_view_preview = new QGraphicsView(centralwidget);
        graphics_view_preview->setObjectName(QStringLiteral("graphics_view_preview"));

        verticalLayout->addWidget(graphics_view_preview);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_new = new QPushButton(centralwidget);
        btn_new->setObjectName(QStringLiteral("btn_new"));

        gridLayout->addWidget(btn_new, 0, 0, 1, 1);

        btn_load = new QPushButton(centralwidget);
        btn_load->setObjectName(QStringLiteral("btn_load"));

        gridLayout->addWidget(btn_load, 0, 1, 1, 1);

        btn_manual = new QPushButton(centralwidget);
        btn_manual->setObjectName(QStringLiteral("btn_manual"));

        gridLayout->addWidget(btn_manual, 1, 0, 1, 1);

        btn_exit = new QPushButton(centralwidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        gridLayout->addWidget(btn_exit, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        options_screen->setCentralWidget(centralwidget);

        retranslateUi(options_screen);

        QMetaObject::connectSlotsByName(options_screen);
    } // setupUi

    void retranslateUi(QMainWindow *options_screen)
    {
        options_screen->setWindowTitle(QApplication::translate("options_screen", "MainWindow", Q_NULLPTR));
        btn_new->setText(QApplication::translate("options_screen", "New", Q_NULLPTR));
        btn_load->setText(QApplication::translate("options_screen", "Load", Q_NULLPTR));
        btn_manual->setText(QApplication::translate("options_screen", "Manual", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("options_screen", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class options_screen: public Ui_options_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_SCREEN_H
