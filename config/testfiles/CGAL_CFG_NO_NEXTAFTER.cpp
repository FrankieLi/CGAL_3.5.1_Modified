// Copyright (c) 2006  Utrecht University (The Netherlands),
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Installation/config/testfiles/CGAL_CFG_NO_NEXTAFTER.cpp $
// $Id: CGAL_CFG_NO_NEXTAFTER.cpp 49022 2009-04-29 20:03:21Z spion $
// 
//
// Author(s)     : Andreas Fabri

//| If a compiler doesn't know nextafter() (or only knows _nextafter as VC++ 7.1).
//| nextafter() is part of ISO C99, but not ISO C++98 (hence <math.h> instead of <cmath>).
//| CGAL_CFG_NO_NEXTAFTER is set. 

#include <math.h>

int main()
{
  double d = nextafter(0,0);
  (void) d;
  return 0;
}
