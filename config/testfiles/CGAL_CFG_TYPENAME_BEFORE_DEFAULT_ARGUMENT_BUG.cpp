// Copyright (c) 2004  Utrecht University (The Netherlands),
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Installation/config/testfiles/CGAL_CFG_TYPENAME_BEFORE_DEFAULT_ARGUMENT_BUG.cpp $
// $Id: CGAL_CFG_TYPENAME_BEFORE_DEFAULT_ARGUMENT_BUG.cpp 32421 2006-07-12 09:03:57Z spion $
// 
//
// Author(s)     : Andreas Fabri <Andreas.Fabri@geometryfactory.com>

struct Class {
  struct Nested_class {
    Nested_class(){}
  };
};


template <class Cl>
void
function(const Cl& cl,
	 typename Cl::Nested_class start =  typename Cl::Nested_class())
{}


int
main()
{
  Class cl;
  function(cl);
  return 0;
}
