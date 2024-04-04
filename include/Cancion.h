#ifndef CANCION_H
#define CANCION_H
#include "Librerias.h"

class Artista;

class Cancion
{
private:
    string titulo;
    double ranking, precio;
    vector<Artista> artistas;


public:
    //Constructores
    Cancion();
    Cancion(string titulo);
    Cancion(string titulo, int cantidad_artistas);
    Cancion(string titulo, vector<Artista> artistas);
    Cancion(string titulo, double ranking, double precio, vector<Artista> artistas);

    //otros metodos
    string info();
    void modificar_ranking(double n);
    void add_artista(Artista artista);
    bool operator==(const Cancion& cancion) const;
    bool operator!=(const Cancion& cancion) const;

    //getters y setters
    string getTitulo();
    void setTitulo(string);

    double getRanking();
    void setRanking(double);

    double getPrecio();
    void setPrecio(double);

    vector<Artista> getArtistas();

private:
    int buscar_artista(Artista artista);

};

#endif // CANCION_H
