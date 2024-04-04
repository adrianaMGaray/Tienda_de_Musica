#include "Usuario.h"

//Constructores
Usuario::Usuario(){

}

Usuario::Usuario(string nombre) {
    this->nombre = nombre;
}


//otros metodos
string Usuario::info() {
    return nombre + "\n";
}


//getters y setters
void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

string Usuario::getNombre() {
    return nombre;
}
