// Copyright (c) 2009 INRIA Sophia-Antipolis (France).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Mesh_3/include/CGAL/Mesh_3/sliver_criteria.h $
// $Id: sliver_criteria.h 50401 2009-07-06 16:10:24Z stayeb $
//
//
// Author(s)     : Stephane Tayeb
//
//******************************************************************************
// File Description : 
//******************************************************************************

#ifndef CGAL_MESH_3_SLIVER_CRITERIA_H
#define CGAL_MESH_3_SLIVER_CRITERIA_H

#include <CGAL/Mesh_3/min_dihedral_angle.h>
#include <CGAL/Mesh_3/radius_ratio.h>

namespace CGAL {

namespace Mesh_3 {

  
template <typename K>
class Min_dihedral_angle_criterion
{
  typedef typename K::Tetrahedron_3 Tetrahedron_3;
  
public:
  static double default_value;
  
  double operator()(const Tetrahedron_3& t) const
  {
    return CGAL::to_double(minimum_dihedral_angle(t, K()));
  }
  
};

template<typename K> double Min_dihedral_angle_criterion<K>::default_value = 25.; 

  
template <typename K>
class Radius_radio_criterion
{
  typedef typename K::Tetrahedron_3 Tetrahedron_3;
  
public:
  static double default_value;
  
  double operator()(const Tetrahedron_3& t) const
  {
    return CGAL::to_double(radius_ratio(t, K()));
  }
  
};

template<typename K> double Radius_radio_criterion<K>::default_value = 0.25; 
  
  
  
} // end namespace Mesh_3
  
} // end namespace CGAL




#endif // CGAL_MESH_3_SLIVER_CRITERIA_H
