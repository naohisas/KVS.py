/*****************************************************************************/
/**
 *  @file   kvs.cpp
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
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>

#include "Application.h"
#include "Screen.h"

//#include "ImageImporter.h"
//#include "PointImporter.h"
//#include "LineImporter.h"
//#include "PolygonImporter.h"
#include "StructuredVolumeImporter.h"
//#include "UnstructuredVolumeImporter.h"

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

#include "Isosurface.h"
//#include "ExternalFaces.h"
//#include "Streamline.h"
//#include "SlicePlane.h"
//#include "OrthoSlice.h"

#include "Debug.h"


BOOST_PYTHON_MODULE( kvs )
{
    Debug();

    // Viewer
    kvs::python::Application::Export();
    kvs::python::Screen::Export();

    // Importer
//    kvs::python::ImageImporter::Export();
//    kvs::python::PointImporter::Export();
//    kvs::python::LineImporter::Export();
//    kvs::python::PolygonImporter::Export();
    kvs::python::StructuredVolumeImporter::Export();
//   kvs::python::UnstructuredVolumeImporter::Export();

    // Object
//    kvs::python::ImageObject::Export();
//    kvs::python::PointObject::Export();
//    kvs::python::LineObject::Export();
    kvs::python::PolygonObject::Export();
    kvs::python::StructuredVolumeObject::Export();
//    kvs::python::UnstructuredVolumeObject::Export();

    // Renderer
//    kvs::python::ImageRenderer::Export();
//    kvs::python::PointRenderer::Export();
//    kvs::python::LineRenderer::Export();
    kvs::python::PolygonRenderer::Export();
//    kvs::python::RayCastingRenderer::Export();

    // Mapper
    kvs::python::Isosurface::Export();
//    kvs::python::ExternalFaces::Export();
//    kvs::python::Streamline::Export();
//    kvs::python::SlicePlane::Export();
//    kvs::python::OrthoSlice::Export();
}
