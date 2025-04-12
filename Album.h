#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include "Cancion.h" // Incluimos la clase Cancion

class Album {
private:



public:
    /**
     * Constructor por defecto
     */
    Album();
    /**
     * Constructor con parametros
     * @param id Identificador de album
     * @param titulo // de Album
     * @param anio // del album
     * @param esDeEstudio / "true" si es de estudio, "false" si es en vivo
     */
    Album(int id, const std::string& titulo, int anio, const std::string& esDeEstudio);

    /**
     * Destructor
     */
    ~Album();

 void agregarCancion(int indiceCancion);

 /**
     * 
     * @return Obtiene el id
     */
    int getId() const;

    /**
     * 
     * @return Obtiene el título
     */
    std::string getTitulo() const;

    /**
     * 
     * @return Obtiene el año
     */
    int getAnio() const;

    /**
     * 
     * @return Obtiene el booleano si es de estudio o no
     */
     std::string getEsDeEstudio() const;

    /**
     * 
     * @return Obtiene el puntero al arreglo dinamico que contiene las canciones
     */
    int *getCanciones() const;

    /**
     *
     * @return Obtiene el numero de canciones en el arreglo
     */
    int getNumCanciones() const;

    /**
     *
     * @return Obtiene la capacidad maxima de canciones en el arreglo
     */
    int getCapacidadCanciones() const;

    Album* next;         // Siguiente album lista enlazada, es como un nodo por asi decirlo pero de tipo album.
    int id;                   // ID único del álbum
    std::string titulo;       // Nombre del álbum
    int anio;                 // Año de publicación
    std::string esDeEstudio; // "Si" o "No"

    int* canciones;           // Arreglo dinámico de índices de canciones
    int numCanciones;         // Cantidad actual de canciones
    int capacidadCanciones;   // Capacidad del arreglo dinámico
};

#endif