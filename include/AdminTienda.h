#ifndef ADMINTIENDA_H
#define ADMINTIENDA_H
#include "Librerias.h"
#include "Usuario.h"

class Artista;
class Cliente;

class AdminTienda : public Usuario
{
private:
    vector<Artista> art_contratados;
    vector<Cliente> clientes;
    double presupuesto;

public:
    //Constructores
    AdminTienda(string nombre);
    AdminTienda(string nombre, vector<Artista> art_contratados, vector<Cliente> clientes, double presupuesto);

    //otros metodos
    string info_artistas();
    unsigned int buscar_artista(Artista artista);
    void add_artista(Artista artista);
    void del_artista(Artista artista);
    void add_cliente(Cliente cliente);
    void del_cliente(Cliente cliente);
    void incrementar_presupuesto(double cantidad);

    //getters y setters
    double getPresupuesto();
    void setPresupuesto(double presupuesto);

    vector<Artista> getArt_contratados();

    vector<Cliente> getClientes();

private:
    int buscar_cliente(Cliente cliente);


};

extern AdminTienda admin;

#endif // ADMINTIENDA_H
