// Copyright (c) 2002  Max-Planck-Institute Saarbruecken (Germany)
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Nef_3/demo/Nef_3/visualization_SM.cpp $
// $Id: visualization_SM.cpp 45458 2008-09-09 22:20:48Z lrineau $
//
//
// Author(s)     : Peter Hachenberger

#include <CGAL/basic.h>
#include <CGAL/Gmpz.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Nef_polyhedron_3.h>
#include <CGAL/IO/Nef_polyhedron_iostream_3.h>
#include <CGAL/IO/Qt_widget_Nef_S2.h>
#include <qapplication.h>

typedef CGAL::Homogeneous<CGAL::Gmpz> Kernel;
typedef CGAL::Nef_polyhedron_3<Kernel> Nef_polyhedron_3;



int main(int argc, char* argv[]) {

  // We've put the typedefs here as VC7 gives us an ICE if they are global typedefs
  typedef Nef_polyhedron_3::Vertex_const_iterator Vertex_const_iterator;
  typedef Nef_polyhedron_3::Nef_polyhedron_S2 Nef_polyhedron_S2;

  Nef_polyhedron_3 N;
  std::cin >> N;
  Vertex_const_iterator v = N.vertices_begin();
  Nef_polyhedron_S2 S(N.get_sphere_map(v));

  QApplication a(argc, argv);
  CGAL::Qt_widget_Nef_S2<Nef_polyhedron_S2>* w =
    new CGAL::Qt_widget_Nef_S2<Nef_polyhedron_S2>(S);
  a.setMainWidget(w);
  w->show();
  return a.exec();
}
