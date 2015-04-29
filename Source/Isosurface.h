/*****************************************************************************/
/**
 *  @file   Isosurface.h
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
#include <kvs/Isosurface>
#include "DebugMessage.h"
#include "SharedPointer.h"
#include "StructuredVolumeObject.h"
//#include "UnstructuredVolumeObject.h"
#include "PolygonObject.h"
#include "Python.h"


namespace kvs
{

namespace python
{

class Isosurface
{
    typedef SHARED_POINTER<kvs::Isosurface> SelfType;

public:

    static void Export()
    {
        boost::python::class_<kvs::python::Isosurface>(
            "Isosurface", boost::python::init<>() )
            .def( "setIsolevel", &kvs::python::Isosurface::setIsolevel )
            .def( "execute", &kvs::python::Isosurface::execute );
    }

public:

    SelfType self;

public:

    Isosurface()
    {
        DEBUG_MESSAGE;
        this->self = SelfType( new kvs::Isosurface() );
        DEBUG_MESSAGE;
    }

    void setIsolevel( const double isolevel )
    {
        DEBUG_MESSAGE;
        this->self->setIsolevel( isolevel );
        DEBUG_MESSAGE;
    }

    kvs::python::PolygonObject execute( boost::python::object py_object )
    {
        DEBUG_MESSAGE;

        // Input volume data.
        const std::string class_name = kvs::python::ClassName( py_object.ptr() );
        kvs::ObjectBase* volume = NULL;
        if ( class_name == "StructuredVolumeObject" )
        {
            typedef kvs::python::StructuredVolumeObject Object;
            volume = kvs::python::ClassPointer<Object>( py_object.ptr() )->self.get();
        }
/*
        else if ( class_name == "UnstructuredVolumeObject" )
        {
            typedef kvs::python::UnstructuredVolumeObject Object;
            volume = kvs::python::ClassPointer<Object>( py_object.ptr() )->self.get();
        }
*/
        else
        {
            kvsMessageError( "Unsupported object type in kvs::Isosurface class: '%s'.", class_name.c_str() );
        }

        DEBUG_MESSAGE;

        // Extract isosurfaces.
        this->self->exec( volume );

        DEBUG_MESSAGE;

        // Shallow copy to the output polygon object.
        kvs::python::PolygonObject object;
        object.self = this->self;

        DEBUG_MESSAGE;

        return( object );
    }
};

} // end of namespace python

} // end of namespace kvs
