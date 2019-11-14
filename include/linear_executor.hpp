#ifndef MAP_MAKER_LINEAR_EXECUTOR_HPP
#define MAP_MAKER_LINEAR_EXECUTOR_HPP

#include <array>
#include <any>
#include "make_index.hpp"
#include "type_list.hpp"
#include "type_pack.hpp"
#include "function_traits.hpp"

namespace map_builder
{
    template <typename ...Callables>
    class linear_executor;
    namespace details
    {

        template<typename T, typename T1>
        inline typename function_traits<T1>::return_value_type  operator%(T &&t, T1 &&t1)
        {
            return std::invoke(std::forward<T1>(t1), std::forward<T>(t));
        }


        template<typename RetVal, typename ListOfArguments, typename SubClass, typename FirstCallable, typename RestCallables, typename ListOfIndex>
        struct gen_execute;


        template<typename RetVal, typename FirstCallable, typename ...Callabels, typename ...Args, typename ...RestCallabels, typename ...indexes>
        struct gen_execute<RetVal, list<Args...>, linear_executor<Callabels...>, FirstCallable, list<RestCallabels...>, list<indexes...>>
        {
            RetVal execute(Args... args)
            {
                auto sub_class = reinterpret_cast<linear_executor<Callabels...>*>(this);
                return
                        (std::any_cast<FirstCallable>(sub_class->m_callables[0])(args...)
                    %
                ...% std::any_cast<typename get<indexes::value, RestCallabels...>::type>(
                                sub_class->m_callables[indexes::value+1]) );

            }
        };
    }

    template <typename ...Callables>
    class linear_executor : public details::gen_execute<
            typename details::function_traits<typename details::get<details::length<Callables...>::value-1, Callables...>::type>::return_value_type,
            typename  details::function_traits<typename details::get<0, Callables...>::type>::arguments_type,
            linear_executor<Callables...>,
                    typename details::get<0, Callables...>::type,
            typename details::tail<Callables...>::type,
            typename details::make_index<typename details::tail<Callables...>::type >::type
            >
    {
    private :
        template<typename ...U>
        explicit linear_executor(U&&... callables)
        :   m_callables{std::forward<U>(callables)...}
        {}




   private:
        std::any m_callables[details::length<Callables...>::value];
        friend class details::gen_execute<
                typename details::function_traits<typename details::get<details::length<Callables...>::value-1, Callables...>::type>::return_value_type,
                typename  details::function_traits<typename details::get<0, Callables...>::type>::arguments_type,
                linear_executor<Callables...>,
                typename details::get<0, Callables...>::type,
                typename details::tail<Callables...>::type,
                typename details::make_index<typename details::tail<Callables...>::type >::type
        >;
        template <typename ...U>
        friend linear_executor<std::remove_reference_t<U>...> make_linear_executor(U&&... args);
    };

    template <typename ...U>
    linear_executor<std::remove_reference_t<U>...> make_linear_executor(U&&... args)
    {
        return linear_executor<std::remove_reference_t<U>...>(std::forward<U>(args)...);
    }
}

#endif //MAP_MAKER_LINEAR_EXECUTOR_HPP
