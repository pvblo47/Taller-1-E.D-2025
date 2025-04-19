#ifndef SISTEMA_H
#define SISTEMA_H

#include "ListaAlbumes.h"
#include "ArregloCanciones.h"

class Sistema {
private:
    ListaAlbumes listaAlbumes;  // Lista para manejar los álbumes
    ArregloCanciones canciones; // Arreglo para manejar las canciones

public:
    // Método principal para iniciar el sistema
    void iniciar();

    // Muestra el menú principal y gestiona las opciones
    void mostrarMenu();

    // Muestra un álbum específico
    void mostrarAlbumPorId(int idAlbum);


    // Lógica de búsqueda avanzada para canciones
    void busquedaAvanzada();

    // Elimina un álbum
    void eliminarAlbum();

    // Lógica para jugar trivia
    void jugarTrivia();

    // Método de salida, para liberar recursos y guardar si es necesario
    void salir();
};

#endif // SISTEMA_H
