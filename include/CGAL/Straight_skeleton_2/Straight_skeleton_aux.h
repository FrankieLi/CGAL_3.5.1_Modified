// Copyright (c) 2006 Fernando Luis Cacciola Carballal. All rights reserved.
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Straight_skeleton_2/include/CGAL/Straight_skeleton_2/Straight_skeleton_aux.h $
// $Id: Straight_skeleton_aux.h 40295 2007-09-10 14:07:00Z fcacciola $
//
// Author(s)     : Fernando Cacciola <fernando_cacciola@ciudad.com.ar>
//
#ifndef CGAL_STRAIGHT_SKELETON_AUX_H
#define CGAL_STRAIGHT_SKELETON_AUX_H 1

#include <boost/optional/optional.hpp>
#include <boost/none.hpp>

#include <CGAL/Straight_skeleton_2/assertions.h>
#include <CGAL/Straight_skeleton_2/debug.h>
#include <CGAL/Straight_skeleton_2/test.h>

//
// The heap objects used in this implementation are intrusively reference counted. Thus, they inherit from Ref_counted_base.
//
CGAL_BEGIN_NAMESPACE

namespace CGAL_SS_i
{


//
// This record encapsulates the defining contour halfedges for a node (both contour and skeleton)
//
template<class Handle_>
class Triedge 
{
public:

  typedef Handle_ Handle ;
  
  typedef Triedge<Handle> Self ;
  
  Triedge() {}
  
  // Contour nodes (input polygon vertices) have only 2 defining contour edges    
  Triedge ( Handle aE0, Handle aE1 )
  {
    mE[0] = aE0 ;
    mE[1] = aE1 ;
    // mE[2] gets default constructed, i.e., "null".
  }              
  
  // Skeleton nodes (offset polygon vertices) have 3 defining contour edges    
  Triedge ( Handle aE0, Handle aE1 , Handle aE2 )
  {
    mE[0] = aE0 ;
    mE[1] = aE1 ;
    mE[2] = aE2 ;
  }              
  
  Handle e( unsigned idx ) const { CGAL_assertion(idx<3); return mE[idx]; }
  
  Handle e0() const { return e(0); }
  Handle e1() const { return e(1); }
  Handle e2() const { return e(2); }
  
  bool is_valid() const 
  { 
    return    handle_assigned(e0())
           && handle_assigned(e1())
           && e0() != e1() && e1() != e2() ; 
  }
  
  bool is_contour () const { return !handle_assigned(e2()) ; }
  bool is_skeleton() const { return  handle_assigned(e2()) ; }
  
  // returns 1 if aE is one of the halfedges stored in this triedge, 0 otherwise.
  int contains ( Handle aE ) const
  {
    return aE == e0() || aE == e1() || aE == e2() ? 1 : 0 ;
  }
  
  // Returns the number of common halfedges in the two triedges x and y
  static int CountInCommon( Self const& x, Self const& y )
  {
    return x.contains(y.e0()) + x.contains(y.e1()) + x.contains(y.e2()) ; 
  }
  
  // Returns true if the triedges store the same 3 halfedges (in any order)
  friend bool operator == ( Self const& x, Self const& y ) { return CountInCommon(x,y) == 3 ; }
  
  friend bool operator != ( Self const& x, Self const& y ) { return !(x==y) ; }
  
  friend Self operator & ( Self const& x, Self const& y )
  {
    return Self(x.e0(), x.e1(), ( x.e0() == y.e0() || x.e1() == y.e0() ) ? y.e1() : y.e0()  ) ;
  }
  
  static void insert_handle_id( std::ostream& ss, Handle aH )
  {  
    if ( handle_assigned(aH) )
         ss << aH->id() ;
    else ss << "#" ;
  }
  
  friend std::ostream& operator<< ( std::ostream& ss, Self const& t )
  {
    ss << "{E" ;
    insert_handle_id(ss,t.e0())  ;
    ss << ",E" ;
    insert_handle_id(ss,t.e1()) ;
    ss << ",E" ;
    insert_handle_id(ss,t.e2()) ;
    ss << "}" ;
    return ss ;
  }
  
private:
  

  Handle mE[3];
} ;

} // namespace CGAL_SS_i

enum Trisegment_collinearity
{ 
    TRISEGMENT_COLLINEARITY_NONE
  , TRISEGMENT_COLLINEARITY_01
  , TRISEGMENT_COLLINEARITY_12
  , TRISEGMENT_COLLINEARITY_02
  , TRISEGMENT_COLLINEARITY_ALL
} ;

static char const* trisegment_collinearity_to_string( Trisegment_collinearity c )
{
  switch ( c )
  {
    case TRISEGMENT_COLLINEARITY_NONE : return "<>" ;  
    case TRISEGMENT_COLLINEARITY_01   : return "<0,1>" ; 
    case TRISEGMENT_COLLINEARITY_12   : return "<1,2>" ; 
    case TRISEGMENT_COLLINEARITY_02   : return "<0,2>" ; 
    case TRISEGMENT_COLLINEARITY_ALL  : return "<0,1,2>" ; 
  }
  
  return "!!UNKNOWN COLLINEARITY!!" ;
}
namespace CGALi 
{

template <>
struct Minmax_traits< Trisegment_collinearity >
{
  static const Trisegment_collinearity min = TRISEGMENT_COLLINEARITY_NONE;
  static const Trisegment_collinearity max = TRISEGMENT_COLLINEARITY_ALL;
};

}

class Ref_counted_base
{
private:
  mutable long mCount ;
  Ref_counted_base( Ref_counted_base const &);
  Ref_counted_base& operator=( Ref_counted_base const &);
protected:
  Ref_counted_base(): mCount(0) {}
  virtual ~Ref_counted_base() {}
public:
    void AddRef() const { ++mCount; }
    void Release() const
      {
        if( --mCount == 0 )
          delete this;
      }
};

CGAL_END_NAMESPACE

namespace boost
{
inline void intrusive_ptr_add_ref( CGAL::Ref_counted_base const* p ) { p->AddRef(); }
inline void intrusive_ptr_release( CGAL::Ref_counted_base const* p ) { p->Release(); }
} // namespace boost



#endif // CGAL_STRAIGHT_SKELETON_AUX_H //
// EOF //

