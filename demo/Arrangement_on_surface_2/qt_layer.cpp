// Copyright (c) 2005  Tel-Aviv University (Israel).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Arrangement_on_surface_2/demo/Arrangement_on_surface_2/qt_layer.cpp $
// $Id: qt_layer.cpp 45453 2008-09-09 21:35:22Z lrineau $
//
//
//
// Author(s)     : Baruch Zukerman <baruchzu@post.tau.ac.il>

#include <CGAL/basic.h>


#include "qt_layer.h"
#include "demo_tab.h"
#include <qtabwidget.h>

/*! constructor */
Qt_layer::Qt_layer( QTabWidget * bar ) :
  myBar(bar)
{}

/*! draw - activate the current page widget draw function */
void Qt_layer::draw()
{
  // We peform downcasting from QWigdet* to Qt_widget_demo_tab*
  // , as we know that only
  // Qt_widget_demo_tab objects are stored in the tab pages.
  Qt_widget_base_tab    *w_base_p =
    static_cast<Qt_widget_base_tab *> (myBar->currentPage());

  TraitsType t = w_base_p->traits_type;

  switch ( t ) {
   case SEGMENT_TRAITS:
    {
     Qt_widget_demo_tab<Segment_tab_traits> *w_demo_p =
       static_cast<Qt_widget_demo_tab<Segment_tab_traits> *>
       (myBar->currentPage());
     w_demo_p->lock();
     w_demo_p->draw();
     w_demo_p->unlock();
     break;
    }
   case POLYLINE_TRAITS:
    {
     Qt_widget_demo_tab<Polyline_tab_traits> *w_demo_p =
       static_cast<Qt_widget_demo_tab<Polyline_tab_traits> *>
       (myBar->currentPage());
     w_demo_p->lock();
     w_demo_p->draw();
     w_demo_p->unlock();
     break;
    }
   case CONIC_TRAITS:
    {
     Qt_widget_demo_tab<Conic_tab_traits> *w_demo_p =
       static_cast<Qt_widget_demo_tab<Conic_tab_traits> *>
       (myBar->currentPage());
     w_demo_p->lock();
     w_demo_p->draw();
     w_demo_p->unlock();
     break;
    }
  }


}

