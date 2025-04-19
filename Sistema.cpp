#include "Sistema.h"
#include <iostream>
#include <set>
#include <vector>

void Sistema::iniciar() {
    std::cout << "Iniciando el sistema..." << std::endl;

    try {
        // Intentar leer los archivos
        std::cout << "Leyendo archivo de canciones..." << std::endl;
        canciones.leerArchivoCanciones("canciones.csv");
        std::cout << "Archivo de canciones leído correctamente." << std::endl;

        std::cout << "Leyendo archivo de álbumes..." << std::endl;
        listaAlbumes.leerArchivoAlbumes("albumes.csv");
        std::cout << "Archivo de álbumes leído correctamente." << std::endl;

        mostrarMenu();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl; // Mostrar el mensaje de error
    }
}

void Sistema::mostrarMenu() {
    int opcion;
    do {
        std::cout << "\n--- Menú Principal ---\n";
        std::cout << "1. Mostrar álbum\n";
        std::cout << "2. Búsqueda avanzada de canciones\n";
        std::cout << "3. Eliminar álbum\n";
        std::cout << "4. Trivia\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                int id;
            std::cout << "Ingrese el id: ";
            std::cin >> id;
                mostrarAlbumPorId(id);
                break;
            case 2:
                busquedaAvanzada();
                break;
            case 3:
                eliminarAlbum();
                break;
            case 4:
                jugarTrivia();
                break;
            case 5:
                salir();
                break;
            default:
                std::cout << "Opción no válida.\n";
        }
    } while (opcion != 5);
}

void Sistema::mostrarAlbumPorId(int idBuscado) {
    Album* aux = listaAlbumes.getHead();  // Obtiene el primer nodo de la lista

    while (aux != nullptr) {
        if (aux->id == idBuscado) {
            std::cout << "Álbum encontrado:" << std::endl;
            std::cout << "ID: " << aux->id << std::endl;
            std::cout << "Título: " << aux->titulo << std::endl;
            std::cout << "Año: " << aux->anio << std::endl;
            std::cout << "Es de estudio: " << aux->esDeEstudio << std::endl;
            std::cout << "Canciones:" << std::endl;

            for (int i = 0; i < aux->numCanciones; ++i) {
                int idCancion = aux->canciones[i];

                for (int j = 0; j < canciones.getNumCanciones(); ++j) {
                    if (canciones.getCancionPorIndice(j)->getIdCancion() == idCancion) {
                        std::cout << "  - " << canciones.getCancionPorIndice(j)->getTitulo() << std::endl;
                        break;
                    }
                }
            }
            return;
        }
        aux = aux->next;
    }

    std::cout << "Álbum con ID " << idBuscado << " no encontrado." << std::endl;
}

void Sistema::busquedaAvanzada() {
    std::vector<Cancion*> cancionesFiltradas;

    // 1. Partimos con todas las canciones
    for (int i = 0; i < canciones.getNumCanciones(); ++i) {
        cancionesFiltradas.push_back(canciones.getCancionPorIndice(i));
    }

    // a. Filtro por rango de años
    std::string opcion;
    std::cout << "\n¿Deseas aplicar filtro por rango de años? (si/no): ";
    std::cin >> opcion;
    if (opcion == "Si" || opcion == "si") {
        int anio1;
        int anio2;
        std::cout << "Ingresa el año inicial: ";
        std::cin >> anio1;
        std::cout << "Ingresa el año final: ";
        std::cin >> anio2;

        if (anio2 < anio1) std::swap(anio1, anio2); // para ordenar siempre de forma ascendente

        std::vector<Cancion*> filtradasTemp;
        for (int i = 0; i < cancionesFiltradas.size(); ++i) {
            Cancion* cancion = cancionesFiltradas[i];
            Album* album = listaAlbumes.buscarAlbumPorId(cancion->getAlbumId());
            if (album && album->anio >= anio1 && album->anio <= anio2) {
                filtradasTemp.push_back(cancion);
            }
        }
        cancionesFiltradas = filtradasTemp;
    }

    // b. Filtro por álbum
    std::cout << "\n¿Deseas aplicar filtro por álbum? (si/no): ";
    std::cin >> opcion;
    if (opcion == "Si" || opcion == "si") {
        std::cout << "Álbumes disponibles tras filtro anterior:\n";
        std::set<int> idsMostrados; //para evitar mostrar albumes duplicados
        for (int i = 0; i < cancionesFiltradas.size(); ++i) {
            Cancion* cancion = cancionesFiltradas[i];
            if (!idsMostrados.count(cancion->getAlbumId())) { // "count" devuelve 0 si el ID no está en el set.
                Album* album = listaAlbumes.buscarAlbumPorId(cancion->getAlbumId());
                if (album) { // Si el álbum existe
                    std::cout << "ID: " << album->id << " - Título: " << album->titulo << "\n";
                    idsMostrados.insert(album->id); // se inserta el ID del álbum en el set para que no se repita.

                }
            }
        }

        int idElegido;
        std::cout << "Ingresa el ID del álbum a filtrar: ";
        std::cin >> idElegido;

        std::vector<Cancion*> filtradasTemp;
        for (int i = 0; i < cancionesFiltradas.size(); ++i) {
            Cancion* cancion = cancionesFiltradas[i];
            if (cancion->getAlbumId() == idElegido) {
                filtradasTemp.push_back(cancion);
            }
        }
        cancionesFiltradas = filtradasTemp;
    }

    // Mostrar resultados
    std::cout << "\nResultados:\n";
    for (int i = 0; i < cancionesFiltradas.size(); ++i) {
        Cancion* cancion = cancionesFiltradas[i];
        Album* album = listaAlbumes.buscarAlbumPorId(cancion->getAlbumId());
        if (album) {
            std::cout << "Título: " << cancion->getTitulo()<< " | Álbum: " << album->getTitulo()<< " | Duración: " << cancion->getDuracion() << "\n";
        }
    }
}



void Sistema::eliminarAlbum() {

}

void Sistema::jugarTrivia() {

}

void Sistema::salir() {

}