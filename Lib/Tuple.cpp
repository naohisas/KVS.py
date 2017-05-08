#include "Tuple.h"


namespace kvs
{

namespace python
{

Tuple::Tuple( const size_t size ):
    kvs::python::Object( PyTuple_New( size ) )
{
}

void Tuple::set( const size_t index, const kvs::python::Object& object )
{
    object.increment();
    PyTuple_SetItem( get(), Py_ssize_t( index ), object.get() );
}

kvs::python::Object Tuple::operator [] ( const size_t index ) const
{
    const bool borrowed = true;
    return kvs::python::Object( PyTuple_GetItem( get(), Py_ssize_t( index ) ), borrowed );
}

} // end of namespace python

} // end of namespace kvs
