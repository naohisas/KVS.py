/*****************************************************************************/
/**
 *  @file   Python.h
 *  @author Naohisa Sakamoto
 */
/*----------------------------------------------------------------------------
 *
 *  Copyright (c) Visualization Laboratory, Kyoto University.
 *  All rights reserved.
 *  See http://www.viz.media.kyoto-u.ac.jp/kvs/copyright/ for details.
 *
 *  $Id$
 */
/*****************************************************************************/
#pragma once

#include <boost/python.hpp>
#include <string>
#include "DebugMessage.h"


namespace kvs
{

namespace python
{

inline const std::string ClassName( PyObject* class_object )
{
    DEBUG_MESSAGE;
    return( std::string( class_object->ob_type->tp_name ) );
}

template <typename T>
inline T* ClassPointer( PyObject* class_object )
{
    DEBUG_MESSAGE;

    boost::python::converter::extract_pointer<T*> pointer( class_object );

    DEBUG_MESSAGE;

    return( pointer() );
}

} // end of namespace python

} // end of namespace kvs
