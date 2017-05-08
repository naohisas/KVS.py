#pragma once
#include "Object.h"

namespace kvs
{

namespace python
{

class Tuple : public kvs::python::Object
{
public:
    Tuple( const size_t size = 0 );

    void set( const size_t index, const kvs::python::Object& object );
    kvs::python::Object operator [] ( const size_t index ) const;
};

} // end of namespace python

} // end of namespace kvs
