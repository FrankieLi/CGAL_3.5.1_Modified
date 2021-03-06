// Copyright (c) 2006 Foundation for Research and Technology-Hellas (Greece).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Segment_Delaunay_graph_2/include/CGAL/Segment_Delaunay_graph_storage_traits_2.h $
// $Id: Segment_Delaunay_graph_storage_traits_2.h 32875 2006-08-01 13:13:36Z mkaravel $
// 
//
// Author(s)     : Menelaos Karavelas <mkaravel@iacm.forth.gr>

#ifndef CGAL_SEGMENT_DELAUNAY_GRAPH_STORAGE_TRAITS_2_H
#define CGAL_SEGMENT_DELAUNAY_GRAPH_STORAGE_TRAITS_2_H 1

#include <CGAL/Segment_Delaunay_graph_2/basic.h>
#include <set>
#include <CGAL/Segment_Delaunay_graph_storage_site_2.h>
#include <CGAL/Segment_Delaunay_graph_simple_storage_site_2.h>
#include <CGAL/Segment_Delaunay_graph_2/Construct_storage_site_2.h>


CGAL_BEGIN_NAMESPACE

//----------------------------------------------------------------------
//----------------------------------------------------------------------

CGAL_SEGMENT_DELAUNAY_GRAPH_2_BEGIN_NAMESPACE

namespace Internal {

  template<class Gt, class USE_SIMPLE_STORAGE_SITE_Tag>
  struct Which_storage_site;

  // use the simple storage site
  template<class Gt>
  struct Which_storage_site<Gt,Tag_false>
  {
    typedef Gt         Geom_traits;
    typedef Tag_false  Storage_site_tag;

    typedef Segment_Delaunay_graph_simple_storage_site_2<Geom_traits>
    Storage_site_2;
  };

  // use the full storage site
  template<class Gt>
  struct Which_storage_site<Gt,Tag_true>
  {
    typedef Gt         Geom_traits;
    typedef Tag_true   Storage_site_tag;

    typedef Segment_Delaunay_graph_storage_site_2<Geom_traits>
    Storage_site_2;
  };


} // namespace Internal

CGAL_SEGMENT_DELAUNAY_GRAPH_2_END_NAMESPACE

//----------------------------------------------------------------------

template<class Gt>
class Segment_Delaunay_graph_storage_traits_2
{
public:
  typedef Gt                                       Geom_traits;
  typedef typename Geom_traits::Point_2            Point_2;
  typedef typename Geom_traits::Site_2             Site_2;
  typedef std::set<Point_2>                        Point_container;
  typedef typename Point_container::iterator       Point_handle;
  typedef typename Point_container::const_iterator const_Point_handle;

private:
  typedef Segment_Delaunay_graph_storage_traits_2<Geom_traits>   Self;
  typedef typename Geom_traits::Intersections_tag                ITag;

public:
  typedef typename
  CGAL_SEGMENT_DELAUNAY_GRAPH_2_NS::Internal::
  Which_storage_site<Self,ITag>::Storage_site_2
  Storage_site_2;

  typedef
  CGAL_SEGMENT_DELAUNAY_GRAPH_2_NS::Construct_storage_site_2<Self>
  Construct_storage_site_2;

  // MK::FIGURE OUT HOW TO PASS A REFERENCE TO GEOM_TRAITS AND HAVE
  // DEFAULT CONSTRUCTOR AS WELL IF POSSIBLE
  Segment_Delaunay_graph_storage_traits_2
  (const Geom_traits& gt = Geom_traits()) : gt_(gt) {}

  inline const Geom_traits& geom_traits() const { return gt_; }

  inline Construct_storage_site_2
  construct_storage_site_2_object() const {
    return Construct_storage_site_2();
  }

private:
  Geom_traits gt_;
};


//----------------------------------------------------------------------
//----------------------------------------------------------------------

CGAL_END_NAMESPACE

#endif // CGAL_SEGMENT_DELAUNAY_GRAPH_STORAGE_TRAITS_2_H
