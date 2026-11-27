cmake_minimum_required(VERSION 3.24)
project(Arbori)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# forces everything underneath these commands to have that standard

add_executable(arbori)
target_sources(arbori
    PRIVATE    
        main.cpp
        # Arbore.cpp 
        # binary_tree.cpp 
        # <- they are already in my library
        # <- putting them here too would cause issues
        # <- such as compiling twice, double definitions etc.
)

target_compile_options(arbori
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
)

target_link_libraries(arbori # the target I want to modify
    PRIVATE
        BinaryTree
)

# PRIVATE   - only for me
# INTERFACE - for others
# PUBLIC    - available to all

add_library(BinaryTree STATIC) # INTERFACE pt header-only library
target_sources(BinaryTree
    PRIVATE
        Arbore.cpp
        binary_tree.cpp
    PUBLIC
        FILE_SET HEADERS # name
        # TYPE HEADERS
        # BASE_DIRS lab9
        FILES
            binary_tree.hpp
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(arbori PRIVATE -g -O0 -fsanitize=address,undefined)
    target_compile_options(BinaryTree PRIVATE -g -O0 -fsanitize=address,undefined)
    target_link_options(arbori PRIVATE -fsanitize=address,undefined)
endif()