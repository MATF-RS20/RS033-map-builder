#ifndef DELETEACTION_HPP
#define DELETEACTION_HPP

#include "Action.hpp"

namespace map_builder
{

    class DeleteAction : public Action
    {
    public:
        DeleteAction(QObject * parent = nullptr);

        void applyAction(QGraphicsScene *scene, controller::StateController *stateController) override;
    };

}

#endif // DELETEACTION_HPP
