//
// ... Standard header files
//
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>


//
// ... affix header files
//
#include <affix/affix.hpp>


//
// ... Iterator header files
//
#include <iterator/range.hpp>


//
// ... Testing header files
//
#include <iterator_testing/test_macros.hpp>



/** Test the Range class  */
struct Range_test
{
  
  Range_test() : accum( 0 ) {
    constructor_test();
    
    using namespace Iterator::Core;
    using std::cout;
    using std::transform;
    using std::copy;
    using std::vector;
    using std::back_inserter;
    using affix::affix_iterator;

    auto xs = Range<int>( 0, 10 );
    vector<int> ys;
    transform( begin( xs ), end( xs ), back_inserter( ys ),
	       []( auto x ){ return x*x; });

    int n = ys.size();
    ITERATOR_TEST( accum, n == 10 );
    for( int i = 0; i < n; ++i ){
      ITERATOR_TEST( accum, ys[ i ] == i*i );
    }
  }
  operator int() const { return accum; }
private:
  void
  constructor_test(){
    using namespace Iterator::Core;
    range( 10 );
  }
  int accum;
}; // end of struct Range_test

int
main( int, char** )
{
  int accum = 0;
  accum += Range_test();
  return accum;
}
