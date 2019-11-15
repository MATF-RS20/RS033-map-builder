#ifndef MAP_MAKER_COMUNICATOR_HPP
#define MAP_MAKER_COMUNICATOR_HPP

#include <tuple>
#include <type_traits>
#include <QtCore/QObject>
#include "mp/list.hpp"
#include "mp/algorithm.hpp"

namespace map_builder
{


    template<typename ...Comunicators>
    class comunicator : public QObject
    {
    public:
        //enable if element exists
        template<typename Comunicator>
        Comunicator get()
        {

        }
    private:
        template<typename ...U>
        explicit comunicator(U&&... comunicators)
        :   m_comunicators{std::forward<U>(comunicators)...}
        {}

        std::tuple<Comunicators...> m_comunicators;
        template<typename ...U>
        friend
        typename std::enable_if<
                mp::all_diffrent<mp::list<std::decay_t<U>...>>::type::value,
                comunicator<std::remove_reference_t<U>...>*
        >::type
        make_comunicator(U&& ...comunicators);
    };

    template<typename ...U>
    typename std::enable_if<
            mp::all_diffrent<mp::list<std::decay_t<U>...>>::type::value,
            comunicator<std::remove_reference_t<U>...>*
    >::type
    make_comunicator(U&& ...comunicators)
    {
        return new comunicator<std::remove_reference_t<U>...>(std::forward<U>(comunicators)...);
    }

}
#endif //MAP_MAKER_COMUNICATOR_HPP
