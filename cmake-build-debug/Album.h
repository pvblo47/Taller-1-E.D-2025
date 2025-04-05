//
// Created by ulloc on 29-03-2025.
//

#ifndef ALBUM_H
#define ALBUM_H
#include <string>


class Album {

private:
    /**
     * Atributo que define el identificador único deL album.
     *
     */
    int id;
    /**
     * Atributo que define el título de un album.
     */
    std::string titulo;

    /**
     * Atributo que define el año de publicación de un album.
     */
    int anio;

    /**
     * Atributo que define si el album está grabado en estudio o en vivo.
     */
    std::string esDeEstudio;
    //ArregloDinamico canciones;

    public:
    /**
     * Constructor del objeto tipo album
     * @param id del album
     * @param titulo del album
     * @param anio del album
     * @param esDeEstudio (Sí o No)
     */
    Album(int id, const std::string& titulo, int anio, const std::string& esDeEstudio);

    /**
     * Constructor por defecto del objeto tipo album
     */
    Album();
    /**
     * Destructor del objetio tipo album
     */
    ~Album() = default;

    [[nodiscard]] int getId() const {
     return id;
    }

    [[nodiscard]] std::string getTitulo() const {
     return titulo;
    }

    [[nodiscard]] int getAnio() const {
     return anio;
    }

    [[nodiscard]] std::string getEsDeEstudio() const {
     return esDeEstudio;
    }
};



#endif //ALBUM_H
