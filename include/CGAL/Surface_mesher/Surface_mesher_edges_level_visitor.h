// Copyright (c) 2006  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Surface_mesher/include/CGAL/Surface_mesher/Surface_mesher_edges_level_visitor.h $
// $Id: Surface_mesher_edges_level_visitor.h 42968 2008-04-21 16:07:38Z lrineau $
//
//
// Author(s)     : Laurent RINEAU


#ifndef CGAL_SURFACE_MESHER_EDGES_LEVEL_VISITOR_H
#define CGAL_SURFACE_MESHER_EDGES_LEVEL_VISITOR_H

#include <CGAL/Meshes/Triangulation_mesher_level_traits_3.h>

namespace CGAL {

  namespace Surface_mesher {

    template <
      typename Tr,
      typename Surface_mesher,
      typename Previous_level
      >
    class Edges_level_visitor {
      Surface_mesher* surface_mesher;
      Previous_level* previous;

    public:
      typedef typename Tr::Vertex_handle Vertex_handle;
      typedef ::CGAL::Triangulation_mesher_level_traits_3<Tr> Traits;
      typedef typename Traits::Zone Zone;
      typedef typename Traits::Point Point;

      typedef Previous_level Previous_visitor;

      Edges_level_visitor(Surface_mesher* surface_mesher_,
	      Previous_visitor* p)
        : surface_mesher(surface_mesher_), previous(p) {}

      template <typename E, typename P>
      void before_conflicts(E, P) const {}

      template <class E>
      void before_insertion(E,
                            const Point& p,
                            Zone zone)
      {
	surface_mesher->remove_edges(p, zone);
      }

      void after_insertion(const Vertex_handle& v)
      {
	surface_mesher->after_insertion_impl(v);
      }

      template <typename E, typename P, typename Z>
      void after_no_insertion(E, P, Z) const {}

      Previous_visitor& previous_level()
      {
        return *previous;
      }

    }; // end class Edges_level_visitor

  }  // end namespace Surface_mesher

}  // end namespace CGAL

#endif // CGAL_SURFACE_MESHER_EDGES_LEVEL_VISITOR_H
