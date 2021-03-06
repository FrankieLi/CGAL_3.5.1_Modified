cmake_minimum_required(VERSION 2.4.5)

#path where to build libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY .build/ipelets)

find_package(CGAL QUIET COMPONENTS Core )


if ( CGAL_FOUND )
  include( ${CGAL_USE_FILE} )
  find_package(IPE)
  if ( IPE_FOUND )
    include_directories(../../include)
    include_directories(include/CGAL_ipelets)
    include_directories(${IPE_INCLUDE_DIR})
    link_directories( ${IPE_LIBRARY_DIR} )

    set(CGAL_IPELETS ${CGAL_IPELETS})
    set(CGAL_IPELETS ${CGAL_IPELETS} hilbert_sort)
    set(CGAL_IPELETS ${CGAL_IPELETS} arrangement)
    set(CGAL_IPELETS ${CGAL_IPELETS} diagrams)
    set(CGAL_IPELETS ${CGAL_IPELETS} alpha_shapes)
    set(CGAL_IPELETS ${CGAL_IPELETS} hull)
    set(CGAL_IPELETS ${CGAL_IPELETS} multi_delaunay)
    set(CGAL_IPELETS ${CGAL_IPELETS} multi_regular)
    set(CGAL_IPELETS ${CGAL_IPELETS} triangulation)
    set(CGAL_IPELETS ${CGAL_IPELETS} mesh_2)
    set(CGAL_IPELETS ${CGAL_IPELETS} generator)
    set(CGAL_IPELETS ${CGAL_IPELETS} partition)
    set(CGAL_IPELETS ${CGAL_IPELETS} minkowski)
    set(CGAL_IPELETS ${CGAL_IPELETS} pca)
    set(CGAL_IPELETS ${CGAL_IPELETS} bbox_restriction)
    set(CGAL_IPELETS ${CGAL_IPELETS} skeleton)


    foreach(IPELET ${CGAL_IPELETS})
      add_library(CGAL_${IPELET} MODULE ${IPELET}.cpp)
      add_to_cached_list(CGAL_EXECUTABLE_TARGETS CGAL_${IPELET})
      target_link_libraries( CGAL_${IPELET} ipe)
      if ( IPELET_INSTALL_DIR )
        install(TARGETS CGAL_${IPELET} DESTINATION ${IPELET_INSTALL_DIR})
      endif ()
    endforeach(IPELET)
    #example in doc not installed
    add_library(simple_triangulation MODULE simple_triangulation.cpp)
    target_link_libraries( simple_triangulation ipe )
    
  else()
    message(STATUS "NOTICE: This program requires the Ipe include files and library, and will not be compiled.")
  endif()
else()

    message(STATUS "NOTICE: This program requires the CGAL library, and will not be compiled.")
    
endif()
