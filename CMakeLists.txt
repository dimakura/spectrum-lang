cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

project(Spectrum)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")
add_subdirectory(src/java/ast) # spectrum-java library
find_package(Catch2 REQUIRED) # Catch2

set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(TEST_SOURCES 
  ${TEST_DIR}/main.cpp
  ${TEST_DIR}/java/ast/identifier_test.cpp)
add_executable(spectrum_test ${TEST_SOURCES})
target_link_libraries(spectrum_test spectrum-java)
target_link_libraries(spectrum_test Catch2::Catch2)
