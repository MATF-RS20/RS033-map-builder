#ifndef MAP_MAKER_LIST_HPP
#define MAP_MAKER_LIST_HPP
#include <cstddef>
#include <type_traits>
#include "types.hpp"



namespace map_builder::mp
{

    template<typename ...Ts>
    struct list;
    template<int n, typename ...Ts>
    struct get;
    template<typename ...Ts>
    struct length;
    template<typename ...Ts>
    struct tail;
    template<typename List>
    struct all_same;
    template <typename List, typename T>
    struct push_back;
    template<typename List, typename ElToFind, typename Enable>
    struct find_index;
    template<typename List>
    struct is_empty;


    template<int n, typename ...Ts>
    struct get<n, list<Ts...>>
    {
        using type = typename get<n, Ts...>::type;
    };

    template<typename ...Ts>
    struct length<list<Ts...>>
    {
        using type = typename length<Ts...>::type;
    };

    template<typename T, typename ...Ts>
    struct tail<list<T, Ts...>>
    {
        using type = list<Ts...>;
    };

    template<typename ...Ts, typename T>
    struct push_back<list<Ts...>, T>
    {
        using type = list<Ts..., T>;
    };

    template <typename List>
    struct head
    {
        using type = typename get<0, List>::type ;
    };





}

#endif //MAP_MAKER_LIST_HPP
