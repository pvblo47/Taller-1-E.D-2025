#ifndef ARREGLOCANCIONES_H
#define ARREGLOCANCIONES_H

#include "Cancion.h"

class ArregloCanciones {
private:
 Cancion* canciones;
 int numCanciones;
 int capacidadCanciones;

 void expandir(); // Expande el arreglo si se llena

public:
 ArregloCanciones();
 ~ArregloCanciones();

 void agregarCancion(const Cancion& nuevaCancion);
 void leerArchivoCanciones(const std::string& nombreArchivo);

 Cancion *getCancionPorIndice(int indice);

 Cancion* getCanciones() const;
 int getNumCanciones() const;
};

#endif
