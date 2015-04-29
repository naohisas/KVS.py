/*****************************************************************************/
/**
 *  @file   Application.h
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
#include <kvs/glut/Application>
#include "DebugMessage.h"
#include "SharedPointer.h"


namespace kvs
{

namespace python
{

class Application
{
    typedef SHARED_POINTER<kvs::glut::Application> SelfType;

public:

    static void Export( void )
    {
        boost::python::class_<kvs::python::Application>( "Application" )
            .def( boost::python::init<int,char**>() )
            .def( "run", &kvs::python::Application::run )
            .def( "quit", &kvs::python::Application::quit );
    }

public:

    SelfType self;

public:

    Application( void )
    {
        DEBUG_MESSAGE;
        int argc = 0;
        char** argv = static_cast<char**>( NULL );
        DEBUG_MESSAGE;
        self = SelfType( new kvs::glut::Application( argc, argv ) );
        DEBUG_MESSAGE;
    }

    Application( int argc, char** argv )
    {
        DEBUG_MESSAGE;
        self = SelfType( new kvs::glut::Application( argc, argv ) );
        DEBUG_MESSAGE;
    }

public:

    void run()
    {
        DEBUG_MESSAGE;
        self->run();
        DEBUG_MESSAGE;
    }

    void quit()
    {
        DEBUG_MESSAGE;
        self->quit();
        DEBUG_MESSAGE;
    }
};

} // end of namespace python

} // end of namespace kvs
