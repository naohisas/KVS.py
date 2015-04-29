#pragma once

#include <iostream>
#include <boost/python.hpp>
#include "DebugMessage.h"
#include <kvs/AnyValueArray>
#include <kvs/ValueArray>
#include <kvs/SharedPointer>
#include <kvs/StructuredVolumeObject>

void Test1()
{
    DEBUG_MESSAGE;
}

void Test2()
{
    DEBUG_MESSAGE;

    kvs::AnyValueArray* x = new kvs::AnyValueArray;
    delete x;
}

void Test3()
{
    DEBUG_MESSAGE;

    kvs::ValueArray<float>* x = new kvs::ValueArray<float>( 100 );
    delete x;
}

void Test4()
{
    DEBUG_MESSAGE;

    kvs::ValueArray<float>* x = new kvs::ValueArray<float>();
    delete x;
}

void Test5()
{
    DEBUG_MESSAGE;

    int* x = new int [ 100 ];
    delete [] x;
}

void Test6()
{
    DEBUG_MESSAGE;

    int* x = new int;
    delete x;
}

void Test7()
{
    DEBUG_MESSAGE;

    kvs::SharedPointer<int> p( new int );
}

void Test8()
{
    DEBUG_MESSAGE;

    kvs::StructuredVolumeObject* o = new kvs::StructuredVolumeObject();
    delete o;
}

void Test9()
{
    DEBUG_MESSAGE;

    kvs::SharedPointer<kvs::StructuredVolumeObject> p( new kvs::StructuredVolumeObject() );
}

void Test10()
{
    DEBUG_MESSAGE;

    int* x = new int [ 100 ];
    delete [] x;

    kvs::StructuredVolumeObject* o = new kvs::StructuredVolumeObject();
    delete o;
}

void Debug()
{
    boost::python::def( "Test1", &Test1 );
    boost::python::def( "Test2", &Test2 );
    boost::python::def( "Test3", &Test3 );
    boost::python::def( "Test4", &Test4 );
    boost::python::def( "Test5", &Test5 );
    boost::python::def( "Test6", &Test6 );
    boost::python::def( "Test7", &Test7 );
    boost::python::def( "Test8", &Test8 );
    boost::python::def( "Test9", &Test9 );
    boost::python::def( "Test10", &Test10 );
}
