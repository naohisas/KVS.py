#pragma once
#include "Object.h"

namespace kvs
{

namespace python
{

class List : public kvs::python::Object
{
public:
    List( const size_t size = 0 );
    List( const kvs::python::Object& object );

    void set( const size_t index, const kvs::python::Object& object );
    void append( const kvs::python::Object& object );
    size_t size() const;
    kvs::python::Object operator [] ( const size_t index ) const;
};

} // end of namespace python

} // end of namespace kvs
