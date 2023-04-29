add_library(src
Game.cpp
Board.cpp
Player.cpp
FigureRenderizerSFML.cpp
PossibleMovementsRenderizerSFML.cpp
Figure.cpp
Rook.cpp
Pawn.cpp
King.cpp
Knight.cpp
Queen.cpp
Bishop.cpp
State.cpp
StateNothingSelected.cpp
StateFigureSelected.cpp
MovementsSides.cpp
MovementsUpDown.cpp
MovementsPositionState.cpp
MovementsDiagonal.cpp
MovementsKnight.cpp
MovementsPawn.cpp
MovementsQueen.cpp
MovementsRook.cpp
MovementsBishop.cpp
MovementsKing.cpp
)

#Uncoment if Conan is used
#target_link_libraries( src PUBLIC ${CONAN_LIBS})

if(UNIX)
find_package(SFML 2.5.1 COMPONENTS window graphics REQUIRED)
target_link_libraries( src PUBLIC sfml-window sfml-graphics)
endif (UNIX)

file(COPY
images
DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(src PUBLIC include ) 
