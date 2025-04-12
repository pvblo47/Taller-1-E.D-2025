#include "Cancion.h"


Cancion::Cancion() {
    idCancion = 0;
    albumId = 0;
    titulo = "";
    reproducciones = 0;
    duracion = 0;
}


Cancion::Cancion(int idCancion, int albumId, const std::string& titulo, int reproducciones, int duracion) {
    this->idCancion = idCancion;
    this->albumId = albumId;
    this->titulo = titulo;
    this->reproducciones = reproducciones;
    this->duracion = duracion;
}

int Cancion::getIdCancion() {
    return idCancion;
}
int Cancion::getAlbumId() {
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
