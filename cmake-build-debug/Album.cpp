//
// Created by ulloc on 29-03-2025.
//

#include "Album.h"


// Constructor con parámetros
Album::Album(int id, const std::string &titulo, int anio, const std::string &esDeEstudio)
    : id(id), titulo(titulo), anio(anio), esDeEstudio(esDeEstudio) {

}

// Constructor por defecto
Album::Album()
    : id(0), titulo(""), anio(0), esDeEstudio("") {}
