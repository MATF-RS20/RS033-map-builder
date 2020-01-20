#ifndef ZOOMOUTACTION_HPP
#define ZOOMOUTACTION_HPP

#include "Action.hpp"

namespace map_builder {

    class ZoomOutAction : public Action
    {
    public:
        ZoomOutAction(QObject *parent = nullptr);

        void applyAction(QGraphicsScene* scene, controller::StateController *stateController) override;
    };

}

#endif // ZOOMOUTACTION_HPP
