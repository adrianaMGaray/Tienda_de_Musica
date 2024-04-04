#include "AdminTienda.h"

#include "Artista.h"
#include "Cliente.h"

AdminTienda admin("Musiquita C~plus"); //declaracion de la variable global

//Constructores
AdminTienda::AdminTienda(string nombre) : Usuario(nombre) {
    presupuesto = 0;
}

AdminTienda::AdminTienda(string nombre, vector<Artista> art_contratados, vector<Cliente> clientes, double presupuesto)
    : Usuario(nombre) {
    this->art_contratados = art_contratados;
    this->clientes = clientes;
    this->presupuesto = presupuesto;
}



//otros metodos
int AdminTienda::buscar_cliente(Cliente cliente) {
    unsigned int i = 0;
    while (i < clientes.size() && clientes[i] != cliente) {
        i++;
    }
    return i; //si i==clientes.size() significa que el cliente no estaba en la lista
}

string AdminTienda::info_artistas(){
    string resultado = "";
    for(unsigned int i = 0; i<art_contratados.size(); i++)
        resultado+= to_string(i)+"- " + art_contratados[i].getNombre();
    return resultado;
}

unsigned int AdminTienda::buscar_artista(Artista artista) {
    unsigned int i = 0;
    while (i < art_contratados.size() && art_contratados[i] != artista) {
        i++;
    }
    return i; //si i==art_contratados.size() significa que el artista no estaba en la lista
}

void AdminTienda::add_artista(Artista artista) {
    unsigned int i = buscar_artista(artista);
    if (i != art_contratados.size())
        throw runtime_error("Este artista ya estaba contratado");
    else
        art_contratados.push_back(artista);
}

void AdminTienda::del_artista(Artista artista) {
    unsigned int i = buscar_artista(artista);
    if (i == art_contratados.size())
        cout << "Este artista no se encontraba contratado";
    else {
        art_contratados.erase(art_contratados.begin() + i);
        cout << "El artista ha sido dado de baja exitosamente";
    }
}

void AdminTienda::add_cliente(Cliente cliente) {
    unsigned int i = buscar_cliente(cliente);
    if (i != clientes.size())
        cout << "Este cliente ya estaba registrado ";
    else
        clientes.push_back(cliente);
}

void AdminTienda::del_cliente(Cliente cliente) {
    unsigned int i = buscar_cliente(cliente);
    if (i == clientes.size())
        cout << "Este cliente no estaba registrado ";
    else
        clientes.erase(clientes.begin() + i);
    cout << "El cliente ha sido dado de baja exitosamente";
}

void AdminTienda::incrementar_presupuesto(double cantidad) {
    presupuesto += cantidad;
}



//getters y setters
void AdminTienda::setPresupuesto(double presupuesto) {
    this->presupuesto = presupuesto;
}

double AdminTienda::getPresupuesto() {
    return presupuesto;
}

vector<Artista> AdminTienda::getArt_contratados(){
    return art_contratados;
}

vector<Cliente> AdminTienda::getClientes(){
    return clientes;
}

/*string AdminTienda::canciones_a_la_venta(){
    string vendiendo = "";
    unsigned int i = 0;
    while(!art_contratados.empty() && i<art_contratados.size()){
        vendiendo += "Artista: " + art_contratados[i].getNombre() + "\n";
        for(int j = 0; j<art_contratados[i].getAlbumes().size(); i++){
            vendiendo += art_contratados[i].getAlbumes()[j]->getTitulo() + "\n";
            for(int k = 0; k<art_contratados[i].getAlbumes()[j]->getCanciones().size(); k++)
                vendiendo += art_contratados[i].getAlbumes()[j]->getCanciones()[k]->getTitulo();
        }
    }
    return vendiendo;
}*/



