#ifndef ITERABLE_HPP_INCLUDED_2168123778018600310
#define ITERABLE_HPP_INCLUDED_2168123778018600310 1

//
// ... Iterator header files
//
#include <iterator/import.hpp>


namespace Iterator
{
  namespace Core
  {


    /** */
    template< typename Container >
    class Generic_iterator
    {
    public:
      using container_type = Container;
      using container_reference = container_type&;
      using state_type = typename container_type::state_type;

      using value_type = typename container_type::value_type;
      using reference = value_type&;
      using const_reference = const value_type&;

      Generic_iterator( Container& input )
	: ref( input )
	, state( start( ref ))
      {}
	
      value_type
      operator*() const &{ return get_value( ref, state ); }

      Generic_iterator&
      operator++(){
	state = next( ref, state );
	return *this;
      }



      Generic_iterator
      operator++( int ){
	Generic_iterator result = *this;
	state = next( ref, state );
	return result;
      }
      

    private:
      container_reference ref;
      state_type state;
      
    }; // end of class Generic_iterator







    
    /** 
     * @brief A CRTP base class for iterable types
     */
    template< typename T >
    class Iterable : public CRTP<Iterable,T>
    {
      friend auto
      begin( Iterable& xs ){ return Generic_iterator<T>( xs ); }

      friend auto
      end( Iterable& xs ){ return Generic_iterator<T>( xs ); }
      
    }; // end of class Iterable


    
    
  } // end of namespace Core
} // end of namespace Iterator

#endif // !defined ITERABLE_HPP_INCLUDED_2168123778018600310
