#ifndef ROTATECLOCKACTION_HPP
#define ROTATECLOCKACTION_HPP

#include "Action.hpp"

namespace map_builder
{

    class RotateClockAction : public Action
    {
    public:
        RotateClockAction(QObject *parent = nullptr);

        void applyAction(QGraphicsScene *scene, controller::StateController *stateController) override;
    };

}

#endif // ROTATECLOCKACTION_HPP
