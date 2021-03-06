// Copyright (c) 2008  INRIA Sophia-Antipolis (France).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Installation/config/testfiles/CGAL_CFG_NO_CPP0X_DECLTYPE.cpp $
// $Id: CGAL_CFG_NO_CPP0X_DECLTYPE.cpp 49022 2009-04-29 20:03:21Z spion $
//
// Author(s)     : Sylvain Pion

//| If a compiler does not support decltype() (from C++0x)
//| CGAL_CFG_NO_CPP0X_DECLTYPE is set. 

#undef NDEBUG
#include <cassert>

// It also tests if const refs are properly found.
template <typename>
struct Is_const_ref
{ static const bool value = false; };

template <typename T>
struct Is_const_ref <const T&>
{ static const bool value = true; };

void use(int) {}

int f_copy(int i) { return i; }

const int& f_cref(const int & i) { return i; }

int main()
{
  int i = 2;
  decltype(i+i) j = 3;
  use(j);
  assert(! Is_const_ref<decltype(i)>::value);
  assert(! Is_const_ref<decltype(f_copy(i))>::value);
  assert(  Is_const_ref<decltype(f_cref(i))>::value);
  return 0;
}
