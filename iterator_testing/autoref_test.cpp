//
// ... iterator header files
//
#include <iterator/autoref.hpp>


//
// ... Testing header files
//
#include <iterator_testing/test_macros.hpp>


/** Test the Auto_ref class */
struct Auto_ref_test
{
  Auto_ref_test() : accum( 0 ) {
    comparison_test();
    offset_test();
  }

   

  void
  comparison_test(){

     using Iterator::Core::Auto_ref;
     
    ITERATOR_TEST( accum, 3 == Auto_ref<int>( 3 ) );
    ITERATOR_TEST( accum, !(4 == Auto_ref<int>( 3 )));
    ITERATOR_TEST( accum, Auto_ref<int>( 3 ) == 3 );
    ITERATOR_TEST( accum, !(Auto_ref<int>( 3 ) == 4 ));
    
    ITERATOR_TEST( accum, !(3 != Auto_ref<int>( 3 )));
    ITERATOR_TEST( accum, 4 != Auto_ref<int>( 3 ));
    ITERATOR_TEST( accum, !( Auto_ref<int>( 3 ) != 3 ));
    ITERATOR_TEST( accum, Auto_ref<int>( 3 ) != 4 );

    
    ITERATOR_TEST( accum, Auto_ref<int>( 3 ) == Auto_ref<int>( 3 ));
    ITERATOR_TEST( accum, !(Auto_ref<int>( 3 ) == Auto_ref<int>( 4 )));
    ITERATOR_TEST( accum, Auto_ref<int>( 3 ) != Auto_ref<int>( 4 ));
    ITERATOR_TEST( accum, !(Auto_ref<int>( 3 ) != Auto_ref<int>( 3 )));


    ITERATOR_TEST( accum, Auto_ref<int>( 3 ) < Auto_ref<int>( 4 ));
    ITERATOR_TEST( accum, Auto_ref<int>( 3 ) <= Auto_ref<int>( 4 ));
    ITERATOR_TEST( accum, !( Auto_ref<int>( 3 ) >= Auto_ref<int>( 4 )));
    ITERATOR_TEST( accum, !( Auto_ref<int>( 3 ) > Auto_ref<int>( 4 )));

    ITERATOR_TEST( accum, Auto_ref<int>( 3 ) < 4 );
    ITERATOR_TEST( accum, Auto_ref<int>( 3 ) <= 4 );
    ITERATOR_TEST( accum, !( Auto_ref<int>( 3 ) >= 4 ));
    ITERATOR_TEST( accum, !( Auto_ref<int>( 3 ) > 4 ));

    ITERATOR_TEST( accum, 3 < Auto_ref<int>( 4 ));
    ITERATOR_TEST( accum, 3 <= Auto_ref<int>( 4 ));
    ITERATOR_TEST( accum, !( 3 >= Auto_ref<int>( 4 )));
    ITERATOR_TEST( accum, !( 3 > Auto_ref<int>( 4 )));



    ITERATOR_TEST( accum, !( Auto_ref<int>( 5 ) < Auto_ref<int>( 4 )));
    ITERATOR_TEST( accum, !( Auto_ref<int>( 5 ) <= Auto_ref<int>( 4 )));
    ITERATOR_TEST( accum, Auto_ref<int>( 5 ) >= Auto_ref<int>( 4 ));
    ITERATOR_TEST( accum, Auto_ref<int>( 5 ) > Auto_ref<int>( 4 ));

    ITERATOR_TEST( accum, !( Auto_ref<int>( 5 ) < 4 ));
    ITERATOR_TEST( accum, !( Auto_ref<int>( 5 ) <= 4 ));
    ITERATOR_TEST( accum, Auto_ref<int>( 5 ) >= 4 );
    ITERATOR_TEST( accum, Auto_ref<int>( 5 ) > 4 );

    ITERATOR_TEST( accum, !( 5  < Auto_ref<int>( 4 )));
    ITERATOR_TEST( accum, !( 5  <= Auto_ref<int>( 4 )));
    ITERATOR_TEST( accum, 5 >= Auto_ref<int>( 4 ));
    ITERATOR_TEST( accum, 5 > Auto_ref<int>( 4 ));


    
    ITERATOR_TEST( accum, !( Auto_ref<int>( 5 ) < Auto_ref<int>( 5 )));
    ITERATOR_TEST( accum, Auto_ref<int>( 5 ) <= Auto_ref<int>( 5 ));
    ITERATOR_TEST( accum, Auto_ref<int>( 5 ) >= Auto_ref<int>( 5 ));
    ITERATOR_TEST( accum, !( Auto_ref<int>( 5 ) > Auto_ref<int>( 5 )));


    ITERATOR_TEST( accum, !( Auto_ref<int>( 5 ) < 5 ));
    ITERATOR_TEST( accum, Auto_ref<int>( 5 ) <=  5 );
    ITERATOR_TEST( accum, Auto_ref<int>( 5 ) >=  5 );
    ITERATOR_TEST( accum, !( Auto_ref<int>( 5 ) > 5 ));

    ITERATOR_TEST( accum, !( 5 < Auto_ref<int>( 5 )));
    ITERATOR_TEST( accum, 5 <= Auto_ref<int>( 5 ));
    ITERATOR_TEST( accum, 5 >= Auto_ref<int>( 5 ));
    ITERATOR_TEST( accum, !( 5 > Auto_ref<int>( 5 )));
   
  }
  void
  offset_test(){
    using namespace Iterator::Core;

    Auto_ref<int> x( 0 );

    ITERATOR_TEST( accum, ++x == 1 );
    ITERATOR_TEST( accum, x++ == 1 );
    ITERATOR_TEST( accum, x == 2 );
    ITERATOR_TEST( accum, x-- == 2 );
    ITERATOR_TEST( accum, x == 1 );
    ITERATOR_TEST( accum, --x == 0 );
    ITERATOR_TEST( accum, x == 0 );

    ITERATOR_TEST( accum, (x += 2 ) == 2);
    ITERATOR_TEST( accum, x == 2 );
    ITERATOR_TEST( accum, (x -= 2 ) == 0 );
    ITERATOR_TEST( accum, x == 0 );


    ITERATOR_TEST( accum, x[ 1 ] == 1 );
    ITERATOR_TEST( accum, x[ 2 ][ 2 ] == 4 );
    
  }
  operator int() const { return accum; }
  int accum;
}; // end of struct Autoref_test




int
main( int, char** )
{
  int accum = 0;
  accum += Auto_ref_test();
  return accum;
}
