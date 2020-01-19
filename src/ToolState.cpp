
#include <ToolState.hpp>
#include "utils/util.hpp"

namespace map_builder::state
{
    ToolState::ToolState(QObject *parent)
    :   QObject(parent),
        mCurrentTool{nullptr}
    {
    }

    void ToolState::currentTool(Tool *tool)
    {

        if(tool)
        {
           if(tool->parent() == nullptr)
           {
                utils::adopt_object(tool, this);
           }

           if(mCurrentTool && mCurrentTool->parent() == this)
           {
               mCurrentTool->deleteLater();
           }

           mCurrentTool = tool;
           emit currentToolChanged(*mCurrentTool);
        }
    }

}


