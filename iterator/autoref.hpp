#ifndef AUTOREF_HPP_INCLUDED_2212751100788832416
#define AUTOREF_HPP_INCLUDED_2212751100788832416 1

//
// ... Iterator header files
//
#include <iterator/import.hpp>


namespace Iterator
{
  namespace Core
  {

    template< typename T >
    class Auto_ref
    {
    public:
      
      using value_type = T;
      using reference = value_type&;
      using const_reference = const value_type&;
      using rvalue_reference = value_type&&;

      template< typename U >
      Auto_ref( U&& input ) : value( forward<U>( input ))
      {}

      
      Auto_ref&
      operator +=( value_type offset ) & {
	value += offset;
	return *this;
      }
      

      Auto_ref&
      operator -=( value_type arg ) & { return operator+=( -arg ); }
      
      
      Auto_ref&
      operator ++() &  { return operator+=( 1 ); }

      
      Auto_ref
      operator ++(int) & {
	Auto_ref result = *this;
	operator+=( 1 );
	return result;
      }
      
      Auto_ref&
      operator --() & {
	return operator+=( -1 );
      }

      Auto_ref
      operator --(int) & {
	Auto_ref result = *this;
	operator+=( -1 );
	return result;
      }

      
      Auto_ref
      operator []( value_type offset ){
	Auto_ref result = *this;
	result += offset;
	return result;
      }

      constexpr
      operator const_reference () const & { return value; }

      constexpr
      operator rvalue_reference () && { return move( value ); }

      constexpr
      operator reference  () & { return value;  }

      constexpr const Auto_ref&
      operator *() const & { return *this; }


      constexpr Auto_ref&&
      operator *() && { return *this; }

      Auto_ref&
      operator *() & { return *this; }

      constexpr const Auto_ref&
      operator &() const & { return *this; }

      constexpr Auto_ref&&
      operator &() && { return *this; }

      
      Auto_ref&
      operator &() & { return *this; }

      
    private:

      value_type value;
      
    }; // end of class Auto_ref


    template< typename T >
    constexpr auto
    autoref( T&& x ){
      return Auto_ref<decay_t<T>>( x );
    }

    
  } // end of namespace Core  
} // end of namespace Iterator



namespace std
{

  template< typename T >
  struct iterator_traits<Iterator::Core::Auto_ref<T>> {
    using value_type = typename Iterator::Core::Auto_ref<T>::value_type;
    using difference_type = make_signed_t<T>;    
    using iterator_category = random_access_iterator_tag;
  }; // end of struct iterator_traits
  

  template< typename T, typename S = make_signed_t<T> >
  constexpr S
  distance( Iterator::Core::Auto_ref<T> first, Iterator::Core::Auto_ref<T> last ){
    return S(last)-S(first);
  }


  
} // end of namespace std


#endif // !defined AUTOREF_HPP_INCLUDED_2212751100788832416
