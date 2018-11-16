#ifndef ALGORITHM_HPP_INCLUDED_1765069066130440670
#define ALGORITHM_HPP_INCLUDED_1765069066130440670 1

namespace Iterator::Core
{

  template< typename Iter, typename F >
  F
  for_each_iter( Iter first, Iter last, F f ){
    while( first != last )
    {
      f( first );
      ++first;
    }
  } // end of function for_each_iter
} // end of namespace Iterator::Core

#endif // !defined ALGORITHM_HPP_INCLUDED_1765069066130440670
