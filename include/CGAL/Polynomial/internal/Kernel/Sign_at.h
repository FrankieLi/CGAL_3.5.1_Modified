// Copyright (c) 2005  Stanford University (USA).
// All rights reserved.
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Kinetic_data_structures/include/CGAL/Polynomial/internal/Kernel/Sign_at.h $
// $Id: Sign_at.h 35777 2007-01-23 17:02:20Z drussel $
// 
//
// Author(s)     : Daniel Russel <drussel@alumni.princeton.edu>

#ifndef CGAL_POLYNOMIAL_INTERNAL_SIGN_AT_ROOT_H
#define CGAL_POLYNOMIAL_INTERNAL_SIGN_AT_ROOT_H

#include <CGAL/Polynomial/basic.h>
#include <CGAL/Polynomial/Polynomial.h>
#include <CGAL/Polynomial/polynomial_converters.h>
#include <CGAL/Polynomial/internal/Rational/Sign_at_rational.h>

CGAL_POLYNOMIAL_BEGIN_INTERNAL_NAMESPACE
template <class Root, class K>
class Sign_at
{
  typedef typename K::Function Poly;
  typedef typename K::FT FT;
public:
  Sign_at(K k=K()): k_(k) {
  }
  Sign_at(){}
  typedef typename K::Root argument_type;
  typedef CGAL::Sign result_type;


protected:
 
  template <class MRT>
  CGAL::Sign eval(const Poly&p, const MRT &r) const {
    std::pair<double,double> di= CGAL::to_interval(r);
 
    typename K::Root_stack s= k_.root_stack_object(p,
						   typename K::Root(di.first),
						   typename K::Root(di.second));
    while (!s.empty() && s.top() < r) {
      s.pop();
    }
    if (s.empty()) {
      // there are no roots
      FT mid= (FT(di.first) + FT(di.second))*FT(.5);
      return eval_ft(p, mid);
    } else if (s.top()==r) {
      return CGAL::ZERO;
    } else {
      FT ft= k_.rational_between_roots_object()(r, s.top());
      return eval_ft(p, ft);
    }
  }


  CGAL::Sign eval(const Poly&p, const FT &r) const {
    //typedef typename K::Root_stack_traits::Sign_at SA;
    return eval_ft(p, r);
  }

  CGAL::Sign eval_ft(const Poly&p, const FT &r) const {
    //typedef typename K::Root_stack_traits::Sign_at SA;
    return k_.root_stack_traits_object().sign_at_object()(p, r);
  }
  

  /*template <class RT>
  CGAL::Sign eval(const CGAL_POLYNOMIAL_NS::internal::Explicit_root<RT> &r) {
    typedef  internal::Explicit_root<RT> R;
    typename R::Representation rep= r.representation();
    typedef  typename CGAL_POLYNOMIAL_NS::Polynomial<typename R::Representation> Rep_poly;
    typename CGAL_POLYNOMIAL_NS::Polynomial_converter<typename K::Polynomial, Rep_poly> pc;
    return CGAL::sign(pc(p_)(rep));
    }*/
  K k_;
public:
  template <class T>
  result_type operator()(const Poly &p, const T &v) const
  {
    return eval(p, v);
  }


};

CGAL_POLYNOMIAL_END_INTERNAL_NAMESPACE
#endif
