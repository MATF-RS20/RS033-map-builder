//
// Created by trifu on 11/14/2019.
//

#ifndef MAP_MAKER_TYPE_LIST_HPP
#define MAP_MAKER_TYPE_LIST_HPP
#include <cstddef>


namespace map_builder::details
{

    template<typename ...Ts>
    struct list;
    template<int n, typename ...Ts>
    struct get;
    template<typename ...Ts>
    struct length;
    template<typename ...Ts>
    struct tail;


    template<int n, typename ...Ts>
    struct get<n, list<Ts...>>
    {
        using type = typename get<n, Ts...>::type;
    };

    template<typename ...Ts>
    struct length<list<Ts...>>
    {
        static constexpr size_t value = length<Ts...>::value;
    };

    template<typename T, typename ...Ts>
    struct tail<list<T, Ts...>>
    {
        using type = list<Ts...>;
    };

    template <typename List, typename T>
    struct push_back;

    template<typename ...Ts, typename T>
    struct push_back<list<Ts...>, T>
    {
        using type = list<Ts..., T>;
    };

    template <typename List, typename T>
    using push_back_t = typename push_back<List, T>::type;
}

#endif //MAP_MAKER_TYPE_LIST_HPP
