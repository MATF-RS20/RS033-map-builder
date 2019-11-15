#ifndef MAP_MAKER_UTILS_HPP
#define MAP_MAKER_UTILS_HPP
namespace map_builder::mp
{
    template<int n, typename ...Ts>
    struct get;
    template<typename ...Ts>
    struct tail;
    template<typename ...Ts>
    struct length;
    template<typename List, typename T>
    struct push_back;
    template<typename CallableObject>
    struct function_traits;


    template<int n, typename ...Ts>
    using get_t = typename get<n, Ts...>::type;

    template<typename ...Ts>
    using tail_t = typename tail<Ts...>::type;

    template<typename ...Ts>
    using length_t = typename length<Ts...>::type;

    template <typename List, typename T>
    using push_back_t = typename push_back<List, T>::type;

    template<typename F>
    using function_traits_return_value_t=  typename function_traits<F>::return_value_type;
    template<typename F>
    using function_traits_arguments_list_t=  typename function_traits<F>::arguments_type;
}
#endif //MAP_MAKER_UTILS_HPP
