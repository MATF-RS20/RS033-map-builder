#include <utility>
#include "controller/StateController.hpp"
#include "utils/util.hpp"

namespace map_builder::controller
{

    namespace details
    {
    }

    StateController::StateController(state::GridState *grid_state, state::ToolState *toolState, QObject *parent)
    : QObject(parent),
      mGridState(grid_state),
      mToolState(toolState)
    {
        utils::adopt_object(mGridState, this);
        utils::adopt_object(mToolState, this);
    }

    namespace details
    {

    }



}