#ifndef ALGORITHM_HPP_INCLUDED_1765069066130440670
#define ALGORITHM_HPP_INCLUDED_1765069066130440670 1

namespace Iterator::Core
{

  /** Apply the given function object f to every iterator in the range [first, last), in order
   *
   * @details This function differs from the function std::for_each in that the function is
   * applied to the iterators without dereferencing
   *
   * @param first, last - the range to apply the function to
   * @param f - the function object
   */
  template< typename Iter, typename Function >
  Function
  for_each_iter( Iter first, Iter last, Function f ){
    while( first != last ){
      f( first );
      ++first;
    }
    return f;    
  } // end of function for_each_iter


  /**  Apply the given function to iterators over a range and stores the result in another range
   *
   * @details This function differs from the function std::transform in that the function is
   * applied to the iterators without dereferencing.
   *
   * @param first_in, last_in - the first range of elements to transform
   * @param first_out - the begining of the output range
   * @param f - unary operation function object that will be applied.
   */
  template< typename InputIter, typename OutputIter, typename Function >
  OutputIter
  transform_iter( InputIter first_in, InputIter last_in, OutputIter first_out, Function f ){
    while( first_in != last_in ){
      *first_out = f( first_in );
      ++first_in;
      ++first_out;
    }
    return first_out;
  }


  
} // end of namespace Iterator::Core

#endif // !defined ALGORITHM_HPP_INCLUDED_1765069066130440670
