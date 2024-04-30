cmake_minimum_required(VERSION 3.10)
project(SDALi)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# SDL
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)



if(APPLE)
  set(SDL2_IMAGE_INCLUDE_DIRS /usr/local/opt/sdl2_image/include)
  set(SDL2_IMAGE_LIBRARIES /usr/local/opt/sdl2_image/lib/libSDL2_image.dylib)
  include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

endif()

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})


# add headers repertories
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/Builders/include
  ${CMAKE_CURRENT_SOURCE_DIR}/Builders/Image/include
  ${CMAKE_CURRENT_SOURCE_DIR}/Builders/Window/include
  ${CMAKE_CURRENT_SOURCE_DIR}/Window/include
  ${CMAKE_CURRENT_SOURCE_DIR}/Image/include
)

# main
set(MAIN_SOURCE_FILE
  src/main.cpp
)

# ################
# Headers files #
# ################
set(BUILDER_HEADER_FILES
  Builders/include/IBuilder.h
)
set(WINDOW_BUILDER_HEADER_FILES
  Builders/Window/include/WindowBuilder.h
  Builders/Window/include/WindowTestBuilder.h
)

set(IMAGE_BUILDER_HEADER_FILES
  Builders/Image/include/ImageBuilder.h
)

set(WINDOW_HEADER_FILES
  Window/include/WindowManager.h
)

set(IMAGE_HEADER_FILES
  Image/include/ImageManager.h
)

# ################
# Sources files #
# ################
set(WINDOW_BUILDER_SOURCE_FILES
  Builders/Window/src/WindowBuilder.cpp
  Builders/Window/src/WindowTestBuilder.cpp
)

set(IMAGE_BUILDER_SOURCE_FILES
  Builders/Image/src/ImageBuilder.cpp
)

set(WINDOW_SOURCE_FILES
  Window/src/WindowManager.cpp
)

set(IMAGE_SOURCE_FILES
  Image/src/ImageManager.cpp
)

# Link libraries
link_libraries(${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# # TMP, FOR DEVELOPMENT I NEED TO GENERATE AN EXECUTABLE
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Create exe
add_executable(SDaLi

  # #########
  # # MAIN ##
  # #########
  ${MAIN_SOURCE_FILE}

  # ############
  # # BUILDER ##
  # ############
  ${BUILDER_HEADER_FILES}
  ${WINDOW_BUILDER_SOURCE_FILES} ${WINDOW_BUILDER_HEADER_FILES}
  ${IMAGE_BUILDER_SOURCE_FILES} ${IMAGE_BUILDER_HEADER_FILES}

  # ###########
  # # WINDOW ##
  # ###########
  ${WINDOW_SOURCE_FILES} ${WINDOW_HEADER_FILES}

  # ##########
  # # IMAGE ##
  # ##########
  ${IMAGE_SOURCE_FILES} ${IMAGE_HEADER_FILES}
)
target_link_libraries(SDaLi SDL2_image::SDL2_image)