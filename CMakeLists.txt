cmake_minimum_required(VERSION 3.10)

project(HelloCMake)

add_compile_options(-lSDL2)

include_directories(include)

add_executable(SDaLi
## HEADERS
  include/header1.h
  include/header2.h

## SOURCES


  src/main.cpp
  src/other_source.c

)

add_executable(hello src/main.cpp)