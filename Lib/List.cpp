#include "List.h"


namespace kvs
{

namespace python
{

List::List( const size_t size ):
    kvs::python::Object( PyList_New( size ) )
{
}

List::List( const kvs::python::Object& object ):
    kvs::python::Object( object )
{
}

void List::set( const size_t index, const kvs::python::Object& object )
{
    object.increment();
    PyList_SetItem( get(), Py_ssize_t( index ), object.get() );
}

void List::append( const kvs::python::Object& object )
{
    PyList_Append( get(), object.get() );
}

size_t List::size() const
{
    return static_cast<size_t>( PyList_Size( get() ) );
}

kvs::python::Object List::operator [] ( const size_t index ) const
{
    const bool borrowed = true;
    return kvs::python::Object( PyList_GetItem( get(), Py_ssize_t( index ) ), borrowed );
}

} // end of namespace python

} // end of namespace kvs
