#pragma once
#include <Python.h>
#include <kvs/String>


namespace kvs
{

namespace python
{

inline std::string Version()
{
    const std::string version = kvs::String::ToString( PY_VERSION );
    return version;
}

} // end of namespace python

} // end of namespace kvs
