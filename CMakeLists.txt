cmake_minimum_required( VERSION 3.1 )
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# project name
project( Matrix )
enable_testing()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
                      
# include files
include_directories( ./include ./src ./test )
include_directories(${Boost_INCLUDE_DIRS})

# target
# to display a matrix
add_executable( matrix_def ./src/main.cpp ./src/Matrix.cpp ./src/Matrix.hpp)
add_executable( test_matrix_dim ./src/Matrix.cpp ./test/matrix_tests.cpp)

target_link_libraries(test_matrix_dim ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# tests
add_test( NAME test_matrix_dim COMMAND test_matrix_dim)
