// Copyright (c) 2005-2008 ASCLEPIOS Project, INRIA Sophia-Antipolis (France)
// All rights reserved.
//
// This file is part of the ImageIO Library, and as been adapted for
// CGAL (www.cgal.org).
// You can redistribute it and/or  modify it under the terms of the
// GNU Lesser General Public License as published by the Free Software Foundation;
// version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// These files are provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/CGALimageIO/src/CGALimageIO/convert.h $
// $Id: convert.h 41804 2008-01-24 14:42:03Z lrineau $
//
//
// Author(s)     :  ASCLEPIOS Project (INRIA Sophia-Antipolis), Laurent Rineau

/*************************************************************************
 * convert.h - conversion between types
 *
 * $Id: convert.h 41804 2008-01-24 14:42:03Z lrineau $
 *
 * CopyrightŠINRIA 1998
 *
 * AUTHOR:
 * Gregoire Malandain (greg@sophia.inria.fr)
 * http://www.inria.fr/epidaure/personnel/malandain/
 * 
 * CREATION DATE: 
 * June, 9 1998
 *
 * ADDITIONS, CHANGES
 *
 */

#ifndef _convert_h_
#define _convert_h_







#include <stdio.h> /* memcpy */
#include <string.h> /* memcpy */
#include "typedefs.h"






/* Converts buffers from one type into another.
 *
 * DESCRIPTION:
 *
 * Conversions from types DOUBLE or FLOAT to 
 * others types are all implemented. I hope
 * I do not make mistakes.
 *
 * - When a real value is converted into an integer
 *   one, we take the nearest integer, i.e.
 *   (int)(real value - 0.5) for negative
 *   numbers, and (int)(real value + 0.5) for 
 *   positive ones.
 *
 * - Some conversions are not yet implemented.
 *
 * - When types and pointers are equal, nothing is
 *   done.
 */
extern void ConvertBuffer( void *bufferIn, /* buffer to be converted */
			   bufferType typeIn, /* type of this buffer */
			   void *bufferOut, /* result buffer */
			   bufferType typeOut, /* type of this buffer */
			   int bufferLength /* buffers' length */
			   );

extern void Convert_r32_to_s8( r32 *theBuf,
			       s8 *resBuf,
			       int size );

extern void Convert_r32_to_u8( r32 *theBuf,
			       u8 *resBuf,
			       int size );

extern void Convert_r32_to_s16( r32 *theBuf,
				s16 *resBuf,
				int size );

extern void Convert_r32_to_u16( r32 *theBuf,
				u16 *resBuf,
				int size );







#endif
