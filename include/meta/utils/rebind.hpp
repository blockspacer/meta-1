/*
** Created by doom on 19/01/19.
*/

#ifndef META_UTILS_REBIND_HPP
#define META_UTILS_REBIND_HPP

namespace meta
{
    namespace details
    {
        template <typename T, template <typename ...> typename To>
        struct rebind;

        template <template <typename ...> typename From, typename ...Types, template <typename ...> typename To>
        struct rebind<From<Types...>, To>
        {
            using type = To<Types...>;
        };
    }

    template <typename T, template <typename ...> typename To>
    using rebind = typename details::rebind<T, To>::type;
}

#endif /* !META_UTILS_REBIND_HPP */
