/*****************************************************************************/
/**
 *  @file   StructuredVolumeObject.h
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
#include <kvs/StructuredVolumeObject>
#include "DebugMessage.h"
#include "SharedPointer.h"


namespace kvs
{

namespace python
{

class StructuredVolumeObject
{
    typedef SHARED_POINTER<kvs::StructuredVolumeObject> SelfType;

public:

    static void Export()
    {
        boost::python::class_<kvs::python::StructuredVolumeObject>(
            "StructuredVolumeObject", boost::python::init<>() );
    }

public:

    SelfType self;

public:

    StructuredVolumeObject()
    {
        DEBUG_MESSAGE;

//        kvs::StructuredVolumeObject* object = new kvs::StructuredVolumeObject();
//        delete object;

//ok        kvs::AnyValueArray* x = new kvs::AnyValueArray;
//ng        kvs::ValueArray<float>* x = new kvs::ValueArray<float>( 100 );
//ok        kvs::ValueArray<float>* x = new kvs::ValueArray<float>();
//ok        int* x = new int [ 100 ];
//ok        int* x = new int;

        self = SelfType( new kvs::StructuredVolumeObject() );

        DEBUG_MESSAGE;
    }
};

} // end of namespace python

} // end of namespace kvs
