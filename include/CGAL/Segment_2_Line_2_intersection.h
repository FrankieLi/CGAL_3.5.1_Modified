// Copyright (c) 2000  Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbruecken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).  All rights reserved.
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Intersections_2/include/CGAL/Segment_2_Line_2_intersection.h $
// $Id: Segment_2_Line_2_intersection.h 45356 2008-09-07 15:09:56Z spion $
// 
//
// Author(s)     : Geert-Jan Giezeman


#ifndef CGAL_SEGMENT_2_LINE_2_INTERSECTION_H
#define CGAL_SEGMENT_2_LINE_2_INTERSECTION_H

#include <CGAL/Line_2.h>
#include <CGAL/Segment_2.h>
#include <CGAL/Point_2.h>
#include <CGAL/kernel_assertions.h>
#include <CGAL/number_utils.h>
#include <CGAL/Object.h>
#include <CGAL/Line_2_Line_2_intersection.h>

CGAL_BEGIN_NAMESPACE

namespace CGALi {

template <class K>
class Segment_2_Line_2_pair {
public:
    enum Intersection_results {NO_INTERSECTION, POINT, SEGMENT};
    Segment_2_Line_2_pair(typename K::Segment_2 const *seg,
                          typename K::Line_2 const *line)
      : _seg(seg), _line(line), _known(false) {}

    Intersection_results intersection_type() const;

    typename K::Point_2    intersection_point() const;
    typename K::Segment_2  intersection_segment() const;
protected:
    typename K::Segment_2 const*_seg;
    typename K::Line_2 const *  _line;
    mutable bool                    _known;
    mutable Intersection_results     _result;
    mutable typename K::Point_2         _intersection_point;
};

template <class K>
inline bool do_intersect(
    const typename K::Segment_2 &p1,
    const typename K::Line_2 &p2,
    const K&)
{
    typedef Segment_2_Line_2_pair<K> pair_t;
    pair_t pair(&p1, &p2);
    return pair.intersection_type() != pair_t::NO_INTERSECTION;
}

template <class K>
Object
intersection(const typename K::Segment_2 &seg, 
	     const typename K::Line_2 &line,
	     const K&)
{
    typedef Segment_2_Line_2_pair<K> is_t;
    is_t ispair(&seg, &line);
    switch (ispair.intersection_type()) {
    case is_t::NO_INTERSECTION:
    default:
        return Object();
    case is_t::POINT:
        return make_object(ispair.intersection_point());
    case is_t::SEGMENT:
        return make_object(seg);
    }
}

template <class K>
Object
intersection(const typename K::Line_2 &line,
	     const typename K::Segment_2 &seg, 
	     const K& k)
{
  return CGALi::intersection(seg, line, k);
}


template <class K>
inline bool do_intersect(
    const typename K::Line_2 &p1,
    const typename K::Segment_2 &p2,
    const K&)
{
    typedef Segment_2_Line_2_pair<K> pair_t;
    pair_t pair(&p2, &p1);
    return pair.intersection_type() != pair_t::NO_INTERSECTION;
}


template <class K>
typename Segment_2_Line_2_pair<K>::Intersection_results
Segment_2_Line_2_pair<K>::intersection_type() const
{
    if (_known)
        return _result;
    // The non const this pointer is used to cast away const.
    _known = true;
    const typename K::Line_2 &l1 = _seg->supporting_line();
    Line_2_Line_2_pair<K> linepair(&l1, _line);
    switch ( linepair.intersection_type()) {
    case Line_2_Line_2_pair<K>::NO_INTERSECTION:
        _result = NO_INTERSECTION;
        break;
    case Line_2_Line_2_pair<K>::POINT:
        _intersection_point = linepair.intersection_point();
        _result = (_seg->collinear_has_on(_intersection_point) )
                ? POINT : NO_INTERSECTION;
        break;
    case Line_2_Line_2_pair<K>::LINE:
        _result = SEGMENT;
        break;
    }
    return _result;
}

template <class K>
typename K::Point_2
Segment_2_Line_2_pair<K>::intersection_point() const
{
    if (!_known)
        intersection_type();
    CGAL_kernel_assertion(_result == POINT);
    return _intersection_point;
}

template <class K>
typename K::Segment_2
Segment_2_Line_2_pair<K>::intersection_segment() const
{
    if (!_known)
        intersection_type();
    CGAL_kernel_assertion(_result == SEGMENT);
    return *_seg;
}

} // namespace CGALi

template <class K>
inline bool
do_intersect(const Segment_2<K> &seg, const Line_2<K> &line)
{
  typedef typename K::Do_intersect_2 Do_intersect;
  return Do_intersect()(seg, line);
}

template <class K>
inline bool
do_intersect(const Line_2<K> &line, const Segment_2<K> &seg)
{
  typedef typename K::Do_intersect_2 Do_intersect;
  return Do_intersect()(line, seg);
}

template <class K>
inline Object
intersection(const Line_2<K> &line, const Segment_2<K> &seg)
{
  typedef typename K::Intersect_2 Intersect;
  return Intersect()(seg, line);
}

template <class K>
inline Object
intersection(const Segment_2<K> &seg, const Line_2<K> &line)
{
  typedef typename K::Intersect_2 Intersect;
  return Intersect()(line, seg);
}

CGAL_END_NAMESPACE

#endif
