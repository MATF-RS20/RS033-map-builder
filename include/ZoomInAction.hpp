#ifndef MAP_MAKER_ZOOMINACTION_HPP
#define MAP_MAKER_ZOOMINACTION_HPP

#include "Action.hpp"

namespace map_builder
{
    class ZoomInAction : public Action
    {
    public:
        ZoomInAction(QObject *parent = nullptr);

        void applyAction(QGraphicsScene *scene, controller::StateController *stateController) override;
    };
}
#endif //MAP_MAKER_ZOOMINACTION_HPP
