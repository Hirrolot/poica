cmake_minimum_required(VERSION 3.0)
project(examples LANGUAGES C)

include_directories(../include)

add_executable(ast ast.c)
add_executable(binary_tree binary_tree.c)
add_executable(binary_tree_malloc binary_tree_malloc.c)
add_executable(error_handling error_handling.c)
add_executable(obj obj.c)
add_executable(tokens tokens.c)
add_executable(compare_variants compare_variants.c)

add_executable(record_introspection introspection/record.c)
add_executable(choice_introspection introspection/choice.c)

add_executable(maybe maybe.c)
add_executable(either either.c)
add_executable(pair pair.c)

add_executable(generic_linked_list generic_linked_list.c)
add_executable(swap_registers swap_registers.c)
add_executable(int_bool_ast int_bool_ast.c)

if(UNIX)
  add_executable(message_passing message_passing.c)
  target_link_libraries(message_passing libdill.a pthread)
endif(UNIX)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-Wall)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-Wall -Wextra)
endif()

set_target_properties(
  ast
  binary_tree
  binary_tree_malloc
  error_handling
  message_passing
  obj
  tokens
  compare_variants
  record_introspection
  choice_introspection
  maybe
  either
  pair
  generic_linked_list
  swap_registers
  int_bool_ast
  PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
