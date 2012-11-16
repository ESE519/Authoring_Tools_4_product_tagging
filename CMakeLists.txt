cmake_minimum_required(VERSION 2.4.6)
project(vios)

# Dependencies
find_package(OpenCV REQUIRED)

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#set the default path for includes
include_directories(${PROJECT_SOURCE_DIR}/include)

# Face library
add_library(face src/face.cpp)

# Object Library
#add_library(object src/object.cpp)

# Face library
add_library(render src/render.cpp)

#target_link_libraries(face ${OpenCV_LIBS})

# Main executable
add_executable(vios src/main.cpp)
target_link_libraries(vios render face ${OpenCV_LIBS})
