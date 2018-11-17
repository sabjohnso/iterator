//
// ... Standard header files
//
#include <algorithm>
#include <iterator>

//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... Iterator header files
//
#include <iterator/indexed.hpp>


namespace Iterator::Testing
{
  namespace // anonymous
  {
    using std::for_each;
    using std::distance;
    using Core::Indexed_iterable;

    
    template< typename T >
    class Vector : public Indexed_iterable<Vector<T>>
    {
    public:

      using base = Indexed_iterable<Vector<T>>;

      using value_type = T;
      using reference = value_type&;
      using const_reference = const value_type&;
      using pointer_type = value_type*;

      using iterator = typename base::iterator;
      using const_iterator = typename base::const_iterator;
      using reverse_iterator = typename base::reverse_iterator;
      using reverse_const_iterator = typename base::reverse_const_iterator;
      

      friend iterator
      begin( Vector& xs ){ return xs.begin(); }

      friend iterator
      end( Vector& xs ){ return xs.end(); }

      friend const_iterator
      begin( const Vector& xs ){ return xs.begin(); }

      friend const_iterator
      end( const Vector& xs ){ return xs.end(); }
     
      using size_type = ssize_t;
      
      Vector( ssize_t element_count )
	: n( element_count )
      {
	ptr = new value_type[ n ];
      }

      reference
      operator []( ssize_t index ){
	return ptr[ index ];
      }

      const_reference
      operator []( ssize_t index ) const {
	return ptr[ index ];
      }

      ssize_t
      size() const { return n; }

      ~Vector(){ delete [] ptr; }

    private:
      
      ssize_t n;
      pointer_type ptr;
      
    }; // end of class Vector
  } // end of anonymous namespace

  TEST( indexed, vector )
  {
    constexpr ssize_t n = 10;
    Vector<int> xs(n);
    EXPECT_EQ( xs.size(), n );
    EXPECT_EQ( distance( xs.begin(), xs.end()), n );
    EXPECT_EQ( distance( begin( xs ), end( xs )), n );

    { // local scope for index
      ssize_t index = 0;
      for(auto& x : xs ){
	x = index;
	++index;
      }
    }

    for_each(
      begin( xs ), end( xs ),
      [index = 0]( auto x ) mutable {
	EXPECT_EQ( x, index );
	++index;
      });
	      

  } // end of class


  
  
} // end of namespace Iterator::Testing
