#pragma once

#define USE_BOOST_SHARED_POINTER 0

#if USE_BOOST_SHARED_POINTER
    #include <boost/shared_ptr.hpp>
    #define SHARED_POINTER boost::shared_ptr
#else
    #include <kvs/SharedPointer>
    #define SHARED_POINTER kvs::SharedPointer
#endif
