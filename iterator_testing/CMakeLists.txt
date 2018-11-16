macro( iterator_add_simple_test  name )
  add_executable( ${name}_test ${name}_test.cpp )
  target_link_libraries( ${name}_test PRIVATE iterator )
  add_test( ${name} ${name}_test ) 
endmacro( iterator_add_simple_test  name )




iterator_add_simple_test( autoref )
iterator_add_simple_test( range )
iterator_add_simple_test( iterable )

add_subdirectory(gtest_external)


add_test_executable(
  NAME algorithm
  EXENAME algorithm_test
  SOURCE_FILES for_each_iter.cpp
  DEPENDENCIES iterator google::test_main )
