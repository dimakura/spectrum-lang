cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

project(Spectrum)

#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/java/ast")
add_subdirectory(src/java/ast)

# Prepare libraries
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Catch2 REQUIRED)
find_package(Boost REQUIRED)
#find_package(Boost COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
message(${Boost_INCLUDE_DIRS})
#message("${Boost_LIBRARIES}")
#message("${Boost_LIBRARIES}")

# Make test executable
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(TEST_SOURCES 
  ${TEST_DIR}/main.cpp
  ${TEST_DIR}/java/ast/identifier_test.cpp)
add_executable(spectrum_test ${TEST_SOURCES})
target_link_libraries(spectrum_test JavaAST)
target_link_libraries(spectrum_test Catch2::Catch2)
#target_link_libraries(spectrum_test ${Boost_LIBRARIES}) 
