configure_file( config.hpp.in config.hpp )

install( FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  autoref.hpp
  gslice.hpp
  import.hpp
  iterator.hpp
  iterable.hpp
  range.hpp
  slice.hpp
  DESTINATION ${ITERATOR_INSTALL_INCLUDE_DIR} )
