#ifndef MAP_MAKER_ACTIONANDTOOLCONTROLLER_HPP
#define MAP_MAKER_ACTIONANDTOOLCONTROLLER_HPP

#include <QtCore/QObject>
#include "StateController.hpp"

namespace map_builder::controller
{
    class ActionAndToolController : public QObject
    {
    public:
        ActionAndToolController(controller::StateController *stateController, QGraphicsScene *scene,
                                QLayout *configuratorLayout, QObject *parent = nullptr);


    public slots:
        void undoActionClicked();
        void redoActionClicked();
        void zoomInActionClicked();
        void zoomOutActionClicked();
        void rotateContraActionClicked();
        void rotateClockActionClicked();
        void moveToolClicked();
        void selectToolClicked();
    private:
        controller::StateController *mStateController;
        QLayout *mConfiguratorLayout;
        QGraphicsScene *mScene;
    };
}
#endif //MAP_MAKER_ACTIONANDTOOLCONTROLLER_HPP
