#ifndef CANCION_H
#define CANCION_H

#include <string>

class Cancion {
private:
 int idCancion;
 int albumId;
 std::string titulo;
 int reproducciones;
 int duracion; //formato "segundos"

public:
    /**
     * Constructor por defecto
     */
    Cancion();



 /**
     *@param idCancion id de la cancion
     * @param albumId Id del album
     * @param titulo //de la canción
     * @param reproducciones //de la canción
     * @param duracion // duracion en segundos
     */
    Cancion( int idCancion, int albumId, const std::string& titulo, int reproducciones, int duracion);

 /**
  *
  * @return Obtiene el id de cancion
  */
 int getIdCancion() const;

 /**
  *
  * @return Obtiene el id del album
  */
 int getAlbumId() const;
    /**
     * 
     * @return/ Obtiene el título de la cancion
     */
    std::string getTitulo() const;

    /**
     * 
     * @return Obtiene las reproducciones de la cancion
     */
    int getReproducciones() const;

    /**
     * 
     * @return Obtiene la duración de la canción
     */
    int getDuracion() const;

    /**
     * 
     * @param titulo Cambia el título
     */
    void setTitulo(const std::string& titulo);

    /**
     * 
     * @param reproducciones Cambia las reproducciones
     */
    void setReproducciones(int reproducciones);

    /**
     * 
     * @param duracion Cambia la duracion
     */
    void setDuracion(int duracion);


};

#endif