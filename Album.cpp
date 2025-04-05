#include "Album.h"
#include <iostream>

Album::Album() {
    id = 0;
    titulo = "";
    anio = 0;
    esDeEstudio = false;
    canciones = nullptr;  // No tiene canciones al principio
    numCanciones = 0; // Va aumentando mientras se agregan en la lectura
    capacidadCanciones = 0; // Va aumentando mientras se agregan en la lectura y mientras se va redimensionando
}

Album::Album(int id, const std::string& titulo, int anio, bool esDeEstudio) {
    this->id = id;
    this->titulo = titulo;
    this->anio = anio;
    this->esDeEstudio = esDeEstudio;
    canciones = nullptr;
    numCanciones = 0;
    capacidadCanciones = 0;
}

Album::~Album() {
    delete[] this->canciones; // Se libera la memoria cuando el álbum ya no existe
}


int Album::getId() const {
    return id;
}

std::string Album::getTitulo() const {
    return titulo;
}

int Album::getAnio() const {
    return anio;
}

bool Album::getEsDeEstudio() const {
    return esDeEstudio;
}

int *Album::getCanciones() const {
    return canciones;
}

int Album::getNumCanciones() const {
    return numCanciones;
}

