#include "ArregloCanciones.h"
#include <fstream>
#include <sstream>
#include <iostream>

ArregloCanciones::ArregloCanciones() {
    capacidadCanciones = 10;
    numCanciones = 0;
    canciones = new Cancion[capacidadCanciones];
}

ArregloCanciones::~ArregloCanciones() {
    delete[] canciones;
}

void ArregloCanciones::expandir() {
    int nuevaCapacidad = capacidadCanciones * 2;
    Cancion* nuevoArreglo = new Cancion[nuevaCapacidad];

    for (int i = 0; i < numCanciones; i++) {
        nuevoArreglo[i] = canciones[i];
    }

    delete[] canciones;
    canciones = nuevoArreglo;
    capacidadCanciones = nuevaCapacidad;
}

void ArregloCanciones::agregarCancion(const Cancion& nuevaCancion) {
    if (numCanciones == capacidadCanciones) {
        expandir();
    }

    canciones[numCanciones++] = nuevaCancion;
}

Cancion* ArregloCanciones::getCanciones() const {
    return canciones;
}

int ArregloCanciones::getNumCanciones() const {
    return numCanciones;
}

void ArregloCanciones::leerArchivoCanciones(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de canciones." << std::endl;
        return;
    }

    int lineCount = 0;

    while (getline(archivo, linea)) {
        lineCount++;
        if (linea.empty()) continue;

        std::stringstream ss(linea);
        std::string campo;

        try {
            // Leer ID canción
            getline(ss, campo, ';');
            if (campo.empty()) throw std::invalid_argument("ID vacío");
            int idCancion = std::stoi(campo);

            // Leer ID álbum
            getline(ss, campo, ';');
            if (campo.empty()) throw std::invalid_argument("Álbum ID vacío");
            int albumId = std::stoi(campo);

            // Título
            std::string titulo;
            getline(ss, titulo, ';');
            if (titulo.empty()) throw std::invalid_argument("Título vacío");

            // Reproducciones
            std::string reproduccionesStr;
            getline(ss, reproduccionesStr, ';');
            if (reproduccionesStr.empty()) throw std::invalid_argument("Reproducciones vacías");

            std::string sinComas;
            for (char c : reproduccionesStr) {
                if (isdigit(c)) sinComas += c;
            }

            int reproducciones = std::stoi(sinComas);

            // Duración
            std::string duracionStr;
            getline(ss, duracionStr, '\n');
            if (duracionStr.empty() || duracionStr.find(':') == std::string::npos) {
                throw std::invalid_argument("Duración malformada");
            }

            int minutos = std::stoi(duracionStr.substr(0, duracionStr.find(':')));
            int segundos = std::stoi(duracionStr.substr(duracionStr.find(':') + 1));
            int duracion = minutos * 60 + segundos;

            // Crear canción y agregar
            Cancion nuevaCancion(idCancion, albumId, titulo, reproducciones, duracion);
            agregarCancion(nuevaCancion);

        } catch (const std::exception& e) {
            std::cerr << "Error en línea " << lineCount << ": " << e.what() << std::endl;
            std::cerr << "Contenido de la línea: " << linea << std::endl;
        }
    }

    archivo.close();
    std::cout << "Lectura del archivo de canciones completada. Total: " << numCanciones << " canciones." << std::endl;
}

Cancion* ArregloCanciones::getCancionPorIndice(int indice) {
    if (indice >= 0 && indice < numCanciones) {
        return &canciones[indice];  // Suponiendo que es un arreglo dinámico de Cancion
    }
    return nullptr;
}