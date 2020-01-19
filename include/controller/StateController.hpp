#ifndef MAP_MAKER_STATECONTROLLER_HPP
#define MAP_MAKER_STATECONTROLLER_HPP

#include <QObject>
#include "ToolState.hpp"
#include "state/GridState.hpp"

namespace map_builder::controller
{
    class StateController : QObject
    {
    public:
        StateController(state::GridState *grid_state, state::ToolState *toolState, QObject *parent = nullptr);

        inline state::GridState &gridState()
        {
            return *mGridState;
        }

        inline state::ToolState &toolState()
        {
            return *mToolState;
        }

    private:
        state::GridState *mGridState;
        state::ToolState *mToolState;

    };
}
#endif //MAP_MAKER_STATECONTROLLER_HPP
