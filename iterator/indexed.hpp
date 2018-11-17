#ifndef INDEXED_HPP_INCLUDED_235808412974576736
#define INDEXED_HPP_INCLUDED_235808412974576736 1

//
// ... Iterator header files
//
#include <iterator/import.hpp>
#include <iterator/iterable.hpp>

namespace Iterator::Core
{
  /** An enumeration class used to indicate direction of iteration. */
  enum class Direction{ FORWARD = 1, REVERSE = -1 };

  /** An enumeration class used to indicate the constness of an iterator. */
  enum class Access{ READONLY, WRITABLE };
  
  /** An iterator class for containers using an index for access
   *
   * @details This class defines an iterator that stores an index and
   * and a reference to a container that allowes element access through
   * the array access operator.
   *
   */
  template<
    typename Container,
    Access Constness = Access::WRITABLE,
    Direction direction = Direction::FORWARD
    >
  class Indexed_iterator : public Comparable<Indexed_iterator<Container,Constness,direction>>
  {
  public:

    static constexpr Access  constness = Constness;
    
    using container_type = Container;
    using container_reference =
      conditional_t<constness == Access::READONLY, 
		    add_lvalue_reference_t<add_const_t<container_type>>,
		    add_lvalue_reference_t<container_type>>;

    using value_type = typename Container::value_type;
    using reference =
      conditional_t<constness == Access::READONLY,
		    add_lvalue_reference_t<add_const_t<value_type>>,
		    add_lvalue_reference_t<value_type>>;
    
    using size_type  = typename Container::size_type;
    using ssize_type = make_signed_t<size_type>;

      
    static constexpr size_type rank = container_type::rank;
    
    friend container_type;

    static_assert(
      (constness == Access::READONLY && is_const<remove_reference_t<container_reference>>::value) ||
      ((!(constness == Access::READONLY)) && !(is_const<remove_reference_t<container_reference>>::value)),
      "Expected agreement about constness" );

    Indexed_iterator() = default;


    /** Construct an iterator from a container reference an an initial index 
     */
    Indexed_iterator( container_reference input_ref, size_type input_index )
      : ref_( input_ref )
      , index_element_( input_index )
    {}

    /** Offset the element index */
    Indexed_iterator&
    operator += ( ssize_type offset ) &
    {
      index_element_ += offset * ssize_type( direction );
      return *this;
    }

    /** Offset the element index */
    Indexed_iterator&
    operator -=( ssize_type offset ) &
    {
      return *this += -offset;
    }

    /** Increment index */
    Indexed_iterator&
    operator ++() &
    {
      return *this += 1;
    }

    /** Increment index */
    Indexed_iterator
    operator ++( int ) &
    {
      Indexed_iterator result( *this );
      ++(*this);
      return result;
    }

    /** Decrement index */
    Indexed_iterator&
    operator --() &
    {
      return *this += -1;
    }


    /** Decrement index */
    Indexed_iterator
    operator --( int )&
    {
      Indexed_iterator result( *this );
      --(*this);
      return result;
    }


    /** Current element index */
    ssize_type
    element_index() const &
    {
      return index_element_;
    }
    

    /** Dereference the value with a relive offset
     */
    reference
    operator []( ssize_type offset ) &
    {
      return ref_[ index_element_ + offset ];
    }


    /** Compare less than
     *
     * @details This friend < operator provides the necessary 
     * functionality for deriving the remaining comparison operators
     * from the Comparable super-type.
     */
    friend bool
    operator <( Indexed_iterator a, Indexed_iterator b )
    {
      return a.index_element_ < b.index_element_;
    }

    /**  Dereference the value at the current position
     */
    reference
    operator*() &  { return ref_[ index_element_ ]; }

    ssize_type
    distance( Indexed_iterator it )
    {
      return it.index_element_ - index_element_;
    }



    
  private:

    /** Reference to the container */
    container_reference ref_;

    /** Element index */
    ssize_type index_element_;

  }; // end of class Iterator;

  /** */
  template< typename T >
  class Indexed_iterable
    : public CRTP<Indexed_iterable, T>
    , public Iterable<T>
  {
  public:
    using iterator = Indexed_iterator<T,Access::WRITABLE,Direction::FORWARD>;
    using const_iterator = Indexed_iterator<T,Access::READONLY,Direction::FORWARD>;
    using reverse_iterator = Indexed_iterator<T,Access::WRITABLE,Direction::REVERSE>;
    using reverse_const_iterator = Indexed_iterator<T,Access::READONLY,Direction::REVERSE>;
  protected:
    Indexed_iterable() = default;
    ~Indexed_iterable() = default;
  };


} // end of namespace Iterator::Core

namespace std
{
  template< typename C, Iterator::Core::Access A, Iterator::Core::Direction D >
  auto
  distance( Iterator::Core::Indexed_iterator<C,A,D> first,
	    Iterator::Core::Indexed_iterator<C,A,D> last )
  {
    return first.distance( last );
  }
  
} // end of namespace std


#endif // !defined INDEXED_HPP_INCLUDED_235808412974576736
