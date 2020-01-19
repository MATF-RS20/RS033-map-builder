#ifndef MAP_MAKER_TOOLSTATE_HPP
#define MAP_MAKER_TOOLSTATE_HPP

#include <QtCore/QObject>
#include "Tool.hpp"

namespace map_builder::state
{
    class ToolState : public QObject
    {
        Q_OBJECT
    public:
        explicit ToolState(QObject *parent = nullptr);

        inline Tool& currentTool()
        {
            return *mCurrentTool;
        }

        void currentTool(Tool *tool);

    signals:
        void currentToolChanged(Tool &tool);

    private:
        Tool *mCurrentTool;
    };
}

#endif //MAP_MAKER_TOOLSTATE_HPP
