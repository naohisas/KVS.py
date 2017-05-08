#include "Module.h"


namespace kvs
{

namespace python
{

Module::Module( const std::string& name ):
    Object( PyImport_ImportModule( name.c_str() ) )
{
}

Module::Module( const kvs::python::String& name ):
    Object( PyImport_Import( name.get() ) )
{
}

kvs::python::Dict Module::dict() const
{
    kvs::python::Object object( PyModule_GetDict( get() ), true );
    return kvs::python::Dict( object );
}

} // end of namespace python

} // end of namespace kvs
