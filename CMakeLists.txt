cmake_minimum_required(VERSION 3.10)
project(SDALi)

set(CMAKE_CXX_STANDARD 17)

# SDL
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# add headers repertories
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/Builders/include
  ${CMAKE_CURRENT_SOURCE_DIR}/Window/include
)

# cpp files
set(SOURCE_FILES
  src/main.cpp
  Builders/src/WindowBuilder.cpp
  Window/src/WindowManager.cpp
)

# Headers files
set(HEADER_FILES
  Builders/include/WindowBuilder.h
  Window/include/WindowManager.h
)

# Link libraries
link_libraries(${SDL2_LIBRARIES})


## TMP, FOR DEVELOPMENT I NEED TO GENERATE AN EXECUTABLE

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
# Create exe
add_executable(SDaLi ${SOURCE_FILES} ${HEADER_FILES})



