// Copyright (c) 2007  GeometryFactory (France).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/BGL/include/CGAL/boost/graph/properties.h $
// $Id: properties.h 37284 2007-03-19 19:36:49Z afabri $
// 
//
// Author(s)     : Andreas Fabri, Fernando Cacciola


#ifndef CGAL_BOOST_GRAPH_BGL_PROPERTIES_H
#define CGAL_BOOST_GRAPH_BGL_PROPERTIES_H

#include <boost/property_map.hpp>
#include <boost/graph/properties.hpp>

#include <CGAL/basic.h>

CGAL_BEGIN_NAMESPACE

enum vertex_is_border_t      { vertex_is_border } ;
enum vertex_point_t          { vertex_point     } ;
enum vertex_external_index_t { vertex_external_index } ;
enum edge_is_border_t        { edge_is_border   } ;
enum edge_external_index_t   { edge_external_index } ;

CGAL_END_NAMESPACE

#endif // CGAL_BOOST_GRAPH_BGL_PROPERTIES_H
