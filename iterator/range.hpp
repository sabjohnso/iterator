#ifndef RANGE_HPP_INCLUDED_65688567649014361
#define RANGE_HPP_INCLUDED_65688567649014361 1

//
// ... Iterator header files>
//
#include <iterator/import.hpp>
#include <iterator/autoref.hpp>


namespace Iterator
{
  namespace Core
  {

    template< typename T >
    class Range : pair<T,T>
    {
    public:

      using value_type = T;
      using iterator = Auto_ref<value_type>;
      
      using base = pair<value_type,value_type>;
      using base::base;

      constexpr iterator
      begin() const & { return iterator( base::first ); }

      constexpr iterator
      end() const & { return iterator( base::second ); }

      constexpr size_t
      size(){ return distance( begin(), end()); }
      
    }; // end of class range


    constexpr auto
    range( size_t n ){
      return Range<size_t>( 0, n );
    }

    constexpr auto
    range( size_t m, size_t n ){
      return Range<size_t>( m, n );
    }

  } // end of namespace Core
} // end of namespace Iterator




#endif // !defined RANGE_HPP_INCLUDED_65688567649014361
