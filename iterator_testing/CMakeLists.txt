macro( iterator_add_simple_test  name )
  add_executable( ${name}_test ${name}_test.cpp )
  add_test( ${name} ${name}_test ) 
endmacro( iterator_add_simple_test  name )



iterator_add_simple_test( autoref )
iterator_add_simple_test( range )

