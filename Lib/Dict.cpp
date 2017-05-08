#include "Dict.h"


namespace kvs
{

namespace python
{

Dict::Dict( const kvs::python::Object& object ):
    Object( object )
{
}

kvs::python::Object Dict::find( kvs::python::Object& key ) const
{
    return kvs::python::Object( PyDict_GetItem( get(), key.get() ), true );
}

kvs::python::Object Dict::find( const std::string& key ) const
{
    return kvs::python::Object( PyDict_GetItemString( get(), key.c_str() ), true );
}

bool Dict::check() const
{
    return PyDict_Check( get() );
}

size_t Dict::size() const
{
    return size_t( PyDict_Size( get() ) );
}

void Dict::clear()
{
    PyDict_Clear( get() );
}

} // end of namespace python

} // end of namespace kvs
