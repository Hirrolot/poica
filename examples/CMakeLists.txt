cmake_minimum_required(VERSION 3.16)
project(examples LANGUAGES C)

include_directories(../include)

add_executable(ast ast.c)
add_executable(binary_tree binary_tree.c)
add_executable(error_handling error_handling.c)
add_executable(heron_formula heron_formula.c)
add_executable(message_passing message_passing.c)
add_executable(obj obj.c)
add_executable(tokens tokens.c)

target_link_libraries(heron_formula m)
target_link_libraries(message_passing libdill.a pthread)

set_target_properties(
  ast
  binary_tree
  error_handling
  heron_formula
  message_passing
  obj
  tokens
  PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
