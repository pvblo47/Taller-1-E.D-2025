//
// Created by ulloc on 12-04-2025.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "Album.h"
#include "ListaAlbumes.h"

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
    if (!head || nuevoAlbum->id < head->id) {
        nuevoAlbum->next = head;
        head = nuevoAlbum;
    } else {
        Album* aux = head;
        while (aux->next && aux->next->id < nuevoAlbum->id) { // Mientras exista el siguiente y el id del siguiente sea menor al id del album que se esta insertando
            aux = aux->next; // el auxiliar recorre una posición
        }
        nuevoAlbum->next = aux->next;
        aux->next = nuevoAlbum;
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
        if (aux->id == id) {
            return aux;
        }
        aux = aux->next;
    }
    return nullptr;
}


void ListaAlbumes::leerArchivoAlbumes(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo" << std::endl;
        return;
    }

    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string campo;

        int idAlbum;
        getline(ss, campo, ';');
        idAlbum = std::stoi(campo);

        std::string titulo;
        getline(ss, titulo, ';');

        int anio;
        getline(ss, campo, ';');
        anio = std::stoi(campo);

        std::string esDeEstudio;
        getline(ss, esDeEstudio, ';');

        // (sin remover las llaves)
        std::string canciones;
        getline(ss, canciones, '\n');

        // Se Quitan las llaves
        std::string cancionesSinLlaves = "";
        for (char c : canciones) {
            if (c != '{' && c != '}') {
                cancionesSinLlaves += c;
            }
        }

        Album* nuevoAlbum = new Album(idAlbum, titulo, anio, esDeEstudio);

        // (convertir a entero y agregarlas)
        std::stringstream cancionesStream(cancionesSinLlaves);
        while (getline(cancionesStream, campo, ',')) {
            int indiceCancion = std::stoi(campo); // Convertir el índice a int
            nuevoAlbum->agregarCancion(indiceCancion); // Agrega la canción al álbum
        }

        // Inserta el álbum ordenado en la lista
        insertarOrdenandoId(nuevoAlbum);
    }

    archivo.close();
}