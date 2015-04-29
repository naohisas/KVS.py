/*****************************************************************************/
/**
 *  @file   PolygonRenderer.h
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
#include <kvs/PolygonRenderer>
#include "DebugMessage.h"
#include "SharedPointer.h"


namespace kvs
{

namespace python
{

class PolygonRenderer
{
    typedef SHARED_POINTER<kvs::PolygonRenderer> SelfType;

public:

    static void Export()
    {
        boost::python::class_<kvs::python::PolygonRenderer>(
            "PolygonRenderer", boost::python::init<>() );
    }

public:

    SelfType self;

public:

    PolygonRenderer()
    {
        DEBUG_MESSAGE;
        self = SelfType( new kvs::PolygonRenderer() );
        DEBUG_MESSAGE;
    }
};

} // end of namespace python

} // end of namespace kvs
