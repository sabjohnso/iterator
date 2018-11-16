//
// ... Standard header files
//
#include <vector>
#include <iterator>


//
// ... Testing header files
//
#include <gtest/gtest.h>


//
// ... Iterator header files
//
#include <iterator/algorithm.hpp>



namespace Iterator::Testing
{
  namespace // anonymous
  {
    using std::vector;
    using std::for_each;
    using std::distance;

    using Core::for_each_iter;
    
  } // end of anonymous namespace

  TEST(for_each_iter, vector )
  {
    constexpr ssize_t n = 10;
    vector<ssize_t> xs( n );

    for_each( begin( xs ), end( xs ),
	      [index = ssize_t( 0 )]( auto& x ) mutable {
		x = index;
		++index;});

    auto first = begin( xs );
    auto last = end( xs );
      
    for_each_iter(
      first, last,
      [=, index = 0 ](auto it ) mutable {
	EXPECT_EQ( distance( first, it ), index );
	EXPECT_EQ( *it, index );
	++index;
      });
      
		   
  } // end of test for_each_iter.vector 
} // end of namespace Iterator::Testing
