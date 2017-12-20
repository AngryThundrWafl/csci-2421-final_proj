cmake_minimum_required(VERSION 3.3)
project(AddressBookCleanerVersion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        contact.h contact.cpp
        functions.h functions.cpp
        avlnode.h avlnode.cpp
        avltree.h avltree.cpp
        bstnode.h bstnode.cpp
        bstree.h bstree.cpp
        itemtype.h
        main.cpp)
add_executable(AddressBookCleanerVersion ${SOURCE_FILES})