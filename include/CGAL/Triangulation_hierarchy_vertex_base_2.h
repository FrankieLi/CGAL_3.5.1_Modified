// Copyright (c) 1998  INRIA Sophia-Antipolis (France).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Triangulation_2/include/CGAL/Triangulation_hierarchy_vertex_base_2.h $
// $Id: Triangulation_hierarchy_vertex_base_2.h 48844 2009-04-21 18:28:04Z spion $
// 
//
// Author(s)     : Olivier Devillers <Olivivier.Devillers@sophia.inria.fr>
//                 Mariette Yvinec  <Mariette.Yvinec@sophia.inria.fr>

#ifndef CGAL_TRIANGULATION_HIERARCHY_VERTEX_BASE_2_H
#define CGAL_TRIANGULATION_HIERARCHY_VERTEX_BASE_2_H

#include <CGAL/basic.h>

CGAL_BEGIN_NAMESPACE

template < class Vbb>
class Triangulation_hierarchy_vertex_base_2
 : public Vbb
{
  typedef Vbb                                           Base;
  typedef typename Base::Triangulation_data_structure   Tds;

public:
  typedef typename Base::Point            Point;
  typedef Tds                             Triangulation_data_structure;
  typedef typename Tds::Vertex_handle     Vertex_handle;
  typedef typename Tds::Face_handle       Face_handle;

  template < typename TDS2 >
  struct Rebind_TDS {
    typedef typename Vbb::template Rebind_TDS<TDS2>::Other      Vb2;
    typedef Triangulation_hierarchy_vertex_base_2<Vb2>          Other;
  };

  Triangulation_hierarchy_vertex_base_2()
    : Base(), _up(0), _down(0)
    {}
  Triangulation_hierarchy_vertex_base_2(const Point & p, Face_handle f)
    : Base(p,f), _up(0), _down(0)
    {}
  Triangulation_hierarchy_vertex_base_2(const Point & p)
    : Base(p), _up(0), _down(0)
    {}

  Vertex_handle up() {return _up;}
  Vertex_handle down() {return _down;}
  void set_up(Vertex_handle u) {_up=u;}
  void set_down(Vertex_handle d) { _down=d;}


 private:
  Vertex_handle  _up;    // same vertex one level above
  Vertex_handle  _down;  // same vertex one level below
};

CGAL_END_NAMESPACE

#endif // CGAL_TRIANGULATION_HIERARCHY_VERTEX_BASE_2_H
