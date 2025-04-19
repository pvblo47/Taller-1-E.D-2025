#include "Cancion.h"

#include <fstream>
#include <iostream>
#include <sstream>


Cancion::Cancion() {
    idCancion = 0;
    albumId = 0;
    titulo = "";
    reproducciones = 0;
    duracion = 0;
}


Cancion::Cancion(int id, int albumId, const std::string& titulo, int reproducciones, int duracion)
    : idCancion(id), albumId(albumId), titulo(titulo), reproducciones(reproducciones), duracion(duracion) {}


int Cancion::getIdCancion() const {
    return idCancion;
}
int Cancion::getAlbumId() const {
    return albumId;
}

std::string Cancion::getTitulo() const {
    return titulo;
}

int Cancion::getReproducciones() const {
    return reproducciones;
}

int Cancion::getDuracion() const {
    return duracion;
}


void Cancion::setTitulo(const std::string& titulo) {
    this->titulo = titulo;
}

void Cancion::setReproducciones(int reproducciones) {
    this->reproducciones = reproducciones;
}

void Cancion::setDuracion(int duracion) {
    this->duracion = duracion;
}

