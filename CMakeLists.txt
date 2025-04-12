cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Album.cpp
        Album.h
        Cancion.cpp
        Cancion.h
        ListaAlbumes.cpp
        ListaAlbumes.h
)
