#pragma once

#include <iostream>
#include <kvs/Macro>

#define ENABLE_DEBUG 1

#if ENABLE_DEBUG
    #define DEBUG_MESSAGE                                                   \
        std::cout << KVS_MACRO_FUNC << " in " << KVS_MACRO_FILE << ":" << KVS_MACRO_LINE << std::endl
#else
    #define DEBUG_MESSAGE
#endif
