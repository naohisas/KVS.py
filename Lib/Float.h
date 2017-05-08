#pragma once
#include "Object.h"


namespace kvs
{

namespace python
{

class Float : public kvs::python::Object
{
public:
    Float( const kvs::Real32 value );
    Float( const kvs::Real64 value );
    Float( const kvs::python::Object& value );

    operator kvs::Real32() const;
    operator kvs::Real64() const;
    bool check() const;
};

} // end of namespace python

} // end of namespace kvs
