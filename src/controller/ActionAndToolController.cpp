#include <ZoomInAction.hpp>
#include <SelectTool.hpp>
#include <ZoomOutAction.hpp>
#include <RotateContraAction.hpp>
#include <RotateClockAction.hpp>
#include <DeleteAction.hpp>
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

    void ActionAndToolController::deleteActionClicked()
    {
        Action *action = new DeleteAction();
        action->applyAction(mScene, mStateController);
        action->deleteLater();
    }

    void ActionAndToolController::zoomInActionClicked()
    {
        Action *action = new ZoomInAction();
        action->applyAction(mScene, mStateController);
        action->deleteLater();
    }

    void ActionAndToolController::zoomOutActionClicked()
    {
        Action *action = new ZoomOutAction();
        action->applyAction(mScene, mStateController);
        action->deleteLater();
    }

    void ActionAndToolController::rotateContraActionClicked()
    {
        Action *action = new RotateContraAction();
        action->applyAction(mScene, mStateController);
        action->deleteLater();
    }

    void ActionAndToolController::rotateClockActionClicked()
    {
        Action *action = new RotateClockAction();
        action->applyAction(mScene, mStateController);
        action->deleteLater();
    }

    void ActionAndToolController::moveToolClicked()
    {
        mStateController->toolState().currentTool(new MoveTool(mConfiguratorLayout));
    }

    void ActionAndToolController::selectToolClicked()
    {
        mStateController->toolState().currentTool(new SelectTool(mConfiguratorLayout));
    }
}

