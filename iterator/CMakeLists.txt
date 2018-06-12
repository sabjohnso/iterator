configure_file( config.hpp.in config.hpp )

install( FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  iterator.hpp
  DESTINATION ${ITERATOR_INSTALL_INCLUDE_DIR} )
