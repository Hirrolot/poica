#ifndef POICA_LANG_PRIVATE_VARIADIC_TO_SEQ
#define POICA_P_LANGRIVATE_VARIADIC_TO_SEQ

#include <boost/preprocessor.hpp>
#include <boost/vmd/vmd.hpp>

// Like BOOST_PP_VARIADIC_TO_SEQ, but takes care about a trailing comma.
// Requires at least 1 passed arguments.
#define POICA_P_LANG_VARIADIC_TO_SEQ(...)                                      \
    POICA_P_LANG_VARIADIC_TO_SEQ_AUX(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define POICA_P_LANG_VARIADIC_TO_SEQ_AUX(seq)                                  \
    BOOST_PP_IF(BOOST_VMD_IS_EMPTY(BOOST_PP_SEQ_ELEM(                          \
                    BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(seq)), seq)),               \
                BOOST_PP_SEQ_POP_BACK(seq),                                    \
                seq)

#endif // POICA_LANG_PRIVATE_VARIADIC_TO_SEQ
