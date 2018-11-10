//
// ... Standard header files
//
#include <vector>
#include <utility>
#include <type_traits>
#include <algorithm>
#include <iostream>

//
// ... Affix header files
//
#include <affix/affix.hpp>

//
// ... Iterator header files
//
#include <iterator/iterable.hpp>
#include <iterator/generic.hpp>

//
// ... Testing header files
//
#include <iterator_testing/test_macros.hpp>

using namespace Iterator::Core;
using std::decay_t;


template< typename F, typename T >
struct Iterate
  : pair<F,T>
  , public Generic_iterable<Iterate<F,T>>
{
public:
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using function_type = F;
    
  using base = pair<function_type,value_type>;
  using base::base;

  using state_type = Iterate;

  Iterate&
  operator=( const Iterate& input ){
    base::second = input.get();
    return *this;
  }

  constexpr const_reference
  get( ) const & { return base::second; }


  reference
  get( ) & { return base::second; }

  

  constexpr Iterate
  operator ()() const & { 
    return Iterate( base::first, base::first( base::second ));
  }


  friend decltype(auto)
  start( Iterate& xs ){
    return xs;
  }

  friend auto
  get_value( Iterate&, Iterate& state ){
    return state.get();
  }
  friend auto
  get_value( const Iterate&, const Iterate& state ){
    return state.get();
  }

  friend auto
  next( Iterate&, Iterate& state ){
    return state();
  }

  friend bool
  done( const Iterate& ){
    return false;
  }

  
private:
    
};

namespace std
{
  template< typename F, typename T >
  struct iterator_traits<Generic_iterator<Iterate<F,T>>>
  {
    using type =  Iterate<F,T> ;
    using value_type = typename type::value_type;
    using iterator_category = input_iterator_tag;
  };
} // end of namespace std

template< typename F, typename T >
constexpr auto
iterate( F&& f, T&& x ){
  return Iterate<decay_t<F>,decay_t<T>>( forward<F>( f ), forward<T>( x ));

}


constexpr auto add1 = []( auto x ){ return x+1; };

/** Test the Iterable type ane Generic_iterator type 
 */

struct Iterable_test
{
  Iterable_test() : accum( 0 ) {
    using std::cout;
    using std::endl;
    using std::copy;
    using affix::affix_iterator;
    
    auto ys = iterate( add1, 0 );
    copy_n( begin( ys ), 10, affix_iterator<int>( cout, "[", " ", "]" ));
    
  }
  operator int() const { return accum; }
private:
  int accum;
}; // end of struct Iterable_test

int
main( int, char** )
{
  int accum = 0;
  accum += Iterable_test();

  return accum;
}
