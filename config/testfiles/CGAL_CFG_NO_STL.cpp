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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Installation/config/testfiles/CGAL_CFG_NO_STL.cpp $
// $Id: CGAL_CFG_NO_STL.cpp 49022 2009-04-29 20:03:21Z spion $
// 
//
// Author(s)     : Lutz Kettner, Sylvain Pion

//| A basic test for the STL.
//| If it fails, it probably means a bad CGAL installation.

#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <list>
#include <iterator>

using std::list;

list<char> lst( const char* s)
{
    list<char> x;
    while (*s != '\0') x.push_back( *s++);
    return x;
}

int main()
{
    list<char> list1 = lst( "mark twain");
    std::reverse( list1.begin(), list1.end());
    assert( list1 == lst( "niawt kram"));
    return 0;
}
