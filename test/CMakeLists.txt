find_package(GTest REQUIRED)

add_executable(movements_test 
#MovementsUp.cpp
#MovementsDown.cpp
#MovementsLeft.cpp
#MovementsRight.cpp
#MovementsUpLeft.cpp
#MovementsUpRight.cpp
#MovementsDownRight.cpp
#MovementsDownLeft.cpp
#MovementsPawn.cpp
MovementsSidesDeep.cpp)

target_link_libraries(movements_test
 PUBLIC
 ${CONAN_LIBS}
  src)

  file(COPY
../src/images
DESTINATION ${CMAKE_BINARY_DIR}/test)

add_test(NAME movements_test
COMMAND movements_test)

target_include_directories(movements_test PUBLIC ../src/include )