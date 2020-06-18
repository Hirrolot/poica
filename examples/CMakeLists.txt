cmake_minimum_required(VERSION 3.16)
project(examples LANGUAGES C)

include_directories(../include)

add_executable(ast ast.c)
add_executable(binary_tree binary_tree.c)
add_executable(error_handling error_handling.c)
add_executable(heron_formula heron_formula.c)
add_executable(obj obj.c)
add_executable(tokens tokens.c)

add_executable(product_introspection introspection/product.c)
add_executable(sum_introspection introspection/sum.c)

target_link_libraries(heron_formula m)

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
  error_handling
  heron_formula
  message_passing
  obj
  tokens
  PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
