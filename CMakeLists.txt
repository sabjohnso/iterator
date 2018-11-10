#
# ... Build script for iterator
#

cmake_minimum_required( VERSION 3.7 )

project( ITERATOR )

#
# ... Version information
#
set( ITERATOR_MAJOR 0)
set( ITERATOR_MINOR 1)
set( ITERATOR_UPDATE 0)

set( ITERATOR_SUFFIX ${ITERATOR_MAJOR}.${ITERATOR_MINOR} )

set( ITERATOR_VERSION iterator-${ITERATOR_SUFFIX} )
set( ITERATOR_VERSION_UPDATE ${ITERATOR_VERSION}.${ITERATOR_UPDATE} )


#
# ... Build options
# 
option( BUILD_ITERATOR_TESTING  "Build the iterator tests" ON )
option( BUILD_ITERATOR_DOCUMENTATION "Build the iterator documentation" ON )
option( ITERATOR_INSTALL_VERSIONED "Make a version specific installation" ON )

#
# ... Dependencies
#
find_package( type_utility REQUIRED )
find_package( operators REQUIRED )


#
# ... Installation path info
#
set( ITERATOR_INSTALL_INCLUDE_DIR include
  CACHE PATH "Path for installation of header files" )

set( ITERATOR_INSTALL_LIBRARY_DIR lib/iterator
  CACHE PATH "Path for installation of header files" )


if( ITERATOR_INSTALL_VERSIONED )
  string( APPEND ITERATOR_INSTALL_INCLUDE_DIR /iterator${ITERATOR_SUFFIX})
  string( APPEND ITERATOR_INSTALL_LIBRARY_DIR ${ITERATOR_SUFFIX})
endif()

#
# ... Header library target
#
add_library( iterator INTERFACE )
target_link_libraries( iterator INTERFACE type_utility operators )


target_include_directories( iterator
  INTERFACE $<INSTALL_INTERFACE:${ITERATOR_INSTALL_INCLUDE_DIR}> )

target_include_directories( iterator
  INTERFACE $<BUILD_INTERFACE:${ITERATOR_SOURCE_DIR}>)

target_include_directories( iterator
  INTERFACE $<BUILD_INTERFACE:${ITERATOR_BINARY_DIR}> )


install( TARGETS iterator EXPORT iterator
  DESTINATION ${ITERATOR_INSTALL_LIBRARY_DIR})

install( EXPORT iterator
  DESTINATION ${ITERATOR_INSTALL_LIBRARY_DIR}
  FILE iterator.cmake )
  


add_subdirectory( iterator )



#
# ... Testing #
if( BUILD_ITERATOR_TESTING )
  enable_testing()
  add_subdirectory( iterator_testing )
endif( BUILD_ITERATOR_TESTING )



#
# ... Documentation
#
if( BUILD_ITERATOR_DOCUMENTATION )

  configure_file( Doxyfile.in Doxyfile )

  set( ITERATOR_INSTALL_DOC_DIR share/doc/${ITERATOR_VERSION}
    CACHE PATH "Path for installation of documentation files" )

  set( ITERATOR_INTALL_MAN_DIR include/iterator
    CACHE PATH "Path for installation of man files" )


  find_package( Doxygen REQUIRED )

  add_custom_command(
    OUTPUT ${ITERATOR_BINARY_DIR}/doxygen.log
    COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile > doxygen.log
    MAIN_DEPENDENCY Doxyfile
    DEPENDS ${ITERATOR_BINARY_DIR}/iterator
    WORKING_DIRECTORY ${${ITERATOR_BINARY_DIR}} )

  add_custom_target(
    iterator_documentation ALL
    DEPENDS ${ITERATOR_BINARY_DIR}/doxygen.log )

  install( DIRECTORY ${ITERATOR_BINARY_DIR}/doc/html DESTINATION ${ITERATOR_INSTALL_DOC_DIR} )
  install( DIRECTORY ${ITERATOR_BINARY_DIR}/doc/man DESTINATION ${ITERATOR_INTALL_MAN_DIR} )
endif( BUILD_ITERATOR_DOCUMENTATION )

# end of build definition for iterator
