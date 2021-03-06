// Copyright (c) 2006  Tel-Aviv University (Israel).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Arrangement_on_surface_2/include/CGAL/Arr_spherical_gaussian_map_3/Arr_polyhedral_sgm_initializer_visitor.h $
// $Id: Arr_polyhedral_sgm_initializer_visitor.h 49062 2009-04-30 16:02:11Z efif $
// 
//
// Author(s)     : Efi Fogel          <efif@post.tau.ac.il>

#ifndef CGAL_ARR_POLYHEDRAL_SGM_INITIALIZER_VISITOR_H
#define CGAL_ARR_POLYHEDRAL_SGM_INITIALIZER_VISITOR_H

#include <CGAL/basic.h>

CGAL_BEGIN_NAMESPACE

template<class PolyhedralSgm, class Polyhedron>
class Arr_polyhedral_sgm_initializer_visitor {
public:
  typedef typename Polyhedron::Vertex_const_handle
                                        Polyhedron_vertex_const_handle;
  typedef typename Polyhedron::Halfedge_const_handle
                                        Polyhedron_halfedge_const_handle;
  typedef typename Polyhedron::Facet_const_handle
                                        Polyhedron_facet_const_handle;

  typedef typename PolyhedralSgm::Vertex_handle         Sgm_vertex_handle;
  typedef typename PolyhedralSgm::Halfedge_handle       Sgm_halfedge_handle;
  typedef typename PolyhedralSgm::Face_handle           Sgm_face_handle;
  typedef typename PolyhedralSgm::Face_const_handle     Sgm_face_const_handle;

  /*! Destructor */
  virtual ~Arr_polyhedral_sgm_initializer_visitor() {}
  
  /*! Pass information from a polyhedron vertex to its dual - a sgm-face */
  virtual void update_dual_vertex(Polyhedron_vertex_const_handle src,
                                  Sgm_face_handle trg)
  {}

  /*! Pass information from a dual vertex (face) to another dual vertex (face)
   * of the same vertex
   */
  virtual void update_dual_vertex(Sgm_face_const_handle src,
                                  Sgm_face_handle trg)
  {}

  /*! Pass information from a polyhedron facet to its dual a sgm-vertex */
  virtual void update_dual_face(Polyhedron_facet_const_handle src,
                                Sgm_vertex_handle trg)
  {}

  /*! Pass information from a polyhedron facet to its dual a sgm-vertex */
  virtual void update_dual_halfedge(Polyhedron_halfedge_const_handle src,
                                    Sgm_halfedge_handle trg)
  {}
};

CGAL_END_NAMESPACE

#endif
