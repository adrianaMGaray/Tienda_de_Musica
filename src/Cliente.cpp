#include "Cliente.h"

#include "Artista.h"

//Constructores
Cliente::Cliente() : Usuario(){
    billetera = 5;
}

Cliente::Cliente(string nombre)
    : Usuario(nombre) {
    billetera = 5;
}

Cliente::Cliente(string nombre, vector<Cancion> biblioteca, double billetera) :
    Usuario(nombre) {
    this->biblioteca = biblioteca;
    this->billetera = billetera;
}


//otros metodos
unsigned int Cliente::buscar_cancion(Cancion cancion) {
    unsigned int i = 0;
    while (i < biblioteca.size() && biblioteca[i] != cancion) {
        i++;
    }
    return i; //si i==biblioteca.size() significa que la cancion no estaba en la lista
}

string Cliente::info() {
    string new_info = Usuario::info() + "Dinero actual en la billetera: " + to_string(billetera) + "\n"
        + "Cantidad de canciones compradas: " + to_string(biblioteca.size()) + "\n";
    return new_info;
}

string Cliente::consultar_canciones() {
    string resultado;
    if(biblioteca.empty())
        resultado = "Su biblioteca esta vacia actualmente \n";
    else {
     resultado = "Canciones en la biblioteca: ";
    for (unsigned int i = 0; i < biblioteca.size(); i++)
        resultado += biblioteca[i].getTitulo() + "\n";
    }
    return resultado;
}

bool Cliente::esta_en_biblioteca(Cancion cancion) {
    if (buscar_cancion(cancion) == biblioteca.size())
        return false;
    else
        return true;
}

void Cliente::puntuar_cancion(Cancion cancion, double n) {
    cancion.modificar_ranking(n);
}

void Cliente::comprar_cancion(Cancion cancion) {
    unsigned int i = buscar_cancion(cancion);
    if (i != biblioteca.size())
        cout << "Ya tiene esta cancion en su biblioteca!\n";
    else if ((billetera - cancion.getPrecio()) < 0)
        cout << "El dinero en su billetera no es suficiente :( Siempre puede recargar y volver a intentarlo!\n";
    else {
        billetera -= cancion.getPrecio();
        admin.incrementar_presupuesto(0.3 * cancion.getPrecio());
        double dinero_a_repartir = (0.7 * cancion.getPrecio()) / cancion.getArtistas().size();
        for (unsigned int i = 0; i < cancion.getArtistas().size(); i++)
            cancion.getArtistas()[i].incrementar_recaudacion(dinero_a_repartir);
        biblioteca.push_back(cancion);
        cout << cancion.getTitulo() << " ha sido a" << (char)164 << "adida a tu biblioteca\n";
    }
}

void Cliente::recargar_billetera(double cantidad) {
    billetera += cantidad;
}

bool Cliente::operator==(const Cliente& cliente) const {
    return this->nombre == cliente.nombre;
}

bool Cliente::operator!=(const Cliente& cliente) const {
    return !(*this == cliente);
}


//getters y setters
double Cliente::getBilletera(){
    return billetera;
}

void Cliente::setBilletera(double billetera){
    this->billetera = billetera;
}

void Cliente::setBiblioteca(vector<Cancion> biblioteca){
    this->biblioteca = biblioteca;
}

