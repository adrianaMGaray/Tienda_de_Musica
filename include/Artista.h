#ifndef ARTISTA_H
#define ARTISTA_H
#include "Librerias.h"

class Album;

class Artista
{
private:
    string nombre, pais;
    vector<Album*> albumes;
    double recaudacion;

public:
    //Constructores
    Artista();
    Artista(string nombre);
    Artista(string nombre, string pais);

    //otros metodos
    string info();
    void add_album(Album* album);
    void incrementar_recaudacion(double n);
    bool operator==(const Artista& artista) const;
    bool operator!=(const Artista& artista) const;

    //getters y setters
    string getNombre();
    string getNombre() const;
    void setNombre(string nombre);

    string getPais();
    void setPais(string pais);

    double getRecaudacion();
    void setRecaudacion(double recaudacion);

    vector<Album*> getAlbumes();

private:
    int buscar_album(Album* album);

};

#endif // ARTISTA_H
