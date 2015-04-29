/*****************************************************************************/
/**
 *  @file   StructuredVolumeImporter.h
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
#include <kvs/SharedPointer>
#include <kvs/StructuredVolumeImporter>
#include "DebugMessage.h"
#include "SharedPointer.h"
#include "StructuredVolumeObject.h"


namespace kvs
{

namespace python
{

class StructuredVolumeImporter
{
    typedef SHARED_POINTER<kvs::StructuredVolumeImporter> SelfType;

public:

    static void Export()
    {
        boost::python::class_<kvs::python::StructuredVolumeImporter>(
            "StructuredVolumeImporter", boost::python::init<>() )
            .def( "execute", &kvs::python::StructuredVolumeImporter::execute );
    }

public:

    SelfType self;

public:

    StructuredVolumeImporter()
    {
        DEBUG_MESSAGE;
        this->self = SelfType( new kvs::StructuredVolumeImporter() );
        DEBUG_MESSAGE;
    }

    kvs::python::StructuredVolumeObject execute( const std::string& filename )
    {
        /* Ideally, the method 'exec( filename )' should be called as follows:
         *   this->self->exec( filename );
         *   kvs::python::StructuredVolumeObject object;
         *   object.self = this->self;
         * But, it has not been implemented in the current KVS yet.
         */
        DEBUG_MESSAGE;

        kvs::python::StructuredVolumeObject object;

        DEBUG_MESSAGE;

        object.self = SelfType( new kvs::StructuredVolumeImporter( filename ) );

        DEBUG_MESSAGE;

        return( object );
    }
};

} // end of namespace python

} // end of namespace kvs
