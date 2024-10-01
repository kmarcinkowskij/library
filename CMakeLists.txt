cmake_minimum_required(VERSION 3.28)
project(biblioteka)

set(CMAKE_CXX_STANDARD 26)

add_executable(biblioteka main.cpp
        Library.cpp
        Library.h
        book/Book.cpp
        book/Book.h
        book/Ebook.cpp
        book/Ebook.h
        book/Audiobook.cpp
        book/Audiobook.h
        book/Paperback.cpp
        book/Paperback.h
        utils/Utilities.cpp
        utils/Utilities.h
        reader/Reader.cpp
        reader/Reader.h
        control/Control.cpp
        control/Control.h)
