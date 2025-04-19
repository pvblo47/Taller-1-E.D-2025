#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include "Cancion.h" // Incluimos la clase Cancion

class Album {
public:
 // Atributos públicos
 int id;                   // ID único del álbum
 std::string titulo;       // Nombre del álbum
 int anio;                 // Año de publicación
 std::string esDeEstudio; // "Si" o "No"
 int* canciones;           // Arreglo dinámico de índices de canciones
 int numCanciones;         // Cantidad actual de canciones
 int capacidadCanciones;   // Capacidad del arreglo dinámico
 Album* next;              // Siguiente álbum en la lista enlazada

 /**
  * Constructor por defecto
  */
 Album();

 /**
  * Constructor con parámetros
  * @param id Identificador de album
  * @param titulo Título del album
  * @param anio Año del album
  * @param esDeEstudio "true" si es de estudio, "false" si es en vivo
  */
 Album(int id, const std::string& titulo, int anio, const std::string& esDeEstudio);

 /**
  * Destructor
  */
 ~Album();

 /**
  * Agrega una canción al arreglo de canciones
  * @param indiceCancion Índice de la canción
  */
 void agregarCancion(int indiceCancion);

 // Getters
 int getId() const;
 std::string getTitulo() const;
 int getAnio() const;
 std::string getEsDeEstudio() const;
 int* getCanciones() const;
 int getNumCanciones() const;
 int getCapacidadCanciones() const;
 Album* getNext() const;
};

#endif // ALBUM_H
