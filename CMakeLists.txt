cmake_minimum_required (VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Chess)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

add_executable(${PROJECT_NAME} 
src/main.cpp
src/Figure.cpp
src/Rook.cpp
src/Pawn.cpp
src/King.cpp
src/Knight.cpp
src/Queen.cpp
src/Bishop.cpp
src/FigureManager.cpp
src/ChessManager.cpp)
target_link_libraries(Chess ${CONAN_LIBS})

file(COPY
src/images
DESTINATION ${CMAKE_BINARY_DIR})