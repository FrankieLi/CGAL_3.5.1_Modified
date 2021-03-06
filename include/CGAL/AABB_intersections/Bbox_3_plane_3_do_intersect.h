// Copyright (c) 2008  INRIA Sophia-Antipolis (France), ETHZ (Suisse).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/AABB_tree/include/CGAL/AABB_intersections/Bbox_3_plane_3_do_intersect.h $
// $Id: Bbox_3_plane_3_do_intersect.h 49270 2009-05-10 16:15:24Z cwormser $
// 
//
// Author(s)     : Camille Wormser, Jane Tournois, Pierre Alliez


#ifndef CGAL_PLANE_3_BBOX_3_DO_INTERSECT_H
#define CGAL_PLANE_3_BBOX_3_DO_INTERSECT_H

#include <CGAL/Plane_3.h>
#include <CGAL/Bbox_3.h>

// Opcode like

CGAL_BEGIN_NAMESPACE

namespace CGALi {

  template <class K>
  void get_min_max(const typename K::Vector_3& p,
    const CGAL::Bbox_3& bbox,
    typename K::Point_3& p_min, 
    typename K::Point_3& p_max)
  {
    if(p.x() > 0) {
      if(p.y() > 0) {
	if(p.z() > 0) { p_min = typename K::Point_3(bbox.xmin(), bbox.ymin(),bbox.zmin()); 
	p_max = typename K::Point_3(bbox.xmax(), bbox.ymax(),bbox.zmax());}
	else {							     p_min = typename K::Point_3(bbox.xmin(), bbox.ymin(),bbox.zmax()); 
	p_max = typename K::Point_3(bbox.xmax(), bbox.ymax(),bbox.zmin());}
      }
      else {
	if(p.z() > 0) { p_min = typename K::Point_3(bbox.xmin(), bbox.ymax(),bbox.zmin()); 
	p_max = typename K::Point_3(bbox.xmax(), bbox.ymin(),bbox.zmax());}
	else {					         p_min = typename K::Point_3(bbox.xmin(), bbox.ymax(),bbox.zmax()); 
	p_max = typename K::Point_3(bbox.xmax(), bbox.ymin(),bbox.zmin());}
      }
    }
    else {
      if(p.y() > 0) {
	if(p.z() > 0) { p_min = typename K::Point_3(bbox.xmax(), bbox.ymin(),bbox.zmin()); 
	p_max = typename K::Point_3(bbox.xmin(), bbox.ymax(),bbox.zmax());}
	else {					         p_min = typename K::Point_3(bbox.xmax(), bbox.ymin(),bbox.zmax()); 
	p_max = typename K::Point_3(bbox.xmin(), bbox.ymax(),bbox.zmin());}
      }
      else {
	if(p.z() > 0) { p_min = typename K::Point_3(bbox.xmax(), bbox.ymax(),bbox.zmin()); 
	p_max = typename K::Point_3(bbox.xmin(), bbox.ymin(),bbox.zmax());}
	else {					         p_min = typename K::Point_3(bbox.xmax(), bbox.ymax(),bbox.zmax()); 
	p_max = typename K::Point_3(bbox.xmin(), bbox.ymin(),bbox.zmin());}
      }
    }
  }

  template <class K>
  bool do_intersect(const typename K::Plane_3& plane, 
    const CGAL::Bbox_3& bbox,
    const K&)
  {	
    typename K::Point_3 p_max, p_min;
    get_min_max<K>(plane.orthogonal_vector(), bbox, p_min, p_max);
    return ! (plane.oriented_side(p_max) == ON_NEGATIVE_SIDE || 
      plane.oriented_side(p_min) == ON_POSITIVE_SIDE);
  }

} // namespace CGALi

template <class K>
bool do_intersect(const CGAL::Plane_3<K>& plane, 
		  const CGAL::Bbox_3& bbox)
{
  return typename K::Do_intersect_3()(plane, bbox);
}

template <class K>
bool do_intersect(const CGAL::Bbox_3& bbox, 
		  const CGAL::Plane_3<K>& plane)
{
  return typename K::Do_intersect_3()(plane, bbox);
}


CGAL_END_NAMESPACE

#endif  // CGAL_PLANE_3_BBOX_3_DO_INTERSECT_H


