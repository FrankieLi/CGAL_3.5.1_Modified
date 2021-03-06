# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( Spatial_searching_example )

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

  create_single_source_cgal_program( "circular_query.cpp" )
  create_single_source_cgal_program( "distance_browsing.cpp" )
  create_single_source_cgal_program( "fuzzy_range_query.cpp" )
  create_single_source_cgal_program( "general_neighbor_searching.cpp" )
  create_single_source_cgal_program( "iso_rectangle_2_query.cpp" )
  create_single_source_cgal_program( "nearest_neighbor_searching.cpp" )
  create_single_source_cgal_program( "searching_with_circular_query.cpp" )
  create_single_source_cgal_program( "user_defined_point_and_distance.cpp" )
  create_single_source_cgal_program( "using_fair_splitting_rule.cpp" )
  create_single_source_cgal_program( "weighted_Minkowski_distance.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

