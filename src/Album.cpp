#include "Album.h"

#include "Cancion.h"
#include "Artista.h"


//Constructores
Album::Album(){

}

Album::Album(string titulo, Artista* artista,int anno) :
    titulo(titulo), artista(artista), anno(anno) {
}



//otros metodos
int Album::buscar_cancion(Cancion* cancion) {
    unsigned int i = 0;
    while (i < canciones.size() && canciones[i] != cancion) {
        i++;
    }
    return i; //si i==canciones.size() significa que la cancion no estaba en la lista
}

string Album::info() {
    string informacion = "Titulo: " + titulo + "\n" + "Artista: " + artista->getNombre()
        + "A" + char(164) + "o: " + to_string(anno) + "\n" + to_string(precio())
        + "Canciones: " + "\n";
    for (unsigned int i = 0; i < canciones.size(); i++) {
        informacion += canciones[i]->getTitulo() + "\n";
    }
    return informacion;
}

void Album::add_Cancion(Cancion* cancion) {
    unsigned int i = buscar_cancion(cancion);
    if (i != canciones.size())
        cout << "Esta cancion ya se encuentra en el album\n";
    else
        canciones.push_back(cancion);
}

void Album::del_Cancion(Cancion* cancion) {
    unsigned int i = buscar_cancion(cancion);
    if (i == canciones.size())
        cout << "Esta cancion no se encuentra en el album\n";
    else
        canciones.erase(canciones.begin() + i);
}

double Album::precio() {
    double precio = 0;
    for (unsigned int i = 0; i < canciones.size(); i++) {
        precio += canciones[i]->getPrecio();
    }
    return precio;
}

bool Album::operator==(const Album& album) const {
    bool resultado = true;
    if (titulo != album.getTitulo())
        resultado = false;
    else if (anno != album.getAnno())
        resultado = false;
    return resultado;
}

bool Album::operator!=(const Album& album) const {
    return !(*this == album);
}



//getters y setters
void Album::setTitulo(string titulo) {
    this->titulo = titulo;
}

string Album::getTitulo() {
    return titulo;
}

string Album::getTitulo() const {
    return titulo;
}

void Album::setArtista(Artista* artista) {
    this->artista = artista;
}

string Album::getArtista() {
    return artista->getNombre();
}

string Album::getArtista() const {
    return artista->getNombre();
}

void Album::setAnno(int anno) {
    this->anno = anno;
}

int Album::getAnno() {
    return anno;
}

int Album::getAnno() const {
    return anno;
}

vector<Cancion*> Album::getCanciones(){
    return canciones;
}










