
#Uncoment if Conan is used
#find_package(GTest REQUIRED)
#target_link_libraries(${PROJECT_NAME}-test
# PUBLIC
# ${CONAN_LIBS}
#  src)
#add_test(NAME movements_test
#COMMAND movements_test)
##############
#Coment if Conan is used
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        797b0ad2a3a45608ecf5c67e6e289d377a3521ca #GTest version tag here
)
FetchContent_MakeAvailable(googletest)
###############

add_executable(${PROJECT_NAME}-test
Square.cpp 
MovementsFigures.cpp
MovementsUpDown.cpp
MovementsSides.cpp
MovementsDiagonal.cpp
MovementsOnDeep.cpp
)
#Coment if Conan is used
target_link_libraries(${PROJECT_NAME}-test  gtest_main gmock_main src)

  file(COPY
../src/images
DESTINATION ${CMAKE_BINARY_DIR}/test)

#Coment if Conan is used
include(GoogleTest)
#Coment if Conan is used
gtest_discover_tests(${PROJECT_NAME}-test)

target_include_directories(${PROJECT_NAME}-test PUBLIC ../src/include Mocks)