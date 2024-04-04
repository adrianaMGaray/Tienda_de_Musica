#ifndef USUARIO_H
#define USUARIO_H
#include "Librerias.h"

class Usuario
{
protected:
    string nombre;

public:
    //Constructores
    Usuario();
    Usuario(string nombre);

    //otros metodos
    string info();

    //getters y setters
    string getNombre();
    void setNombre(string nombre);
};

#endif // USUARIO_H
