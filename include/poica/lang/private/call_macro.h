#ifndef POICA_LANG_PRIVATE_CALL_MACRO_H
#define POICA_LANG_PRIVATE_CALL_MACRO_H

#include <boost/preprocessor.hpp>

#define POICA_P_LANG_CALL_MACRO(macro, ...)

#define POICA_P_LANG_CALL_MACRO_SEQ_ARGS(macro, args)                          \
    POICA_P_LANG_CALL_MACRO_SEQ_ARGS_AUX(macro, BOOST_PP_SEQ_ENUM(args))

#define POICA_P_LANG_CALL_MACRO_SEQ_ARGS_AUX(macro, ...) macro(__VA_ARGS__)

#endif // POICA_LANG_PRIVATE_CALL_MACRO_H
