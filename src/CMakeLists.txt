cmake_minimum_required (VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Chess)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

add_executable(${PROJECT_NAME} 
main.cpp
Figure.cpp
Rook.cpp
Pawn.cpp
King.cpp
Knight.cpp
Queen.cpp
Bishop.cpp
FigureManager.cpp)
target_link_libraries(Chess ${CONAN_LIBS})

file(COPY
images
DESTINATION ${CMAKE_BINARY_DIR})