#include "ZoomInAction.hpp"

namespace map_builder
{
    ZoomInAction::ZoomInAction(QObject *parent)
    :   Action(parent)
    {}

    void ZoomInAction::applyAction(QGraphicsScene *scene, controller::StateController *stateController)
    {
        stateController->gridState().zoom(state::GridState::zoom_in_factor/2);
    }
}

