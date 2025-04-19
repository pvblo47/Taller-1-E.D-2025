//
// Created by ulloc on 12-04-2025.
//

#ifndef LISTAALBUMES_H
#define LISTAALBUMES_H
#include "Album.h"


class ListaAlbumes {


private:
    /**
     * Primer "Nodo" de la lista
     */
    Album* head;


public:
    /**
     * Constructor de la lista enlazada, no contiene ningún parametro
     */
    ListaAlbumes();

    /**
     * Destrcutor de la lista enlazada, no contiene ningún parametro
     */
    ~ListaAlbumes();

    /**
     * Inserta un album nuevo y lo va ordenando por id
     * @param nuevoAlbum album que se insertará
     */
    void insertarOrdenandoId(Album* nuevoAlbum);

    /**
     * Para mostrar los albumnes
     */
    void mostrarAlbumes();

    /**
     * Busca el album por id
     * @param id del album a buscar
     * @return
     */
    Album* buscarAlbumPorId(int id);          // buscar un álbum por su ID

    void leerArchivoAlbumes(const std::string& nombreArchivo);


       Album* getHead() const;
};



#endif //LISTAALBUMES_H
