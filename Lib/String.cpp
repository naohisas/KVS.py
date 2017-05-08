#include "String.h"

namespace kvs
{

namespace python
{

String::String( const std::string& value ):
    kvs::python::Object( PyString_FromString( const_cast<char*>( value.c_str() ) ) )
{
}

String::String( const kvs::python::Object& value ):
    kvs::python::Object( value )
{
}

String::operator std::string() const
{
    return std::string( PyString_AsString( get() ) );
}

} // end of namespace python

} // end of namespace kvs
