/*****************************************************************************/
/**
 *  @file   PolygonObject.h
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
#include <kvs/PolygonObject>
#include "DebugMessage.h"
#include "SharedPointer.h"


namespace kvs
{

namespace python
{

class PolygonObject
{
    typedef SHARED_POINTER<kvs::PolygonObject> SelfType;

public:

    static void Export()
    {
        boost::python::class_<kvs::python::PolygonObject>(
            "PolygonObject", boost::python::init<>() );
    }

public:

    SelfType self;

public:

    PolygonObject()
    {
        DEBUG_MESSAGE;
        self = SelfType( new kvs::PolygonObject() );
        DEBUG_MESSAGE;
    }
};

} // end of namespace python

} // end of namespace kvs
