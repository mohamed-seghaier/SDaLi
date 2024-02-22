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

#main
set(MAIN_SOURCE_FILE
src/main.cpp
)

#################
# Headers files #
#################

set(BUILDER_HEADER_FILES
Builders/include/IBuilder.h
  Builders/include/WindowBuilder.h
)

set(WINDOW_HEADER_FILES
  Window/include/WindowManager.h
)


#################
# Sources files #
#################

set(BUILDER_SOURCE_FILES
Builders/src/IBuilder.cpp
Builders/src/WindowBuilder.cpp
)

set(WINDOW_SOURCE_FILES
Window/src/WindowManager.cpp
)

# Link libraries
link_libraries(${SDL2_LIBRARIES})


## TMP, FOR DEVELOPMENT I NEED TO GENERATE AN EXECUTABLE

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
# Create exe
add_executable(SDaLi 



##########
## MAIN ##
##########

${MAIN_SOURCE_FILE}



#############
## BUILDER ##
#############

${BUILDER_SOURCE_FILES} ${BUILDER_HEADER_FILES}

############
## WINDOW ##
############

${WINDOW_SOURCE_FILES} ${WINDOW_HEADER_FILES}

)



