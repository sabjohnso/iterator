configure_file( config.hpp.in config.hpp )

install( FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  algorithm.hpp
  autoref.hpp
  gslice.hpp
  import.hpp
  iterator.hpp
  iterable.hpp
  generic.hpp
  indexed.hpp
  range.hpp
  slice.hpp
  DESTINATION ${ITERATOR_INSTALL_INCLUDE_DIR}/iterator )

configure_file( iterator-config.cmake.in iterator-config.cmake)
install( FILES
  ${CMAKE_CURRENT_BINARY_DIR}/iterator-config.cmake
  DESTINATION ${ITERATOR_INSTALL_LIBRARY_DIR} )
