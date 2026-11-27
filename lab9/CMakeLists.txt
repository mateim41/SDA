cmake_minimum_required(VERSION 3.24)
project(lab9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Arbori)
target_sources(Arbori
    PRIVATE
        main.cpp
        Arbore.cpp
)

target_compile_options(Arbori PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(Arbori PRIVATE -g -O0 -fsanitize=address,undefined)
    target_link_options(Arbori PRIVATE -fsanitize=address,undefined)
endif()

target_link_libraries(Arbori # the target I want to modify
    PRIVATE # only visible to the target
        BinaryTree # the libraries I want to add
)

# PRIVATE   - only for me
# INTERFACE - for others
# PUBLIC    - available to all

add_library(BinaryTree STATIC) # header only library
target_sources(BinaryTree
    PRIVATE
        Arbore.cpp

    PUBLIC
        FILE_SET HEADERS # name of the file_set
        # TYPE HEADERS
        # BASE_DIRS lab9
        FILES
            BinaryTree.hpp
)

# add_library(ArboreLib STATIC)
# target_sources(ArboreLib
#     PRIVATE
#         Arbore.cpp
# )
# target_link_libraries(ArboreLib
#     PUBLIC # because the library includes in the cpp BinaryTree.hpp
#         BinaryTree
# )