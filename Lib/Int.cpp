#include "Int.h"

namespace kvs
{

namespace python
{

Int::Int( const kvs::Int32 value ):
    kvs::python::Object( PyInt_FromLong( value ) )
{
}

Int::Int( const kvs::Int64 value ):
    kvs::python::Object( PyInt_FromLong( value ) )
{
}

Int::Int( const kvs::python::Object& value ):
    kvs::python::Object( PyNumber_Int( value.get() ) )
{
}

Int::operator kvs::Int32() const
{
    return kvs::Int32( PyInt_AsLong( get() ) );
}

Int::operator kvs::Int64() const
{
    return kvs::Int64( PyInt_AsLong( get() ) );
}

bool Int::check() const
{
    return PyInt_Check( get() );
}

} // end of namespace python

} // end of namespace kvs
