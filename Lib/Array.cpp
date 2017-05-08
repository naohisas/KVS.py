#include "Array.h"
#include "NumPy.h"
#include <algorithm>


namespace
{

inline PyObject* New( const int size, const int type )
{
    int ndim = 1;
    npy_intp dims[1] = { size };
    PyArrayObject* array = (PyArrayObject*)PyArray_SimpleNew( ndim, dims, type );
    Py_XINCREF( array );
    return PyArray_Return( array );
}

}

namespace kvs
{

namespace python
{

Array::Array( const kvs::ValueArray<kvs::Int32>& array ):
    kvs::python::Object( ::New( array.size(), NPY_INT32 ) )
{
    PyArrayObject* object = (PyArrayObject*)( get() );
    kvs::Int32* data = (kvs::Int32*)( object->data );
    std::copy( array.begin(), array.end(), data );
}

Array::Array( const kvs::ValueArray<kvs::Int64>& array ):
    kvs::python::Object( ::New( array.size(), NPY_INT64 ) )
{
    PyArrayObject* object = (PyArrayObject*)( get() );
    kvs::Int64* data = (kvs::Int64*)( object->data );
    std::copy( array.begin(), array.end(), data );
}

Array::Array( const kvs::ValueArray<kvs::Real32>& array ):
    kvs::python::Object( ::New( array.size(), NPY_FLOAT32 ) )
{
    PyArrayObject* object = (PyArrayObject*)( get() );
    kvs::Real32* data = (kvs::Real32*)( object->data );
    std::copy( array.begin(), array.end(), data );
}

Array::Array( const kvs::ValueArray<kvs::Real64>& array ):
    kvs::python::Object( ::New( array.size(), NPY_FLOAT64 ) )
{
    PyArrayObject* object = (PyArrayObject*)( get() );
    kvs::Real64* data = (kvs::Real64*)( object->data );
    std::copy( array.begin(), array.end(), data );
}

Array::Array( const kvs::python::Object& value ):
    kvs::python::Object( value )
{
}

Array::operator kvs::ValueArray<kvs::Int32>() const
{
    const int type = PyArray_TYPE( get() );
    if ( type != NPY_INT32 ) { throw ""; }

    const int ndim = PyArray_NDIM( get() );
    if ( ndim != 1 ) { throw ""; }

    const int size = PyArray_DIMS( get() )[0];
    const kvs::Int32* begin = static_cast<kvs::Int32*>( PyArray_DATA( get() ) );
    const kvs::Int32* end = begin + size;
    kvs::ValueArray<kvs::Int32> array( size );
    std::copy( begin, end, array.data() );
    return array;
}

Array::operator kvs::ValueArray<kvs::Int64>() const
{
    const int type = PyArray_TYPE( get() );
    if ( type != NPY_INT64 ) { throw ""; }

    const int ndim = PyArray_NDIM( get() );
    if ( ndim != 1 ) { throw ""; }

    const int size = PyArray_DIMS( get() )[0];
    const kvs::Int64* begin = static_cast<kvs::Int64*>( PyArray_DATA( get() ) );
    const kvs::Int64* end = begin + size;
    kvs::ValueArray<kvs::Int64> array( size );
    std::copy( begin, end, array.data() );
    return array;
}

Array::operator kvs::ValueArray<kvs::Real32>() const
{
    const int type = PyArray_TYPE( get() );
    if ( type != NPY_FLOAT32 ) { throw ""; }

    const int ndim = PyArray_NDIM( get() );
    if ( ndim != 1 ) { throw ""; }

    const int size = PyArray_DIMS( get() )[0];
    const kvs::Real32* begin = static_cast<kvs::Real32*>( PyArray_DATA( get() ) );
    const kvs::Real32* end = begin + size;
    kvs::ValueArray<kvs::Real32> array( size );
    std::copy( begin, end, array.data() );
    return array;
}

Array::operator kvs::ValueArray<kvs::Real64>() const
{
    const int type = PyArray_TYPE( get() );
    if ( type != NPY_FLOAT64 ) { throw ""; }

    const int ndim = PyArray_NDIM( get() );
    if ( ndim != 1 ) { throw ""; }

    const int size = PyArray_DIMS( get() )[0];
    const kvs::Real64* begin = static_cast<kvs::Real64*>( PyArray_DATA( get() ) );
    const kvs::Real64* end = begin + size;
    kvs::ValueArray<kvs::Real64> array( size );
    std::copy( begin, end, array.data() );
    return array;
}

bool Array::check() const
{
    return PyArray_Check( get() );
}

} // end of namespace python

} // end of namespace kvs
