cmake_minimum_required(VERSION 3.23)
project(lab9)

add_executable(Arbori)
target_sources(Arbori
    PRIVATE
        main.cpp
)

target_link_libraries(Arbori # the target I want to modify
    PRIVATE # only visible to the target
        BinaryTree # the library I want to add
)

# PRIVATE   - only for me
# INTERFACE - for others
# PUBLIC    - available to all

add_library(BinaryTree INTERFACE) # header only library
target_sources(BinaryTree
    INTERFACE
        FILE_SETS HEADERS
        # TYPE HEADERS
        # BASE_DIR lab9
        FILES
            BinaryTree.hpp
)