#include "Album.h"

// Constructor por defecto
Album::Album() {
    id = 0;
    titulo = "";
    anio = 0;
    esDeEstudio = "No";
    capacidadCanciones = 10;
    canciones = new int[capacidadCanciones];
    next = nullptr;
}

// Constructor con parámetros
Album::Album(int id, const std::string& titulo, int anio, const std::string& esDeEstudio)
    : id(id), titulo(titulo), anio(anio), esDeEstudio(esDeEstudio) {
    capacidadCanciones = 10;
    canciones = new int[capacidadCanciones];
    numCanciones = 0;
    next = nullptr;
}

// Destructor
Album::~Album() {
    if (canciones != nullptr) {
        delete[] canciones;
        canciones = nullptr;
    }
}

void Album::agregarCancion(int indiceCancion) {
    if (numCanciones == capacidadCanciones) {
        capacidadCanciones *= 2;
        int* nuevoArreglo = new int[capacidadCanciones];
        for (int i = 0; i < numCanciones; ++i) {
            nuevoArreglo[i] = canciones[i];
        }
        delete[] canciones;
        canciones = nuevoArreglo;
    }

    canciones[numCanciones++] = indiceCancion;
}

// Getters
int Album::getId() const {
    return id;
}

std::string Album::getTitulo() const {
    return titulo;
}

int Album::getAnio() const {
    return anio;
}

std::string Album::getEsDeEstudio() const {
    return esDeEstudio;
}

int* Album::getCanciones() const {
    return canciones;
}

int Album::getNumCanciones() const {
    return numCanciones;
}

int Album::getCapacidadCanciones() const {
    return capacidadCanciones;
}

Album* Album::getNext() const {
    return next;
}
