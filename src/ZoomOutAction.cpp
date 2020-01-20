#include "ZoomOutAction.hpp"

namespace map_builder
{
    ZoomOutAction::ZoomOutAction(QObject *parent)
    : Action(parent)
    {}

    void ZoomOutAction::applyAction(QGraphicsScene *scene, controller::StateController *stateController)
    {
        stateController->gridState().zoom(state::GridState::zoom_in_factor*2);
    }
}
