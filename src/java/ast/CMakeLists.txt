find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_library(spectrum-java 
  identifier.cpp
  type.cpp)
