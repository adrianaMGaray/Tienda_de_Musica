#include "Cancion.h"
#include "Artista.h"


//Constructores
Cancion::Cancion(){

}

Cancion::Cancion(string titulo){
    this->titulo = titulo;
    ranking = 0;
    precio = 2;
}

Cancion::Cancion(string titulo, int cantidad_artistas): artistas(cantidad_artistas){
    this->titulo = titulo;
    ranking = 0;
    precio = 2;
}

Cancion::Cancion(string titulo, vector<Artista> artistas){
    this->titulo = titulo;
    this->artistas = artistas;
    ranking = 0;
    precio = 2;
}

Cancion::Cancion(string titulo, double ranking = 0, double precio = 2, vector<Artista> artistas = {}) :
    titulo(titulo), ranking(ranking), precio(precio), artistas(artistas) {}




//otros metodos
int Cancion::buscar_artista(Artista artista){
    unsigned int i = 0;
    while (i < artistas.size() && artistas[i] != artista) {
        i++;
    }
    return i; //si i==artistas.size() significa que el artista no estaba en la lista
}

string Cancion::info() {
    string informacion = "Titulo: " + titulo + "\n" + "Ranking" + to_string(ranking) + "\n"
        + "Precio: " + to_string(precio) + "\n";
    return informacion;
}

void Cancion::modificar_ranking(double n) {
    ranking = (ranking + n) / 2;
    cout << "Se ha puntuado la cancion con ";
    for (int i = 0; i < n; i++)
        cout << "*";
    cout << " . Gracias por compartir tu opinion!\n";
}

void Cancion::add_artista(Artista artista){
    unsigned int i = buscar_artista(artista);
    if (i != artistas.size())
        cout << "Este artista ya esta annadido\n";
    else
        artistas.push_back(artista);
}

bool Cancion::operator==(const Cancion& cancion) const {
    bool resultado = true;
    if (this->titulo != cancion.titulo)
        resultado = false;
    else if (this->artistas.size() == cancion.artistas.size()) {
        int contador = 0;
        int cantidad = static_cast<int>(cancion.artistas.size());
        while (contador < cantidad && resultado) {
            Artista art = artistas[contador];
            bool tmp = true;
            int i = 0;
            while (i < cantidad) {
                if (art.getNombre() != cancion.artistas[i].getNombre()) // sobrecargar == para Artista
                    tmp = false;
                else
                    tmp = true;
                i++;
            }
            if (tmp == false)
                resultado = false;
            else
                contador++;
        }
    }
    return resultado;
}

bool Cancion::operator!=(const Cancion& cancion) const {
    return !(*this == cancion);
}




//getters y setters
string Cancion::getTitulo() {
    return titulo;
}

void Cancion::setTitulo(string titulo) {
    this->titulo = titulo;
}

double Cancion::getRanking() {
    return ranking;
}

void Cancion::setRanking(double ranking) {
    this->ranking = ranking;
}

double Cancion::getPrecio() {
    return precio;
}

void Cancion::setPrecio(double precio) {
    this->precio = precio;
}

vector<Artista> Cancion::getArtistas(){
    return artistas;
}








