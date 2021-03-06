// Copyright (c) 2000  Max-Planck-Institute Saarbruecken (Germany).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Partition_2/include/CGAL/partition_2.h $
// $Id: partition_2.h 31311 2006-05-29 08:30:22Z wein $
// 
//
// Author(s)     : Susan Hert <hert@mpi-sb.mpg.de>

#ifndef CGAL_PARTITION_H
#define CGAL_PARTITION_H

#include <CGAL/Partition_2/partition_greene_approx_convex_2.h>
#include <CGAL/Partition_2/partition_optimal_convex_2.h>
#include <CGAL/Partition_2/partition_approx_convex_2.h>
#include <CGAL/Partition_2/partition_y_monotone_2.h>

namespace CGAL {

template <class InputIterator, class OutputIterator, class Traits>
inline
OutputIterator greene_approx_convex_partition_2(InputIterator first, 
                                                InputIterator beyond,
                                                OutputIterator result, 
                                                const Traits& traits)
{
   return partition_greene_approx_convex_2(first, beyond, result, traits);
}

template <class InputIterator, class OutputIterator>
inline
OutputIterator greene_approx_convex_partition_2(InputIterator first, 
                                                InputIterator beyond,
                                                OutputIterator result) 
{
   return partition_greene_approx_convex_2(first, beyond, result);
}

template <class InputIterator, class OutputIterator, class Traits>
inline
OutputIterator optimal_convex_partition_2(InputIterator first, 
                                          InputIterator beyond,
                                          OutputIterator result, 
                                          const Traits& traits)
{
   return partition_optimal_convex_2(first, beyond, result, traits);
}

template <class InputIterator, class OutputIterator>
inline
OutputIterator optimal_convex_partition_2(InputIterator first, 
                                          InputIterator beyond,
                                          OutputIterator result) 
{
   return partition_optimal_convex_2(first, beyond, result);
}

template <class InputIterator, class OutputIterator, class Traits>
inline
OutputIterator approx_convex_partition_2(InputIterator first, 
                                         InputIterator beyond,
                                         OutputIterator result, 
                                         const Traits& traits)
{
   return partition_approx_convex_2(first, beyond, result, traits);
}

template <class InputIterator, class OutputIterator>
inline
OutputIterator approx_convex_partition_2(InputIterator first, 
                                         InputIterator beyond,
                                         OutputIterator result) 
{
   return partition_approx_convex_2(first, beyond, result);
}

template <class InputIterator, class OutputIterator, class Traits>
inline
OutputIterator y_monotone_partition_2(InputIterator first, 
                                      InputIterator beyond,
                                      OutputIterator result, 
                                      const Traits& traits)
{
   return partition_y_monotone_2(first, beyond, result, traits);
}

template <class InputIterator, class OutputIterator>
inline
OutputIterator y_monotone_partition_2(InputIterator first, 
                                      InputIterator beyond,
                                      OutputIterator result)
{
   return partition_y_monotone_2(first, beyond, result);
}

}

#endif // CGAL_PARTITION_H
