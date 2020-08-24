cmake_minimum_required(VERSION 3.0)
project(examples LANGUAGES C)

include_directories(../include ../preprocessor/include ../vmd/include)
add_compile_definitions(POICA_ENABLE_ASERTIONS)

if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-Wall)
elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-Wall -Wextra -ftrack-macro-expansion=0)
endif()

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
add_executable(dyn_dispatch dyn_dispatch.c)
add_executable(interfaces interfaces.c)
add_executable(int_bool_ast int_bool_ast.c)
add_executable(hkt hkt.c)

foreach(TARGET ${BUILDSYSTEM_TARGETS})
  set_target_properties(TARGET PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
endforeach()
