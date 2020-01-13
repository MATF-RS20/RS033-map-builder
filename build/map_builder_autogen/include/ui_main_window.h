/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *layout_cw;
    QGridLayout *gridLayout;
    QGridLayout *layout_main_grid;
    QVBoxLayout *layout_asset_builder;
    QLabel *lb_terrain_text;
    QToolButton *tool_btn_terrain;
    QLabel *lb_objects_text;
    QScrollArea *scr_objects;
    QWidget *scr_objects_content;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *layout_action_and_tools;
    QPushButton *btn_undo;
    QPushButton *btn_redo;
    QPushButton *btn_preview;
    QPushButton *btn_zoom_in;
    QPushButton *btn_zoom_out;
    QSpacerItem *horizontal_spacer;
    QPushButton *btn_rotate_left;
    QPushButton *btn_rotate_right;
    QPushButton *btn_select_mode;
    QWidget *widget_grid_config_minimap;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter_grid_config;
    QGraphicsView *graphics_view_grid;
    QSplitter *splitter_config_minimap;
    QScrollArea *scr_config_options;
    QWidget *scrollAreaWidgetContents_2;
    QGraphicsView *graphics_view_minimap;
    QMenuBar *menu_bar;
    QMenu *menu_file;
    QMenu *menu_edit;
    QStatusBar *status_bar;

    void setupUi(QMainWindow *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QStringLiteral("main_window"));
        main_window->resize(730, 494);
        layout_cw = new QWidget(main_window);
        layout_cw->setObjectName(QStringLiteral("layout_cw"));
        gridLayout = new QGridLayout(layout_cw);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        layout_main_grid = new QGridLayout();
        layout_main_grid->setObjectName(QStringLiteral("layout_main_grid"));
        layout_asset_builder = new QVBoxLayout();
        layout_asset_builder->setObjectName(QStringLiteral("layout_asset_builder"));
        lb_terrain_text = new QLabel(layout_cw);
        lb_terrain_text->setObjectName(QStringLiteral("lb_terrain_text"));
        lb_terrain_text->setMaximumSize(QSize(100, 20));

        layout_asset_builder->addWidget(lb_terrain_text);

        tool_btn_terrain = new QToolButton(layout_cw);
        tool_btn_terrain->setObjectName(QStringLiteral("tool_btn_terrain"));
        tool_btn_terrain->setMinimumSize(QSize(64, 32));
        tool_btn_terrain->setMaximumSize(QSize(500, 500));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/images/icons/terrain_invert.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_btn_terrain->setIcon(icon);
        tool_btn_terrain->setIconSize(QSize(64, 32));
        tool_btn_terrain->setPopupMode(QToolButton::InstantPopup);
        tool_btn_terrain->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tool_btn_terrain->setAutoRaise(true);
        tool_btn_terrain->setArrowType(Qt::NoArrow);

        layout_asset_builder->addWidget(tool_btn_terrain);

        lb_objects_text = new QLabel(layout_cw);
        lb_objects_text->setObjectName(QStringLiteral("lb_objects_text"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_objects_text->sizePolicy().hasHeightForWidth());
        lb_objects_text->setSizePolicy(sizePolicy);
        lb_objects_text->setMaximumSize(QSize(100, 100));

        layout_asset_builder->addWidget(lb_objects_text);

        scr_objects = new QScrollArea(layout_cw);
        scr_objects->setObjectName(QStringLiteral("scr_objects"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(scr_objects->sizePolicy().hasHeightForWidth());
        scr_objects->setSizePolicy(sizePolicy1);
        scr_objects->setFrameShape(QFrame::NoFrame);
        scr_objects->setLineWidth(0);
        scr_objects->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scr_objects->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scr_objects->setWidgetResizable(true);
        scr_objects_content = new QWidget();
        scr_objects_content->setObjectName(QStringLiteral("scr_objects_content"));
        scr_objects_content->setGeometry(QRect(0, 0, 98, 302));
        verticalLayout = new QVBoxLayout(scr_objects_content);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        toolButton_2 = new QToolButton(scr_objects_content);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy2);
        toolButton_2->setMinimumSize(QSize(64, 32));
        toolButton_2->setMaximumSize(QSize(500, 500));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/images/icons/land.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(32, 16));

        verticalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(scr_objects_content);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        sizePolicy2.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy2);
        toolButton_3->setMinimumSize(QSize(64, 32));
        toolButton_3->setMaximumSize(QSize(500, 500));
        toolButton_3->setIcon(icon1);
        toolButton_3->setIconSize(QSize(32, 16));

        verticalLayout->addWidget(toolButton_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scr_objects->setWidget(scr_objects_content);

        layout_asset_builder->addWidget(scr_objects);


        layout_main_grid->addLayout(layout_asset_builder, 1, 0, 1, 1);

        layout_action_and_tools = new QHBoxLayout();
        layout_action_and_tools->setObjectName(QStringLiteral("layout_action_and_tools"));
        btn_undo = new QPushButton(layout_cw);
        btn_undo->setObjectName(QStringLiteral("btn_undo"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_undo->sizePolicy().hasHeightForWidth());
        btn_undo->setSizePolicy(sizePolicy3);
        btn_undo->setMinimumSize(QSize(20, 20));
        btn_undo->setMaximumSize(QSize(50, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/images/icons/undo_invert.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_undo->setIcon(icon2);
        btn_undo->setIconSize(QSize(32, 16));

        layout_action_and_tools->addWidget(btn_undo);

        btn_redo = new QPushButton(layout_cw);
        btn_redo->setObjectName(QStringLiteral("btn_redo"));
        btn_redo->setMinimumSize(QSize(20, 20));
        btn_redo->setMaximumSize(QSize(50, 50));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/images/icons/redo_invert.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_redo->setIcon(icon3);
        btn_redo->setIconSize(QSize(32, 16));

        layout_action_and_tools->addWidget(btn_redo);

        btn_preview = new QPushButton(layout_cw);
        btn_preview->setObjectName(QStringLiteral("btn_preview"));
        btn_preview->setMinimumSize(QSize(20, 20));
        btn_preview->setMaximumSize(QSize(50, 50));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/images/icons/preview_invert.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_preview->setIcon(icon4);
        btn_preview->setIconSize(QSize(32, 16));

        layout_action_and_tools->addWidget(btn_preview);

        btn_zoom_in = new QPushButton(layout_cw);
        btn_zoom_in->setObjectName(QStringLiteral("btn_zoom_in"));
        btn_zoom_in->setMinimumSize(QSize(20, 20));
        btn_zoom_in->setMaximumSize(QSize(50, 50));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/images/icons/zoom_in_invert.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_zoom_in->setIcon(icon5);
        btn_zoom_in->setIconSize(QSize(32, 16));

        layout_action_and_tools->addWidget(btn_zoom_in);

        btn_zoom_out = new QPushButton(layout_cw);
        btn_zoom_out->setObjectName(QStringLiteral("btn_zoom_out"));
        btn_zoom_out->setMinimumSize(QSize(20, 20));
        btn_zoom_out->setMaximumSize(QSize(50, 50));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/images/icons/zoom_out_invert.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_zoom_out->setIcon(icon6);
        btn_zoom_out->setIconSize(QSize(32, 16));

        layout_action_and_tools->addWidget(btn_zoom_out);

        horizontal_spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout_action_and_tools->addItem(horizontal_spacer);

        btn_rotate_left = new QPushButton(layout_cw);
        btn_rotate_left->setObjectName(QStringLiteral("btn_rotate_left"));
        btn_rotate_left->setMinimumSize(QSize(20, 20));
        btn_rotate_left->setMaximumSize(QSize(50, 50));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/images/icons/rotate_left_invert.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_rotate_left->setIcon(icon7);
        btn_rotate_left->setIconSize(QSize(32, 16));

        layout_action_and_tools->addWidget(btn_rotate_left);

        btn_rotate_right = new QPushButton(layout_cw);
        btn_rotate_right->setObjectName(QStringLiteral("btn_rotate_right"));
        btn_rotate_right->setMinimumSize(QSize(20, 20));
        btn_rotate_right->setMaximumSize(QSize(50, 50));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/images/icons/rotate_right_invert.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_rotate_right->setIcon(icon8);
        btn_rotate_right->setIconSize(QSize(32, 16));

        layout_action_and_tools->addWidget(btn_rotate_right);

        btn_select_mode = new QPushButton(layout_cw);
        btn_select_mode->setObjectName(QStringLiteral("btn_select_mode"));
        btn_select_mode->setMinimumSize(QSize(20, 20));
        btn_select_mode->setMaximumSize(QSize(50, 50));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/images/icons/select_arrow_invert.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_select_mode->setIcon(icon9);
        btn_select_mode->setIconSize(QSize(32, 16));

        layout_action_and_tools->addWidget(btn_select_mode);


        layout_main_grid->addLayout(layout_action_and_tools, 0, 0, 1, 2);

        widget_grid_config_minimap = new QWidget(layout_cw);
        widget_grid_config_minimap->setObjectName(QStringLiteral("widget_grid_config_minimap"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_grid_config_minimap->sizePolicy().hasHeightForWidth());
        widget_grid_config_minimap->setSizePolicy(sizePolicy4);
        widget_grid_config_minimap->setMaximumSize(QSize(5000, 5000));
        horizontalLayout_2 = new QHBoxLayout(widget_grid_config_minimap);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        splitter_grid_config = new QSplitter(widget_grid_config_minimap);
        splitter_grid_config->setObjectName(QStringLiteral("splitter_grid_config"));
        splitter_grid_config->setOrientation(Qt::Horizontal);
        graphics_view_grid = new QGraphicsView(splitter_grid_config);
        graphics_view_grid->setObjectName(QStringLiteral("graphics_view_grid"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(graphics_view_grid->sizePolicy().hasHeightForWidth());
        graphics_view_grid->setSizePolicy(sizePolicy5);
        graphics_view_grid->setMinimumSize(QSize(500, 300));
        graphics_view_grid->setMaximumSize(QSize(5000, 5000));
        splitter_grid_config->addWidget(graphics_view_grid);
        splitter_config_minimap = new QSplitter(splitter_grid_config);
        splitter_config_minimap->setObjectName(QStringLiteral("splitter_config_minimap"));
        splitter_config_minimap->setOrientation(Qt::Vertical);
        scr_config_options = new QScrollArea(splitter_config_minimap);
        scr_config_options->setObjectName(QStringLiteral("scr_config_options"));
        sizePolicy5.setHeightForWidth(scr_config_options->sizePolicy().hasHeightForWidth());
        scr_config_options->setSizePolicy(sizePolicy5);
        scr_config_options->setMinimumSize(QSize(0, 300));
        scr_config_options->setMaximumSize(QSize(300, 800));
        scr_config_options->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 80, 298));
        scr_config_options->setWidget(scrollAreaWidgetContents_2);
        splitter_config_minimap->addWidget(scr_config_options);
        graphics_view_minimap = new QGraphicsView(splitter_config_minimap);
        graphics_view_minimap->setObjectName(QStringLiteral("graphics_view_minimap"));
        sizePolicy5.setHeightForWidth(graphics_view_minimap->sizePolicy().hasHeightForWidth());
        graphics_view_minimap->setSizePolicy(sizePolicy5);
        graphics_view_minimap->setMinimumSize(QSize(0, 0));
        graphics_view_minimap->setMaximumSize(QSize(300, 300));
        splitter_config_minimap->addWidget(graphics_view_minimap);
        splitter_grid_config->addWidget(splitter_config_minimap);

        horizontalLayout_2->addWidget(splitter_grid_config);


        layout_main_grid->addWidget(widget_grid_config_minimap, 1, 1, 1, 1);


        gridLayout->addLayout(layout_main_grid, 0, 0, 1, 2);

        main_window->setCentralWidget(layout_cw);
        menu_bar = new QMenuBar(main_window);
        menu_bar->setObjectName(QStringLiteral("menu_bar"));
        menu_bar->setGeometry(QRect(0, 0, 730, 23));
        menu_file = new QMenu(menu_bar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        menu_edit = new QMenu(menu_bar);
        menu_edit->setObjectName(QStringLiteral("menu_edit"));
        main_window->setMenuBar(menu_bar);
        status_bar = new QStatusBar(main_window);
        status_bar->setObjectName(QStringLiteral("status_bar"));
        QFont font;
        font.setFamily(QStringLiteral("MedievalSharp"));
        status_bar->setFont(font);
        main_window->setStatusBar(status_bar);

        menu_bar->addAction(menu_file->menuAction());
        menu_bar->addAction(menu_edit->menuAction());

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QMainWindow *main_window)
    {
        main_window->setWindowTitle(QApplication::translate("main_window", "MainWindow", Q_NULLPTR));
        lb_terrain_text->setText(QApplication::translate("main_window", "Terrain", Q_NULLPTR));
        tool_btn_terrain->setText(QString());
        lb_objects_text->setText(QApplication::translate("main_window", "Objects", Q_NULLPTR));
        toolButton_2->setText(QString());
        toolButton_3->setText(QString());
        btn_undo->setText(QString());
        btn_redo->setText(QString());
        btn_preview->setText(QString());
        btn_zoom_in->setText(QString());
        btn_zoom_out->setText(QString());
        btn_rotate_left->setText(QString());
        btn_rotate_right->setText(QString());
        btn_select_mode->setText(QString());
        menu_file->setTitle(QApplication::translate("main_window", "&File", Q_NULLPTR));
        menu_edit->setTitle(QApplication::translate("main_window", "&Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
