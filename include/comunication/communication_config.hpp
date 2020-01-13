#ifndef MAP_MAKER_COMMUNICATION_CONFIG_HPP
#define MAP_MAKER_COMMUNICATION_CONFIG_HPP

#include <memory>
namespace map_builder
{

    class splash_screen_communication;
    class options_communication;

    using comunicator_type =
            comunicator<
                    std::unique_ptr<splash_screen_communication>,
                    std::unique_ptr<options_communication>
                    >;
}
#endif //MAP_MAKER_COMMUNICATION_CONFIG_HPP
