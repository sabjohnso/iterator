#ifndef ITERABLE_HPP_INCLUDED_2168123778018600310
#define ITERABLE_HPP_INCLUDED_2168123778018600310 1

//
// ... Iterator header files
//
#include <iterator/import.hpp>


namespace Iterator::Core
{



    /** A CRTP base class for iterable types
     *  
     * @brief This class facilitates the derivation of iterator
     * producing member functions.
     */
    template< typename T >
    class Iterable : public CRTP<Iterable,T>
    {

    public:
      
      using subtype = T;
      using subtype_reference = subtype&;
      using subtype_const_reference = const subtype&;

    private:

            template< typename U >
      static typename U::iterator
      begin_( U& container ){ return typename U::iterator(container, 0); }

      template< typename U >
      static typename U::iterator
      end_( U& container ){ return typename U::iterator(container, container.size()); }

      template< typename U >
      static typename U::const_iterator
      begin_( const U& container ){ return typename U::const_iterator(container, 0); }

      template< typename U >
      static typename U::const_iterator
      end_( const U& container ){ return typename U::const_iterator(container, container.size()); }

      template< typename U >
      static typename U::reverse_iterator
      rbegin_( U& container )
      {
	return typename U::reverse_iterator( container, ssize_type( container.size()) - 1);
      }

      template< typename U >
      static typename U::reverse_iterator
      rend_( U& container ){ return typename U::reverse_iterator( container, -1 ); }

      template< typename U >
      static typename U::const_reverse_iterator
      rbegin_( const U& container )
      {
	return typename U::const_reverse_iterator( container, ssize_type( container.size()) - 1);
      }

      template< typename U >
      static typename U::const_reverse_iterator
      rend_( const U& container ){ return typename U::const_reverse_iterator( container, -1 ); }

    protected:
      
       Iterable() = default;
      ~Iterable() = default;

    public:
      
      auto
      begin() & { return begin_( static_cast<subtype_reference>( *this )); }

      auto
      end() & { return end_( static_cast<subtype_reference>( *this )); }

      auto
      begin() const & { return begin_( static_cast<subtype_const_reference>( *this )); }

      auto
      end() const & { return end_( static_cast<subtype_const_reference>( *this )); }

      auto
      cbegin() const & { return begin_( static_cast<subtype_const_reference>( *this )); }

      auto
      cend() const & { return end_( static_cast<subtype_const_reference>( *this )); }
      
      auto
      rbegin() & { return rbegin_( static_cast<subtype_reference>( *this )); }

      auto
      rend() & { return rend_( static_cast<subtype_reference>( *this )); }

      auto
      rbegin() const & { return rbegin_( static_cast<subtype_const_reference>( *this )); }

      auto
      rend() const & { return rend_( static_cast<subtype_const_reference>( *this )); }

      auto
      crbegin() const & { return rbegin_( static_cast<subtype_const_reference>( *this )); }

      auto
      crend() const & { return rend_( static_cast<subtype_const_reference>( *this )); }

    }; // end of class Iterable

    

} // end of namespace Iterator::Core


#endif // !defined ITERABLE_HPP_INCLUDED_2168123778018600310
