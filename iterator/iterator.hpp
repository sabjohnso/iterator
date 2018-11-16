#ifndef ITERATOR_HPP_INCLUDED_2074655416702505672
#define ITERATOR_HPP_INCLUDED_2074655416702505672 1


//
// ... Iterator header files
//
#include <iterator/autoref.hpp>
#include <iterator/range.hpp>
#include <iterator/iterable.hpp>
#include <iterator/algorithm.hpp>


namespace Iterator
{

  using Core::autoref;
  using Core::range;

  using Core::Indexed_iterator;
  using Core::Indexed_iterable;


  using Core::for_each_iter;
  using Core::transform_iter;

} // end of namespace Iterator

#endif // !defined ITERATOR_HPP_INCLUDED_2074655416702505672
