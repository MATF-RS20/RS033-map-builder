#ifndef MAP_MAKER_PACK_HPP
#define MAP_MAKER_PACK_HPP

#include <cstddef>
#include "types.hpp"
#include "list.hpp"

namespace map_builder::mp
{
    template<typename ...Ts>
    struct list;

    template<typename ...Ts>
    struct tail;

    namespace details
    {
        template<int n, typename ...Ts>
        struct get_;

        template<typename n, typename ...Ts>
        struct length_;

        template<int n, typename T, typename ...Ts>
        struct get_<n, T, Ts...>
        {
            using type = typename get_<n-1, Ts...>::type ;
        };

        template <typename T, typename ...Ts>
        struct get_<0, T, Ts...>
        {
            using  type = T;
        };

        template<typename n, typename T, typename ...Ts>
        struct length_<n, T, Ts...>
        {
            using type = typename length_<int_t<n::value+1>, Ts...>::type;
        };

        template<typename n>
        struct length_<n>
        {
            using type = n;
        };

    }

    template<int n, typename ...Ts>
    struct get
    {
        using type = typename  details::get_<n, Ts...>::type ;
    };

    template<typename ...Ts>
    struct length
    {
        using type = typename details::length_<int_t<0>, Ts...>::type;
    };

    template<typename T, typename ...Ts>
    struct tail<T, Ts...>
    {
        using type = list<Ts...>;
    };
}

#endif //MAP_MAKER_PACK_HPP
