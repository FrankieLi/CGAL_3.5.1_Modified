# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( Minkowski_sum_2_example )

CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)
 
if ( COMMAND cmake_policy )
  cmake_policy( SET CMP0003 NEW )  
endif()
 
find_package(CGAL QUIET COMPONENTS Core )

if ( CGAL_FOUND )

  include( ${CGAL_USE_FILE} )

  include( CGAL_CreateSingleSourceCGALProgram )

  include_directories (BEFORE ../../include)

  create_single_source_cgal_program( "approx_inset.cpp" )
  create_single_source_cgal_program( "approx_offset.cpp" )
  create_single_source_cgal_program( "exact_inset.cpp" )
  create_single_source_cgal_program( "exact_offset.cpp" )
  create_single_source_cgal_program( "sum_by_decomposition.cpp" )
  create_single_source_cgal_program( "sum_triangles.cpp" )
  create_single_source_cgal_program( "sum_with_holes.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

