#include <ZoomInAction.hpp>
#include "controller/ActionAndToolController.hpp"
#include "MoveTool.hpp"

namespace map_builder::controller
{

    ActionAndToolController::ActionAndToolController(controller::StateController *stateController, QGraphicsScene *scene,
                                                     QLayout *configuratorLayout, QObject *parent)
    :   QObject(parent),
        mStateController{stateController},
        mConfiguratorLayout{configuratorLayout},
        mScene{scene}
    {
    }

    void ActionAndToolController::undoActionClicked()
    {

    }

    void ActionAndToolController::redoActionClicked()
    {

    }

    void ActionAndToolController::zoomInActionClicked()
    {
        Action *action = new ZoomInAction();
        action->applyAction(mScene, mStateController);
        action->deleteLater();
    }

    void ActionAndToolController::zoomOutActionClicked()
    {

    }

    void ActionAndToolController::rotateContraActionClicked()
    {

    }

    void ActionAndToolController::rotateClockActionClicked()
    {

    }

    void ActionAndToolController::moveToolClicked()
    {
        mStateController->toolState().currentTool(new MoveTool(mConfiguratorLayout, this));
    }

    void ActionAndToolController::selectToolClicked()
    {

    }
}

