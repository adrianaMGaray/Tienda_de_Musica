#include "Artista.h"
#include "Album.h"


//Constructores
Artista::Artista(){

}

Artista::Artista(string nombre){
    this->nombre = nombre;
}

Artista::Artista(string nombre, string pais) {
    this->nombre = nombre;
    this->pais = pais;
}



//otros metodos
int Artista::buscar_album(Album* album) {
    unsigned int i = 0;
    while (i < albumes.size() && albumes[i] != album) {
        i++;
    }
    return i; //si i==albumes.size() significa que el album no estaba en la lista
}

string Artista::info() {
    string informacion = "Nombre del artista: " + nombre + "\n" + "Pais: " + pais + "\n"
        + "\n" + "Albumes: " + "\n";
    for (unsigned int i = 0; i < albumes.size(); i++) {
        informacion += albumes[i]->getTitulo() + "\n";
    }
    return informacion;
}

void Artista::add_album(Album* album) {
    unsigned int i = buscar_album(album);
    if (i != albumes.size())
        cout << "El album ya estaba registrado";
    else
        albumes.push_back(album);
}

void Artista::incrementar_recaudacion(double n) {
    recaudacion += n;
}

bool Artista::operator==(const Artista& artista) const {
    return this->nombre == artista.nombre;
}

bool Artista::operator!=(const Artista& artista) const {
    return !(*this == artista);
}



//getters y setters
void Artista::setNombre(string nombre) {
    this->nombre = nombre;
}

string Artista::getNombre() {
    return nombre;
}

string Artista::getNombre() const {
    return nombre;
}

void Artista::setPais(string pais) {
    this->pais = pais;
}

string Artista::getPais() {
    return pais;
}

void Artista::setRecaudacion(double recaudacion){
    this->recaudacion = recaudacion;
}

double Artista::getRecaudacion(){
    return recaudacion;
}

vector<Album*> Artista::getAlbumes(){
    return albumes;
}
