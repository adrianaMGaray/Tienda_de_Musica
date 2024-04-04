#ifndef CLIENTE_H
#define CLIENTE_H
#include "Librerias.h"
#include "Usuario.h"

#include "AdminTienda.h"
#include "Cancion.h"

class Cliente : public Usuario
{
private:
    vector<Cancion> biblioteca;
    double billetera;

public:
    //Constructores
    Cliente();
    Cliente(string nombre);
    Cliente(string nombre, vector<Cancion> biblioteca, double billetera);

    //otros metodos
    string info();
    string consultar_canciones();
    bool esta_en_biblioteca(Cancion cancion);
    void puntuar_cancion(Cancion cancion, double n);
    void comprar_cancion(Cancion cancion);
    void recargar_billetera(double cantidad);
    bool operator==(const Cliente& cliente) const;
    bool operator!=(const Cliente& cliente) const;

    //getters y setters
    double getBilletera();
    void setBilletera(double billetera);

    void setBiblioteca(vector<Cancion> biblioteca);

private:
    unsigned int buscar_cancion(Cancion cancion);

};

#endif // CLIENTE_H
