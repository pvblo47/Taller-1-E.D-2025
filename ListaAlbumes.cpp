//
// Created by ulloc on 12-04-2025.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "Album.h"
#include "ListaAlbumes.h"

#include <vector>

ListaAlbumes::ListaAlbumes() {
    head = nullptr;
}

ListaAlbumes::~ListaAlbumes() {
    Album* aux = head;
    while (aux != nullptr) {
        Album* next = aux->next;
        delete aux;
        aux = next;
    }

}

void ListaAlbumes::insertarOrdenandoId(Album* nuevoAlbum) {
    if (nuevoAlbum == nullptr) {
        std::cerr << "Error: El puntero al álbum es nulo." << std::endl;
        return;
    }

    // Depuración para ver el ID del álbum que se va a insertar
    std::cout << "Insertando álbum con ID: " << nuevoAlbum->getId() << std::endl;

    // Si la lista está vacía o el nuevo álbum debe ir antes que el primero
    if (!head || nuevoAlbum->getId() < head->getId()) {
        nuevoAlbum->next = head; // Apunta el "next" del nuevo álbum al primero
        head = nuevoAlbum; // Actualiza head para que apunte al nuevo álbum
        std::cout << "El álbum con ID " << nuevoAlbum->getId() << " se insertó al principio." << std::endl;
    } else {
        // Si no es el primer álbum, recorreremos la lista
        Album* aux = head;
        while (aux->next && aux->next->getId() < nuevoAlbum->getId()) {
            aux = aux->next; // Avanza hasta el punto donde el nuevo álbum debe ir
        }

        // Inserta el álbum en la posición correcta
        nuevoAlbum->next = aux->next;
        aux->next = nuevoAlbum;
        std::cout << "Álbum con ID " << nuevoAlbum->getId() << " insertado correctamente." << std::endl;
    }
}


void ListaAlbumes::mostrarAlbumes() {
    Album* aux = head;
    while (aux) {
        std::cout << "ID: " << aux->id << " | Título: " << aux->titulo << " | Año: " << aux->anio << std::endl;
        aux = aux->next;
    }
}

Album* ListaAlbumes::buscarAlbumPorId(int id) {
    Album* aux = head;
    while (aux) {
        if (aux->getId() == id) {
            return aux;
        }
        aux = aux->getNext();
    }
    return nullptr;
}


void ListaAlbumes::leerArchivoAlbumes(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    std::cout << "Archivo de álbumes abierto correctamente." << std::endl;

    while (getline(archivo, linea)) {
        std::cout << "Leyendo línea: " << linea << std::endl;

        std::stringstream ss(linea);
        std::string campo;
        std::vector<std::string> campos;

        // Leemos todos los campos separados por ';'
        while (getline(ss, campo, ';')) {
            campos.push_back(campo);
        }

        // Validamos que tenga al menos 5 campos (ID, título, año, estudio, canciones)
        if (campos.size() < 5) {
            std::cerr << "Línea ignorada por tener menos de 5 campos: " << linea << std::endl;
            continue;
        }

        // Asignamos cada campo a su variable
        int idAlbum;
        try {
            idAlbum = std::stoi(campos[0]);
        } catch (const std::invalid_argument&) {
            std::cerr << "ID inválido en línea: " << linea << std::endl;
            continue;
        }

        std::string titulo = campos[1];
        std::cout << "Título extraído: " << titulo << std::endl;  // Verificación del título

        int anio;
        try {
            anio = std::stoi(campos[2]);
        } catch (const std::invalid_argument&) {
            std::cerr << "Año inválido en línea: " << linea << std::endl;
            continue;
        }

        std::string esDeEstudio = campos[3];
        for (auto& c : esDeEstudio) c = std::tolower(c);
        if (esDeEstudio == "sí" || esDeEstudio == "si") esDeEstudio = "Si";
        else if (esDeEstudio == "no") esDeEstudio = "No";
        else {
            std::cerr << "Campo 'esDeEstudio' inválido en línea: " << linea << std::endl;
            continue;
        }

        std::string canciones = campos[4];
        std::cout << "Canciones extraídas: " << canciones << std::endl;

        // Limpiamos las llaves de la lista de canciones
        std::string cancionesSinLlaves = "";
        for (char c : canciones) {
            if (c != '{' && c != '}') {
                cancionesSinLlaves += c;
            }
        }

        std::cout << "Canciones sin llaves: " << cancionesSinLlaves << std::endl;

        // Creamos el álbum
        Album* nuevoAlbum = new Album(idAlbum, titulo, anio, esDeEstudio);

        // Convertimos los índices de canciones a enteros y agregamos al álbum
        std::stringstream cancionesStream(cancionesSinLlaves);
        while (getline(cancionesStream, campo, ',')) {
            try {
                int indiceCancion = std::stoi(campo);
                nuevoAlbum->agregarCancion(indiceCancion);
            } catch (const std::invalid_argument&) {
                std::cerr << "Índice de canción inválido en línea: " << linea << std::endl;
                continue;
            }
        }

        insertarOrdenandoId(nuevoAlbum);
    }

    archivo.close();
}


Album* ListaAlbumes::getHead() const {
    return head;
}