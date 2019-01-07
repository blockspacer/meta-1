/*
** Created by doom on 02/01/19.
*/

#ifndef META_SEQUENCE_DROP_HPP
#define META_SEQUENCE_DROP_HPP

#include <cstddef>
#include <meta/sequence/list.hpp>
#include <meta/sequence/details/drop_helper.hpp>

namespace meta
{
    namespace details
    {
        template <typename Sequence, std::size_t N>
        struct drop;

        template <typename ...Ts, std::size_t N>
        struct drop<list<Ts...>, N>
        {
            using type = typename details::drop_helper<
                details::choose_drop_step(simplify_drop_num(N, sizeof...(Ts)))
            >::template f<simplify_drop_num(N, sizeof...(Ts)), Ts...>;
        };
    }

    template <typename Sequence, std::size_t N>
    using drop = typename details::drop<Sequence, N>::type;
}

#endif /* !META_SEQUENCE_DROP_HPP */
