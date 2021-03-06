// Copyright (c) 2006 INRIA Sophia-Antipolis (France).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Apollonius_graph_2/include/CGAL/Apollonius_graph_2/Delage_traits/Edge_conflict_2.h $
// $Id: Edge_conflict_2.h 50086 2009-06-26 07:18:25Z afabri $
// 
//
// Author(s)     : Menelaos Karavelas <mkaravel@tem.uoc.gr>
//                 Christophe Delage <Christophe.Delage@sophia.inria.fr>
//                 David Millman <dlm336@cs.nyu.edu>

#ifndef CGAL_APOLLONIUS_GRAPH_2_EDGE_CONFLICT_2_H
#define CGAL_APOLLONIUS_GRAPH_2_EDGE_CONFLICT_2_H 1


#include <CGAL/Apollonius_graph_2/Delage_traits/Conflict_2.h>

CGAL_BEGIN_NAMESPACE

CGAL_APOLLONIUS_GRAPH_2_BEGIN_NAMESPACE

//-----------------------------------------------------------------------
//                     Edge Conflict Base
//-----------------------------------------------------------------------

template < class K, class Method_tag >
class Edge_conflict_2 : public Conflict_2<K, Method_tag>
{
private:
  typedef Conflict_2<K, Method_tag>       Base;
public:
  typedef typename Base::Inverted_weighted_point   Inverted_weighted_point;
  typedef bool                                     result_type;
  typedef typename Base::Sign                      Sign;

protected:

    bool edge_conflict_test(const Inverted_weighted_point &p2,
                            const Inverted_weighted_point &p3,
                            const Inverted_weighted_point &p4,
                            const Inverted_weighted_point &q,
                            bool b, int /*i23Q*/, int /*i24Q*/) const
    {

        // orientations
        Sign orient23Q = this->orientation(p2, p3, q);
        Sign orient42Q = this->orientation(p4, p2, q);
        Sign orient234 = this->orientation(p2, p3, p4);

        // radical intersections
        Sign radInt23Q = this->radical_intersection(p2, p3, q, -1);
        Sign radInt24Q = this->radical_intersection(p2, p4, q, -1);

        // radical side
        Sign radSid2Q3 = this->radical_side(p2, q, p3, -1);
        Sign radSid2Q4 = this->radical_side(p2, q, p4, -1);

        // order of a line
        bool oolQ24 = this->ordered_on_line(q, p2, p4);
        bool oolQ23 = this->ordered_on_line(q, p2, p3); 

        if ( b )
        {
	  if ( CGAL::sign(q.p()) != POSITIVE ) { return true; }
	  // degenerate case
	  if (orient234 == ZERO && orient23Q == ZERO && orient42Q == ZERO) {
	    return (oolQ23 || oolQ24);
	  } else if (! ((radInt23Q != NEGATIVE && radSid2Q3 == NEGATIVE) && 
			(radInt24Q != NEGATIVE && radSid2Q4 == NEGATIVE))) {
	    // non degenerate case
	    return true;
	  }  else if (orient234 != NEGATIVE) {
	    return orient23Q != POSITIVE && orient42Q != POSITIVE;
	  } else {
	    return orient23Q != POSITIVE || orient42Q != POSITIVE;
	  }
        }
        else
        {
	  CGAL_assertion ( CGAL::sign(q.p()) == POSITIVE );
	  // degenerate case
	  if (orient234 == ZERO && orient23Q == ZERO && orient42Q == ZERO) {
	    return (oolQ23 && oolQ24);
	  } else if (! ((radInt23Q != NEGATIVE && radSid2Q3 == NEGATIVE) && 
                        (radInt24Q != NEGATIVE && radSid2Q4 == NEGATIVE))) {
            // non degenerate case	
	    return false;
	  } else if (orient234 != NEGATIVE) {
	    return orient23Q != POSITIVE || orient42Q != POSITIVE;
	  } else {
	    return orient23Q != POSITIVE && orient42Q != POSITIVE;
	  }
        }
    }
};

CGAL_APOLLONIUS_GRAPH_2_END_NAMESPACE

CGAL_END_NAMESPACE

#endif // CGAL_APOLLONIUS_GRAPH_2_EDGE_CONFLICT_2_H
