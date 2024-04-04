#ifndef ALBUM_H
#define ALBUM_H
#include "Librerias.h"

class Cancion;
class Artista;

class Album
{
private:
    string titulo;
    Artista* artista;
    vector<Cancion*> canciones;
    int anno;

public:
    //Constructores
    Album();
    Album(string titulo, Artista* artista, int anno);

    //otros metodos
    string info();
    void add_Cancion(Cancion* cancion);
    void del_Cancion(Cancion* cancion);
    double precio();
    bool operator==(const Album& album) const;
    bool operator!=(const Album& album) const;

    //getters y setters
    string getTitulo() const;
    string getTitulo();
    void setTitulo(string Titulo);

    string getArtista() const;
    string getArtista();
    void setArtista(Artista* artista);

    int getAnno();
    void setAnno(int anno);
    int getAnno() const;

    vector<Cancion*> getCanciones();

private:
    int buscar_cancion(Cancion* cancion);

};

#endif // ALBUM_H
