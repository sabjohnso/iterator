#ifndef GENERIC_HPP_INCLUDED_814022529675511241
#define GENERIC_HPP_INCLUDED_814022529675511241 1

//
// ... Iterator header files
//
#include <iterator/import.hpp>
#include <iterator/iterable.hpp>


namespace Iterator::Core
{
  
  /** A Generic iterator 
   * 
   * @details This class implements a generic iterator
   * based on the iteration methods/protocol used in the Julia
   * language. This iterator relies on the definition of four
   * overoaded functions for the type being iterated over:
   *  - start     - return an initial state for iteration
   *  - next      - return the next iterator state
   *  - done      - return true if iteration is complete, otherwise false
   *  - get_value - return the value associate with the current iteraion state
   */
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

    /** Dereference the iterator 
     */
    value_type
    operator*() const & { return get_value( ref, state ); }

    Generic_iterator&
    operator++()
    {
      state = next( ref, state );
      return *this;
    }

    Generic_iterator
    operator++( int )
    {
      Generic_iterator result = *this;
      state = next( ref, state );
      return result;
    }
    
  private:

    container_reference ref;
    state_type state;
      
  }; // end of class Generic_iterator

  
  /** A CRTP base class for deriving iteration based on generic iterators*/
  template< typename T >
  class Generic_iterable
    : public CRTP<Generic_iterable,T>
  {
  public:
    using subtype = T;
    using subtype_reference = subtype&;
    using subtype_const_reference = const subtype&;

    using iterator = Generic_iterator<subtype>;
    
    auto
    begin() & { return Generic_iterator<T>( static_cast<subtype_reference>(*this));}

    auto
    end() & { return Generic_iterator<T>(); }
    
  };
  
} // end of namespace Iterator::Core

#endif // !defined GENERIC_HPP_INCLUDED_814022529675511241
