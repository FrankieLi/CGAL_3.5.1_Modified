# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( Apollonius_graph_2_example )

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

  create_single_source_cgal_program( "ag2_exact_traits.cpp" )
  create_single_source_cgal_program( "ag2_exact_traits_sqrt.cpp" )
  create_single_source_cgal_program( "ag2_filtered_traits_no_hidden.cpp" )
  create_single_source_cgal_program( "ag2_hierarchy.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

