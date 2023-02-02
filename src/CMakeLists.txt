add_library(src
Figure.cpp
Rook.cpp
Pawn.cpp
King.cpp
Knight.cpp
Queen.cpp
Bishop.cpp
FigureManager.cpp
ChessManager.cpp)

target_link_libraries( src PUBLIC ${CONAN_LIBS})

file(COPY
images
DESTINATION ${CMAKE_BINARY_DIR})