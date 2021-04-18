cmake_minimum_required(VERSION 3.16.3)

project (CloudWalk)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    message("Debug mode!")
    add_compile_options(-g -ggdb -O0)
    set(CMAKE_VERBOSE_MAKEFILE ON)
else()
    message("Release mode!")
    add_compile_options(-Wall -Wextra -pedantic -Werror -O3)
endif()

file(MAKE_DIRECTORY out)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
