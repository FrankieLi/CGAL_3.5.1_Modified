# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( Alpha_shapes_3_example )

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

  create_single_source_cgal_program( "ex_alpha_shapes_3.cpp" )
  create_single_source_cgal_program( "ex_alpha_shapes_with_hierarchy_3.cpp" )
  create_single_source_cgal_program( "ex_weighted_alpha_shapes_3.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

