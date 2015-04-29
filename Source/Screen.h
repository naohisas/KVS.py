/*****************************************************************************/
/**
 *  @file   Screen.h
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
#include <kvs/glut/Application>
#include <kvs/glut/Screen>
#include "SharedPointer.h"
#include "PythonClass.h"
#include "Application.h"

//#include "ImageObject.h"
//#include "PointObject.h"
//#include "LineObject.h"
#include "PolygonObject.h"
#include "StructuredVolumeObject.h"
//#include "UnstructuredVolumeObject.h"

//#include "ImageRenderer.h"
//#include "PointRenderer.h"
//#include "LineRenderer.h"
#include "PolygonRenderer.h"
//#include "RayCastingRenderer.h"


namespace
{

inline kvs::ObjectBase* KVSObject( PyObject* object )
{
    DEBUG_MESSAGE;

    const std::string class_name = kvs::python::ClassName( object );

/*
    if ( class_name == "ImageObject" )
    {
        typedef kvs::python::ImageObject Object;
        return( kvs::python::ClassPointer<Object>( object )->self.get() );
    }
    else if ( class_name == "PointObject" )
    {
        typedef kvs::python::PointObject Object;
        return( kvs::python::ClassPointer<Object>( object )->self.get() );
    }
    else if ( class_name == "LineObject" )
    {
        typedef kvs::python::LineObject Object;
        return( kvs::python::ClassPointer<Object>( object )->self.get() );
    }
*/
//    else if ( class_name == "PolygonObject" )
    if ( class_name == "PolygonObject" )
    {
        DEBUG_MESSAGE;
        typedef kvs::python::PolygonObject Object;
        return( kvs::python::ClassPointer<Object>( object )->self.get() );
    }
    else if ( class_name == "StructuredVolumeObject" )
    {
        DEBUG_MESSAGE;
        typedef kvs::python::StructuredVolumeObject Object;
        return( kvs::python::ClassPointer<Object>( object )->self.get() );
    }
/*
    else if ( class_name == "UnstructuredVolumeObject" )
    {
        typedef kvs::python::UnstructuredVolumeObject Object;
        return( kvs::python::ClassPointer<Object>( object )->self.get() );
    }
*/
    else
    {
        DEBUG_MESSAGE;
        kvsMessageError( "Unknown the type of KVS object; '%s'.", class_name.c_str() );
        return( NULL );
    }
}

inline kvs::RendererBase* KVSRenderer( PyObject* renderer )
{
    DEBUG_MESSAGE;

    const std::string class_name = kvs::python::ClassName( renderer );

/*
    if ( class_name == "ImageRenderer" )
    {
        typedef kvs::python::ImageRenderer Renderer;
        return( kvs::python::ClassPointer<Renderer>( renderer )->self.get() );
    }
    else if ( class_name == "PointRenderer" )
    {
        typedef kvs::python::PointRenderer Renderer;
        return( kvs::python::ClassPointer<Renderer>( renderer )->self.get() );
    }
    else if ( class_name == "LineRenderer" )
    {
        typedef kvs::python::LineRenderer Renderer;
        return( kvs::python::ClassPointer<Renderer>( renderer )->self.get() );
    }
*/
//    else if ( class_name == "PolygonRenderer" )
    if ( class_name == "PolygonRenderer" )
    {
        DEBUG_MESSAGE;
        typedef kvs::python::PolygonRenderer Renderer;
        return( kvs::python::ClassPointer<Renderer>( renderer )->self.get() );
    }
/*
    else if ( class_name == "RayCastingRenderer" )
    {
        typedef kvs::python::RayCastingRenderer Renderer;
        return( kvs::python::ClassPointer<Renderer>( renderer )->self.get() );
    }
*/
    else
    {
        DEBUG_MESSAGE;
        kvsMessageError( "Unknown the type of KVS renderer; '%s'.", class_name.c_str() );
        return( NULL );
    }
}

} // end of namespace


namespace kvs
{

namespace python
{

class Screen
{
    typedef SHARED_POINTER<kvs::glut::Screen> SelfType;

public:

    static void Export( void )
    {
        boost::python::class_<kvs::python::Screen>( "Screen" )
            .def( boost::python::init<boost::python::object>() )
            .def( "registerObject", &kvs::python::Screen::registerObject )
            .def( "setPosition", &kvs::python::Screen::setPosition )
            .def( "setSize", &kvs::python::Screen::setSize )
            .def( "setGeometry", &kvs::python::Screen::setGeometry )
            .def( "setTitle", &kvs::python::Screen::setTitle )
            .def( "show", &kvs::python::Screen::show );
    }

public:

    SelfType self;

public:

    Screen()
    {
        DEBUG_MESSAGE;
        self = SelfType( new kvs::glut::Screen() );
        DEBUG_MESSAGE;
    }

    Screen( boost::python::object py_app )
    {
        DEBUG_MESSAGE;
        kvs::python::Application* app = kvs::python::ClassPointer<kvs::python::Application>( py_app.ptr() );
        self = SelfType( new kvs::glut::Screen( app->self.get() ) );
        DEBUG_MESSAGE;
    }

public:

    void registerObject( boost::python::object py_object, boost::python::object py_renderer )
    {
        DEBUG_MESSAGE;
        kvs::ObjectBase* object = ::KVSObject( py_object.ptr() );
        kvs::RendererBase* renderer = ::KVSRenderer( py_renderer.ptr() );
        DEBUG_MESSAGE;
        self->registerObject( object, renderer );
        DEBUG_MESSAGE;
    }

    void setPosition( const int x, const int y )
    {
        DEBUG_MESSAGE;
        self->setPosition( x, y );
        DEBUG_MESSAGE;
    }

    void setSize( const int width, const int height )
    {
        DEBUG_MESSAGE;
        self->setSize( width, height );
        DEBUG_MESSAGE;
    }

    void setGeometry( const int x, const int y, const int width, const int height )
    {
        DEBUG_MESSAGE;
        self->setGeometry( x, y, width, height );
        DEBUG_MESSAGE;
    }

    void setTitle( const std::string& title )
    {
        DEBUG_MESSAGE;
        self->setTitle( title );
        DEBUG_MESSAGE;
    }

    void show()
    {
        DEBUG_MESSAGE;
        self->show();
        DEBUG_MESSAGE;
    }
};

} // end of namespace python

} // end of namespace kvs
