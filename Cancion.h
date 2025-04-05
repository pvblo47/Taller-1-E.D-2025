#ifndef CANCION_H
#define CANCION_H

#include <string>

class Cancion {
private:
 int idCancion;
 int albumId;
 std::string titulo;
 long reproducciones;
 std::string duracion; //formato "Min:Seg"

public:
    /**
     * Constructor por defecto
     */
    Cancion();

 Cancion(const std::string &titulo, int reproducciones, const std::string &duracion);

 /**
     *@param idCancion id de la cancion
     * @param albumId Id del album
     * @param titulo //de la canción
     * @param reproducciones //de la canción
     * @param duracion // formato "Min:Seg"
     */
    Cancion( int idCancion, int albumId, const std::string& titulo, int reproducciones, const std::string& duracion);

 /**
  *
  * @return Obtiene el id de cancion
  */
 int getIdCancion();

 /**
  *
  * @return Obtiene el id del album
  */
 int getAlbumId();
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
    std::string getDuracion() const;

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
    void setDuracion(const std::string& duracion);
};

#endif