# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( Interpolation_example )

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

  create_single_source_cgal_program( "interpolation_2.cpp" )
  create_single_source_cgal_program( "linear_interpolation_2.cpp" )
  create_single_source_cgal_program( "nn_coordinates_2.cpp" )
  create_single_source_cgal_program( "nn_coordinates_3.cpp" )
  create_single_source_cgal_program( "rn_coordinates_2.cpp" )
  create_single_source_cgal_program( "sibson_interpolation_2.cpp" )
  create_single_source_cgal_program( "surface_neighbor_coordinates_3.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

