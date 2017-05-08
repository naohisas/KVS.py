#pragma once
#include "Object.h"
#include <string>


namespace kvs
{

namespace python
{

class String : public kvs::python::Object
{
public:
    String( const std::string& value );
    String( const kvs::python::Object& value );

    operator std::string() const;
};

} // end of namespace python

} // end of namespace kvs
