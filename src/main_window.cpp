#include "main_window.hpp"
#include "ui_main_window.h"
#include "pop_up_menu.hpp"
#include "init_worker.hpp"
#include "utils/start_task.hpp"
#include "comunicator.hpp"
#include "comunication/main_window_communication.hpp"
#include "comunication/splash_screen_comunicatior.hpp"
#include "utils/set_style.hpp"
#include <QDebug>
#include <QSpacerItem>
#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QLabel>
#include <QMenu>
#include <QAction>

#include <PaintTool.hpp>
#include <TestAssetPaintBuilder.hpp>
#include <GeneralAssetPaintBuilder.hpp>

#include <QCoreApplication>
#include <QDir>
#include <QDirIterator>
#include <QStringList>

#include "utils/set_style.hpp"
#include "assetCategoryButton.hpp"
#include "assetCategoryItem.hpp"
#include "categoryAsset.hpp"

namespace map_builder
{


main_window::main_window(QWidget *parent)
    : QMainWindow(parent),
    ui{new Ui::main_window()}
{
    ui->setupUi(this);

    set_style_to_widget(this);
    QWidget::setWindowTitle(QString("Nightscream"));



    m_state_controller = new controller::StateController(new state::GridState(10, 10), new state::ToolState,this);
    m_grid_controller = new controller::GridController(ui->graphics_view_grid, ui->graphics_view_minimap,
                                                       m_state_controller, this);


    set_style_to_widget(this);

    /* ====================================== */
    // Adding assets from folder.
    // NOTE: - folders must start with capital letters.
    //       - icons must be writen in format iconFoldername
    //       - pictures and icons end with .png

    ui->scr_objects_content->layout()->addWidget(new QLabel("Assets"));


    // assetsDir = .../assets/
    QDir assetsDir = QCoreApplication::applicationDirPath() + "/assets";
    if (assetsDir.exists()){
        QStringList assetLst = assetsDir.entryList(); // assetLst = {Terrain, Tree, Animals...}
        for (int i = 0; i < assetLst.size(); i++){
            QString assetName = assetLst.at(i); // assetName = Terrain
            if (assetName == '.' || assetName == ".."){
                continue;
            }
            // qDebug() << assetName;
            // assetCategoryDir = .../assets/Terrain/
            QDir assetCategoryDir = QCoreApplication::applicationDirPath() + "/assets/" + assetName;
            std::vector<AssetCategoryItem> aci;

            if (assetCategoryDir.exists()){
                QStringList assetCategoryLst = assetCategoryDir.entryList(); // assetCategoryLst = {Land, Sea, iconTerrain}
                for (int i = 0; i < assetCategoryLst.size(); i++){
                    QString assetCategoryName = assetCategoryLst.at(i); // assetCategoryName = Land
                    if (assetCategoryName == '.' || assetCategoryName == ".."){
                        continue;
                    }
                    QVector<QPair<QString, QPixmap>> painterVariants;
                    // For each asset category name take all of its pngs.
                    // assetCategoryPaintersDir = .../assets/Terrain/Land
                    QDir assetCategoryPaintersDir = QCoreApplication::applicationDirPath() + "/assets/" + assetName + "/" + assetCategoryName;
                    if (assetCategoryPaintersDir.exists()) {
                        QStringList assetCategoryVariantLst = assetCategoryPaintersDir.entryList(); // assetCategoryVariantLst = {g_d.png, g_l.png, g_s.png, icon.png}

                        for (int i = 0; i < assetCategoryVariantLst.size(); i++){
                            QString assetCategoryVariantName = assetCategoryVariantLst.at(i); // assetCategoryVariantName = g_l.png
                            if (assetCategoryVariantName == '.' || assetCategoryVariantName == ".."){
                                continue;
                            }
                            if(!assetCategoryVariantName.startsWith("icon")){
                                // pair = g_l.png, g_l.png
                                QString name = assetCategoryVariantName;
                                name.replace("_", " ");
                                name.replace(".png", " ");
                                QPair<QString, QPixmap> pair = QPair<QString, QPixmap>(name, QPixmap(QCoreApplication::applicationDirPath() + "/assets/" + assetName + "/" + assetCategoryName + "/" + assetCategoryVariantName));
                                painterVariants.push_back(pair);
                            }

                        }
                    } else {
                        qDebug() << QCoreApplication::applicationDirPath() + "/assets/" + assetName + "/" + assetCategoryName + "doesn't exist";
                    }


                    //qDebug() << QCoreApplication::applicationDirPath() + "/assets/" + assetName + "/" + assetCategoryName + ".png";
                    // Painter for Terrain
                    QDir assetCategoryItemDir = QCoreApplication::applicationDirPath() + "/assets/" + assetName + "/" + assetCategoryName;
                    GeneralAssetPaintBuilder *painter;
                    if (assetCategoryItemDir.exists()) {
                        if (assetName == "Terrain"){
                            painter = new GeneralAssetPaintBuilder(painterVariants, AssetPaintType::terrain, this);
                            QIcon assetItemIcon = QIcon(assetCategoryItemDir.path() + "/icon" + assetCategoryName + ".png");
                            aci.push_back(AssetCategoryItem(assetCategoryName, assetItemIcon, painter /*vec of pairs*/));
                        } else {
                            painter = new GeneralAssetPaintBuilder(painterVariants, AssetPaintType::object, this);
                            QIcon assetItemIcon = QIcon(assetCategoryItemDir.path() + "/icon" + assetCategoryName + ".png");
                            aci.push_back(AssetCategoryItem(assetCategoryName, assetItemIcon, painter /*vec of pairs*/));
                        }
                    }

                }
            } else {
                qDebug() << "Doesn't exist";
            }
            auto* tmp = new AssetCategoryButton(CategoryAsset(assetName, QIcon(assetCategoryDir.path() + "/icon" + assetName + ".png"), aci));
            connect(tmp, &AssetCategoryButton::categoryClicked, this, &main_window::categoryButtonClicked);
            ui->scr_objects_content->layout()->addWidget(tmp);
        }
    } else {
        qDebug() << "Desn't exist.";
    }




// Spacer to push the buttons upside.
    ui->scr_objects_content->layout()->addItem(new QSpacerItem(0, 10, QSizePolicy::Expanding, QSizePolicy::Expanding));
    /* ============= ============== =========== */

    // Functions for actions in menu_bar.
    connect(ui->ac_new_file, &QAction::triggered, this, &main_window::create_new_project);
    connect(ui->ac_open_file, &QAction::triggered, this, &main_window::open_project);
    connect(ui->ac_save_file, &QAction::triggered, this, &main_window::save_project);
    connect(ui->ac_save_file_as, &QAction::triggered, this, &main_window::save_as_project);
    connect(ui->ac_exit, &QAction::triggered, this, &main_window::exit_project);
}


void main_window::categoryButtonClicked(AssetPaintBuilder* painter)
{
    m_state_controller->toolState().currentTool(new PaintTool(painter, ui->verticalLayout_2));
}

// Function for creating new project.
void main_window::create_new_project()
{
    QFileDialog dialog;
    dialog.setStyleSheet("style.qss");
    QString new_project = QFileDialog::getSaveFileName(this, tr("Save project"),
                                                       "/Desktop/untitled.txt", "Images (*.jpg)", 0,
                                                       QFileDialog::DontUseNativeDialog);


    utils::start_task<init_worker>(make_comunicator(
            std::make_unique<splash_screen_communication>(),
            std::make_unique<main_window_communication>())
            );

    close_window();
}

// Function for opening another project.
void main_window::open_project()
{
    QFileDialog dialog;
    dialog.setStyleSheet("style.qss");
    QString project = QFileDialog::getOpenFileName(this, "Select project",
                                                       "/Desktop/untitled.txt", "Images (*.jpg)", 0,
                                                       QFileDialog::DontUseNativeDialog);

    utils::start_task<init_worker>(make_comunicator(
            std::make_unique<splash_screen_communication>(),
            std::make_unique<main_window_communication>())
    );

    close_window();
}


// Function for saving existing project.
void main_window::save_project()
{
    QFileDialog dialog;
    dialog.setStyleSheet("style.qss");

    // TODO: Implement saving when format is decided.
}


// Function that saves project as another one.
void main_window::save_as_project()
{
    QFileDialog dialog;
    dialog.setStyleSheet("style.qss");
    QString project = QFileDialog::getOpenFileName(this, "Select project",
                                                       "/Desktop/untitled.txt", "Images (*.jpg)", 0,
                                                       QFileDialog::DontUseNativeDialog);

    utils::start_task<init_worker>(make_comunicator(
            std::make_unique<splash_screen_communication>(),
            std::make_unique<main_window_communication>())
    );

    close_window();
}

// Function for exiting the application.
void main_window::exit_project()
{
    main_window::close();
}

main_window::~main_window()
{
    delete ui;
}

void main_window::close_window()
{
    hide();
    deleteLater();
}



}
