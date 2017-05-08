#include "Interpreter.h"
#include "Python.h"

#define PY_ARRAY_UNIQUE_SYMBOL KVS_PYTHON_NUMPY_ARRAYOBJECT_H
#include <numpy/arrayobject.h>

namespace
{

inline void ImportArray() { import_array(); }

}


namespace kvs
{

namespace python
{

Interpreter::Interpreter( const bool import )
{
    this->initialize( import );
}

Interpreter::~Interpreter()
{
    if ( this->isInitialized() )
    {
        this->finalize();
    }
}

void Interpreter::initialize( const bool import )
{
    Py_Initialize();
    if ( import ) { ::ImportArray(); }
}

void Interpreter::finalize()
{
    Py_Finalize();
}

bool Interpreter::isInitialized() const
{
    return Py_IsInitialized();
}

} // end of namespace python

} // end of namespace kvs
