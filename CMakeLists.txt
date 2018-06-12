#
# ... Build script for iterator
#

cmake_minimum_required( VERSION 3.7 )

project( ITERATOR )
set( ITERATOR_MAJOR 0)
set( ITERATOR_MINOR 1)
set( ITERATOR_UPDATE 0)
set( ITERATOR_VERSION iterator-${ITERATOR_MAJOR}.${ITERATOR_MINOR} )
set( ITERATOR_VERSION_UPDATE ${ITERATOR_VERSION}.${ITERATOR_UPDATE} )

option( BUILD_ITERATOR_TESTING  "Build the iterator  tests" ON )
option( BUILD_ITERATOR_DOCUMENTATION "Build the iterator documentation" ON )

include_directories( 
  ${ITERATOR_SOURCE_DIR}
  ${ITERATOR_BINARY_DIR} )

if( NOT ITERATOR_INSTALL_INCLUDE_DIR)
  set( ITERATOR_INSTALL_INCLUDE_DIR include/iterator
    CACHE PATH "Path for installation of header files" )
endif( NOT ITERATOR_INSTALL_INCLUDE_DIR)

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

  if( NOT ITERATOR_INSTALL_DOC_DIR)
    set( ITERATOR_INSTALL_DOC_DIR share/doc/${ITERATOR_VERSION}
      CACHE PATH "Path for installation of documentation files" )
  endif( NOT ITERATOR_INSTALL_DOC_DIR)

  if( NOT ITERATOR_INTALL_MAN_DIR)
    set( ITERATOR_INTALL_MAN_DIR include/iterator
      CACHE PATH "Path for installation of man files" )
  endif( NOT ITERATOR_INTALL_MAN_DIR)

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
