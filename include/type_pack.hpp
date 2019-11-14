//
// Created by trifu on 11/14/2019.
//

#ifndef MAP_MAKER_TYPE_PACK_HPP
#define MAP_MAKER_TYPE_PACK_HPP

#include <cstddef>

namespace map_builder::details
{
    template<typename ...Ts>
    struct list;

    template<int n, typename ...Ts>
    struct get_;

    template<int n, typename ...Ts>
    struct length_;

    template<int n, typename ...Ts>
    struct get
    {
        using type = typename  get_<n, Ts...>::type ;
    };

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

    template<typename ...Ts>
    struct length
    {
        static constexpr size_t value = length_<0, Ts...>::value;
    };

    template<int n, typename T, typename ...Ts>
    struct length_<n, T, Ts...>
    {
        static constexpr size_t value = length_<n+1, Ts...>::value;
    };

    template<int n>
    struct length_<n>
    {
        static constexpr size_t value = n;
    };

    template<typename ...Ts>
    struct tail;

    template<typename T, typename ...Ts>
    struct tail<T, Ts...>
    {
        using type = list<Ts...>;
    };

    template<int n, typename ...T>
    using get_t = typename get<n, T...>::type;

    template<typename ...Ts>
    using tail_t = typename tail<Ts...>::type;
}

#endif //MAP_MAKER_TYPE_PACK_HPP
