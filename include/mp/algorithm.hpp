#ifndef MAP_MAKER_ALGORITHM_HPP
#define MAP_MAKER_ALGORITHM_HPP

#include <type_traits>
#include "types.hpp"
#include "list.hpp"
#include "pack.hpp"
#include "algorithm.hpp"

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
   template <typename List, typename T>
    struct push_back;
    template<typename List, typename ElToFind, typename Enable = void>
    struct find_index;
    template<typename List>
    struct is_empty;

    namespace details
    {
        template<typename List, typename FirstEl, typename Enable = void>
        struct all_same_;

        template<typename Index, typename List, typename Current, typename ElToFind, typename Enable = void>
        struct find_index_;

        template<typename Visited, typename NotVisited, typename Current, typename Enable = void>
        struct all_diffrent_;

        template<typename List, typename FirstEl>
        struct all_same_<List, FirstEl, typename std::enable_if<is_empty<List>::type::value>::type>
        {
            using type = std::true_type;
        };

        template<typename List, typename FirstEl>
        struct all_same_<List, FirstEl, typename std::enable_if<!is_empty<List>::type::value>::type>
    {
        using type =
        bool_t<std::is_same<typename get<0, List>::type, FirstEl>::value && all_same_<typename tail<List>::type, FirstEl>::type::value>;
    };

    template<typename Index, typename List, typename Current, typename ElToFind>
    struct find_index_<Index, List, Current, ElToFind, typename std::enable_if<is_empty<List>::type::value>::type >
    {
        using type = typename std::conditional<
                std::is_same_v<Current, ElToFind>,
        Index,
        int_t<-1>
        >::type;
    };

    template<typename Index, typename List, typename Current, typename ElToFind>
    struct find_index_<Index, List, Current, ElToFind, typename std::enable_if<!is_empty<List>::type::value>::type >

    {
        using type = typename std::conditional<
                std::is_same_v<Current, ElToFind>,
        Index,
        typename find_index_<int_t<Index::value+1>, typename tail<List>::type, typename get<0, List>::type, ElToFind>::type
        >::type;
    };

    template<typename Visited, typename NotVisited, typename Current>
    struct all_diffrent_<Visited, NotVisited, Current,
            typename std::enable_if<
                    is_empty<NotVisited>::type::value>::type
    >
    {
        using type = typename std::conditional<
                find_index<Visited, Current>::type::value != -1,
                std::false_type,
                std::true_type
        >::type;
    };

    template<typename Visited, typename NotVisited, typename Current>
    struct all_diffrent_<Visited, NotVisited, Current,
                            typename std::enable_if<
                            !is_empty<NotVisited>::type::value>::type
                            >
                               {
                               using type = typename std::conditional<
                               find_index<Visited, Current>::type::value != -1,
                               std::false_type,
                               typename all_diffrent_<
                               typename push_back<Visited, Current>::type,
                               typename tail<NotVisited>::type ,
                               typename get<0, NotVisited>::type
                               >::type
                               >::type;
                               };

    }
    template<typename List>
    struct all_same
   {
       using type = typename details::all_same_<typename tail<List>::type , get<0, List>>::type;
   };

    template<typename List>
    struct is_empty
                       {
                       using type = typename std::conditional<length<List>::type::value == 0, std::true_type, std::false_type>::type;
                       };

    template<typename List, typename ElToFind>
    struct find_index<List, ElToFind, typename std::enable_if<is_empty<List>::type::value>::type>
                                                                                                     {
                                                                                                     using type = int_t<-1>;
                                                                                                     };

    template<typename List, typename ElToFind>
    struct find_index<List, ElToFind, typename std::enable_if<!is_empty<List>::type::value>::type>
                                                                                                      {
                                                                                                      using type = typename details::find_index_<int_t<0>, typename tail<List>::type, typename get<0, List>::type, ElToFind>::type;
                                                                                                      };
    template<typename List>
    struct all_diffrent
    {
        using type = typename details::all_diffrent_<list<>, typename tail<List>::type, typename get<0, List>::type>::type;
    };
}
#endif //MAP_MAKER_ALGORITHM_HPP
