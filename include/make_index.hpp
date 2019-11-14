#ifndef MAP_MAKER_MAKE_INDEX_HPP
#define MAP_MAKER_MAKE_INDEX_HPP

#include "type_pack.hpp"
#include "type_list.hpp"
#include "types.hpp"

namespace map_builder::details
{
   template<typename ...Ts>
    struct make_index;

    template<typename ...Ts>
    struct make_index<list<Ts...>> : public make_index<Ts...>
            {};

    template<typename T, typename ...Ts>
    struct make_index<T, Ts...>
    {
        using type = typename push_back<
                typename make_index<Ts...>::type ,
                int_t<get<
                        length<typename make_index<Ts...>::type>::value-1,
                        typename make_index<Ts...>::type
                        >::type::value+1>
                >::type;

    };

    template<typename T>
    struct make_index<T>
    {
        using type = list<int_t<0>>;
    };
}

#endif //MAP_MAKER_MAKE_INDEX_HPP
