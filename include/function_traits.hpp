//
// Created by trifu on 11/14/2019.
//

#ifndef MAP_MAKER_FUNCTION_TRAITS_HPP
#define MAP_MAKER_FUNCTION_TRAITS_HPP

#include "type_list.hpp"

namespace map_builder::details
{

    template<typename CallableObject>
    struct function_traits : function_traits<decltype(&CallableObject::operator())>
    {};

    /*Function pointer*/
    template<typename RetValue, typename ...Arguments>
    struct function_traits<RetValue (*) (Arguments...)>
    {
        using return_value_type = RetValue;
        using arguments_type = list<Arguments...>;
    };

    /*Pointer to member function*/
    template <typename Class, typename RetValue, typename ...Arguments>
    struct function_traits<RetValue (Class::*) (Arguments...)>
    {
        using return_value_type = RetValue;
        using arguments_type = list<Arguments...>;
    };

    /*Pointer to constant member function*/
    template <typename Class, typename RetValue, typename ...Arguments>
    struct function_traits<RetValue (Class::*) (Arguments...) const>
    {
        using return_value_type = RetValue;
        using arguments_type = list<Arguments...>;
    };

    template<typename F>
    using function_traits_return_value_t=  typename function_traits<F>::return_value_type;
    template<typename F>
    using function_traits_arguments_list_t=  typename function_traits<F>::arguments_type;
}

#endif //MAP_MAKER_FUNCTION_TRAITS_HPP
