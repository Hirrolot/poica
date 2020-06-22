cmake_minimum_required(VERSION 3.16)
project(examples LANGUAGES C)

include_directories(../include)

add_executable(ast ast.c)
add_executable(binary_tree binary_tree.c)
add_executable(error_handling error_handling.c)
add_executable(obj obj.c)
add_executable(tokens tokens.c)
add_executable(compare_variants compare_variants.c)

add_executable(record_introspection introspection/record.c)
add_executable(enum_introspection introspection/enum.c)

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
  message_passing
  obj
  tokens
  compare_variants
  PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
