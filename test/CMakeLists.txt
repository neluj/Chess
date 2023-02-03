add_library(test
BasicMovements.cpp)

include(GoogleTest)

target_link_libraries( test PUBLIC ${CONAN_LIBS})