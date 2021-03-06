// Copyright (c) 2005  Tel-Aviv University (Israel).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Boolean_set_operations_2/include/CGAL/Boolean_set_operations_2/Gps_bfs_intersection_visitor.h $
// $Id: Gps_bfs_intersection_visitor.h 48113 2009-02-17 16:21:43Z ophirset $
// 
//

// Author(s)     : Baruch Zukerman <baruchzu@post.tau.ac.il>
//                 Ophir Setter    <ophir.setter@cs.tau.ac.il>


#ifndef CGAL_GPS_BFS_INTERSECTION_VISITOR_H
#define CGAL_GPS_BFS_INTERSECTION_VISITOR_H

#include <CGAL/Boolean_set_operations_2/Gps_bfs_base_visitor.h>

CGAL_BEGIN_NAMESPACE

template <class Arrangement_>
class Gps_bfs_intersection_visitor : 
public Gps_bfs_base_visitor<Arrangement_, Gps_bfs_intersection_visitor<Arrangement_> >
{
  typedef  Arrangement_                                  Arrangement;
  typedef typename Arrangement::Face_iterator            Face_iterator;
  typedef typename Arrangement::Halfedge_iterator        Halfedge_iterator;
  typedef Gps_bfs_intersection_visitor<Arrangement>      Self;
  typedef Gps_bfs_base_visitor<Arrangement, Self>        Base;
  typedef typename Base::Edges_hash                      Edges_hash;
  typedef typename Base::Faces_hash                      Faces_hash;
 

public:

  Gps_bfs_intersection_visitor(Edges_hash* edges_hash,
                               Faces_hash* faces_hash,
                               unsigned int n_polygons): 
    Base(edges_hash, faces_hash, n_polygons)
  {}


    //! contained_criteria
/*! contained_criteria is used to the determine if the face which has 
  inside count should be marked as contained.
  \param ic the inner count of the talked-about face.
  \return true if the face of ic, otherwise false.
*/
  bool contained_criteria(unsigned int ic)
  {
    // intersection means that all polygons contain the face.
    CGAL_assertion(ic <= this->m_num_of_polygons);
    return (ic == this->m_num_of_polygons);
  }

  void after_scan(Arrangement&)
  {}
};

CGAL_END_NAMESPACE

#endif
