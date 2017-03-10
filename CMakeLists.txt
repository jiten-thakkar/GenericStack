cmake_minimum_required(VERSION 3.2)

project(GenericStack)

include_directories(src/include)

add_library(Stack STATIC
  src/include/stack.h
  src/lib/stack.c
)

add_executable(stack 
  src/main.c
)

target_link_libraries(stack Stack)
