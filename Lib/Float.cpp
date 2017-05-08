#include "Float.h"
#include <kvs/Assert>


namespace kvs
{

namespace python
{

Float::Float( const kvs::Real32 value ):
    kvs::python::Object( PyFloat_FromDouble( value ) )
{
}

Float::Float( const kvs::Real64 value ):
    kvs::python::Object( PyFloat_FromDouble( value ) )
{
}

Float::Float( const kvs::python::Object& value ):
    kvs::python::Object( PyNumber_Float( value.get() ) )
{
}

Float::operator kvs::Real32() const
{
    return kvs::Real32( PyFloat_AsDouble( get() ) );
}

Float::operator kvs::Real64() const
{
    return kvs::Real64( PyFloat_AsDouble( get() ) );
}

bool Float::check() const
{
    return PyFloat_Check( get() );
}

} // end of namespace python

} // end of namespace kvs
