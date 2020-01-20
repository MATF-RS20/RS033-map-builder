#ifndef ROTATECONTRAACTION_HPP
#define ROTATECONTRAACTION_HPP

#include "Action.hpp"

namespace map_builder
{

    class RotateContraAction : public Action
    {
    public:
        RotateContraAction(QObject *parent = nullptr);

        void applyAction(QGraphicsScene *scene, controller::StateController *stateController) override;
    };

}

#endif // ROTATECONTRAACTION_HPP
