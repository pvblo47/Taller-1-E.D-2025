#include "Cancion.h"


Cancion::Cancion() {
    idCancion = 0;
    albumId = 0;
    titulo = "";
    reproducciones = 0;
    duracion = "0:00";
}


Cancion::Cancion(int idCancion, int albumId, const std::string& titulo, int reproducciones, const std::string& duracion) {
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

std::string Cancion::getDuracion() const {
    return duracion;
}


void Cancion::setTitulo(const std::string& titulo) {
    this->titulo = titulo;
}

void Cancion::setReproducciones(int reproducciones) {
    this->reproducciones = reproducciones;
}

void Cancion::setDuracion(const std::string& duracion) {
    this->duracion = duracion;
}
