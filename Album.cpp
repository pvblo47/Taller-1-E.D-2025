#include "Album.h"
#include <iostream>
Album::Album() {
    id = 0;
    titulo = "";
    anio = 0;
    esDeEstudio = "No";
    canciones = nullptr;
    numCanciones = 0;
    capacidadCanciones = 0;
    next = nullptr;
}
Album::Album(int id, const std::string& titulo, int anio, const std::string& esDeEstudio)
    : id(id), titulo(titulo), anio(anio), esDeEstudio(esDeEstudio) {
    canciones = nullptr;
    numCanciones = 0;
    capacidadCanciones = 0;
    next = nullptr;
}

Album::~Album() {
    delete[] canciones;
}

void Album::agregarCancion(int indiceCancion) {
    if (numCanciones == capacidadCanciones) {
        if (capacidadCanciones == 0) { 
            capacidadCanciones = 4;
        } else {
            capacidadCanciones *= 2;
        }

        int* nuevoArreglo = new int[capacidadCanciones];

        for (int i = 0; i < numCanciones; ++i) {
            nuevoArreglo[i] = canciones[i];
        }

        delete[] canciones;
        canciones = nuevoArreglo;
    }

    canciones[numCanciones++] = indiceCancion;
}
