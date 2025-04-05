#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include "Cancion.h" // Incluimos la clase Cancion

class Album {
private:
    int id;
    std::string titulo;
    int anio;
    bool esDeEstudio; // "true" si es de estudio, "false" si es en vivo
    int* canciones;  // Puntero a arreglo dinámico de IDs de canciones
    int numCanciones; // Cuántas canciones tiene este álbum
    int capacidadCanciones; // Capacidad máxima actual del arreglo

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
    Album(int id, const std::string& titulo, int anio, bool esDeEstudio);

    /**
     * Destructor
     */
    ~Album();

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
    bool getEsDeEstudio() const;

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

};

#endif