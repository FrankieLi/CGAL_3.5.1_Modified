# This is the CMake script for compiling a CGAL application.

project( Arrangement_2 ) 

CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)

if ( COMMAND cmake_policy )
  cmake_policy( SET CMP0003 NEW )  
endif()

find_package(CGAL COMPONENTS Qt3 Core )

include( ${CGAL_USE_FILE} )

find_package(Qt3-patched)
# FindQt3-patched.cmake is FindQt3.cmake patched by CGAL developers, so
# that it can be used together with FindQt4: all its variables are prefixed
# by "QT3_" instead of "QT_".

if ( CGAL_FOUND AND CGAL_Qt3_FOUND AND QT3_FOUND )

  # use the Qt MOC preprocessor on classes that derives from QObject
  include( Qt3Macros-patched )
  qt3_generate_moc( "${CMAKE_CURRENT_SOURCE_DIR}/arrangement_2.h" arrangement_2.moc )
  qt3_generate_moc( "${CMAKE_CURRENT_SOURCE_DIR}/forms.h" forms.moc )


  # The executable itself.
  add_executable  ( arrangement_2 
                    arrangement_2.cpp arrangement_2.moc
		    forms.cpp forms.moc
		    demo_tab.cpp
		    MyWindow_files.cpp
		    MyWindow_operations.cpp
		    MyWindow_overlay.cpp
		    qt_layer.cpp
		    )

  add_to_cached_list( CGAL_EXECUTABLE_TARGETS arrangement_2 )

  target_link_libraries( arrangement_2 ${CGAL_LIBRARIES}  ${CGAL_3RD_PARTY_LIBRARIES})

else()

  message(STATUS "NOTICE: This demo requires CGAL and Qt3, and will not be compiled.")

endif()
