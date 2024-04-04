#include "../Librerias.h"
#include "AdminTienda.h"
#include "Cliente.h"
#include "Usuario.h"
#include "Cancion.h"
#include "Artista.h"
#include "Album.h"

#include <conio.h>
#include <iomanip> // para stdw(n)
#include <cctype> //Necesario para las excepciones
#include <fstream> //para lectura de fichero
#include <stdexcept> // Necesario para las excepciones
#include <sstream>
#include <functional> //para las funciones lambda

#define ANNO_ACTUAL 2024

//FUNCIONES AUXILIARES
void print_centrado(const string& text);
string mensaje_excepcion();
void leer_fichero(string nombre);

//FUNCIONES PARA EL MANEJO DE EXCEPCIONES
int convertir_a_int(const string& cadena, const function<bool(int)>& validar);
double convertir_a_double(const string& cadena, const function<bool(double)>& validar);

//MENUS
void menu_Usuario();
void menu_Cliente();
void menu_Admin();

void menuPrincipal();
void menuCliente();
void menuAdministrador();

void menuPrincipal(){
    string entrada;
    int opcion_num;

    system("cls");
    print_centrado("Bienvenido a Musiquita C~Plus!");
    cout<<"Inicie sesion para continuar \n";
    cout<<"1- Cliente \n" ;
    cout<<"2- Administrador \n";
    cout<<"0- Salir \n\n";

    cout<<"Por favor, introduce un numero: ";
    cin>>entrada;
    try{
        opcion_num = convertir_a_int(entrada, [](int numero) -> bool { return (numero == 0 || numero == 1 || numero == 2); });
    }
    catch(const invalid_argument&) {
        cerr << mensaje_excepcion();
        menuPrincipal();
    }

    switch(opcion_num){
        case 1:
        {
            menuCliente();
            break;
        }
        case 2:
        {
            menuAdministrador();
            break;
        }
        case 0:
        {
            exit(1);
        }
        default:
            menuPrincipal();
    }
}

void menuCliente(){
    string nombre_cliente;
    string nombre_cancion;
    string nombre_artista;
    string pais_artista;
    string titulo_album;
    string titulo_cancion;
    Cliente cliente1;

    string entrada;
    int opcion_num;
    double valor;

    cout<<"Introduzca su nombre: \n";
    cin>>nombre_cliente;
    cliente1.setNombre(nombre_cliente);
    admin.add_cliente(nombre_cliente);


    bool bucle = true;
    while (bucle){
        system("cls");
        cout<<"Bien! Ahora puede comenzar a disfrutar de nuestros servicios, "<<nombre_cliente<<" :D \n";
        cout << "\n";
        menu_Cliente();

        bool exito = false;
        while(!exito){
            cout<<"Por favor, introduce un numero: ";
            cin>>entrada;
            try{
                opcion_num = convertir_a_int(entrada, [](int num) -> bool {return num > -1 && num <= 4;});
                exito = true;
            }
            catch(const invalid_argument&) {
                cerr << mensaje_excepcion();
                getch();
            }
        }
        exito = false;

        switch(opcion_num){
            case 1:
                {
                cout<<cliente1.consultar_canciones()<<"\n\n";
                getch();
                break;
                }
            case 2:
                {
                cout<<"Escriba el nombre de la cancion que desea puntuar\n";
                cin>>nombre_cancion;
                Cancion cancion1(nombre_cancion);
                if(!cliente1.esta_en_biblioteca(cancion1))
                    cout<<"Esta cancion no esta en tu biblioteca. Intenta annadirla prilmero\n\n";
                else{
                    while(!exito){
                        cout<<"Introduzca cuantas estrellas desea otorgarle (un # del 0 al 5)\n";
                        cin>>entrada;
                        try{
                            opcion_num = convertir_a_int(entrada, [](int num) -> bool {return num > 0 && num <= 5;});
                            exito = true;
                        }
                        catch(const invalid_argument& e){
                            cerr << mensaje_excepcion();
                        }
                    }
                    cliente1.puntuar_cancion(cancion1, opcion_num);
                }
                getch();
                break;
                }
            case 3:
                {
                cout<<"Escriba el nombre de la cancion que busca\n";
                cin>>nombre_cancion;

                while(!exito){
                    cout<<"Escriba cuantos artistas son sus autores\n";
                    cin>>entrada;
                    try{
                        opcion_num = convertir_a_int(entrada, [](int num) -> bool {return num > 0 && num <= 5;});
                        exito = true;
                    }
                    catch(const invalid_argument& e){
                        cerr << mensaje_excepcion();
                    }
                }

                Cancion cancion2(nombre_cancion, opcion_num);
                cout<<"Escriba el nombre de uno de sus artistas\n";
                cin>>nombre_artista;
                Artista artista2(nombre_artista);
                opcion_num = admin.buscar_artista(artista2);
                if(opcion_num == admin.getArt_contratados().size())
                    cout<<"Lamentablemente no tenemos ese artista registrado\n\n";
                else
                    cliente1.comprar_cancion(cancion2);

                getch();
                break;
                }
            case 4:
                {
                while(!exito){
                    cout<<"Introduzca la cantidad de dinero que quiere depositar en su billetera: \n";
                    cin>>entrada;
                    try{
                        valor = convertir_a_double(entrada,[](double num) -> bool {return num > 0;});
                        exito = true;
                    }
                    catch(const invalid_argument&) {
                        cerr << mensaje_excepcion();
                    }
                }

                cliente1.recargar_billetera(valor);
                cout<<"\n";
                cout<<"Todo bien :D . Su saldo actual es "<<cliente1.getBilletera()<<"\n\n";
                getch();

                break;
                }
            case 0:
                bucle = false;
                break;
        }

    }

    menuPrincipal();
}

void menuAdministrador(){
    string nombre_cliente;
    string nombre_cancion;
    string nombre_artista;
    string pais_artista;
    string titulo_album;
    string titulo_cancion;
    Cliente cliente1;

    string entrada;
    int opcion_num;
    double valor;

    system("cls");
    menu_Admin();
    bool exito = false;
    while(!exito){
        cout<<"Por favor, introduce un numero: ";
        cin>>entrada;
        try{
            opcion_num = convertir_a_int(entrada, [](int num) -> bool {return num >= 0 && num <= 2;});
            exito = true;
        }
        catch(const invalid_argument&) {
            cerr << mensaje_excepcion();
        }
    }
    exito = false;
    switch(opcion_num){
        case 1:
            {
            cout<<"Introduzca el nombre del artista: \n";
            cin>>nombre_artista;
            cout<<"Introduzca el pais del artista: \n";
            cin>>pais_artista;
            Artista* artista3 = new Artista (nombre_artista, pais_artista);
            cout<<"Que album desea annadirle?\n";
            cin>>titulo_album;

            while(!exito){
                cout<<"Anno de este album: \n";
                cin>>entrada;
                try{
                    opcion_num = convertir_a_int(entrada, [](int num) -> bool {return num > 1200 && num <= ANNO_ACTUAL;});
                    exito = true;
                }
                catch(const invalid_argument&) {
                    cerr << mensaje_excepcion();
                }
            }
            exito = false;
            Album* album3 = new Album(titulo_album, artista3, opcion_num);
            artista3->add_album(album3);

            while(!exito){
                cout<<"Cuantas canciones desea annadirle?\n";
                cin>>entrada;
                try{
                    opcion_num = convertir_a_int(entrada, [](int num) -> bool {return num > 0 && num <= 30;});
                    exito = true;
                }
                catch(const invalid_argument&) {
                    cerr << mensaje_excepcion();
                }
            }
            exito = false;
            for(int i = 0; i<opcion_num; i++){
                Cancion* cancion3 = new Cancion();
                cout<<"Introduzca el nombre de la cancion\n";
                cin>>titulo_cancion;
                cancion3->setTitulo(titulo_cancion);
                cout<<"\n";

                while(!exito){
                    cout<<"Introduzca el precio de la cancion\n";
                    cin>>entrada;
                    try{
                        valor = convertir_a_double(entrada,[](double num) -> bool {return num > 0 && num <= 30;});
                        exito = true;
                    }
                    catch(const invalid_argument&) {
                        cerr << mensaje_excepcion();
                    }
                }
                exito = false;
                cancion3->setPrecio(valor);
                cout<<"\n";
                album3->add_Cancion(cancion3);
            }
            admin.add_artista(*artista3);
            cout<<"El proceso ha terminado exitosamente!\n";
            getch();
            break;
        }
        case 2:
            {
            cout<<"Introduzca el nombre del cliente\n";
            cin>>nombre_cliente;
            Cliente cliente3(nombre_cliente);
            admin.add_cliente(cliente3);
            cout<<"El proceso ha terminado exitosamente!\n\n";
            getch();
            break;
            }
        case 0:
            break;
        default:
            menuAdministrador();
    }

    menuPrincipal();
}

int main(){

    leer_fichero("artistas.txt");

    cout << "\n";

    menuPrincipal();

    return 0;
}

//DEFINICIONES DE LAS FUNCiONES

void print_centrado(const string& text) {
    int text_length = text.length();
    int total_ancho = text_length + 10;
    int espacio;
    if((total_ancho-text_length)%2 != 0)
        total_ancho++;
    espacio = (total_ancho-text_length)/2;


    for(int i = 0; i < total_ancho; i++)
        cout << "*";
    cout << "\n";

    cout << "*" << setw(espacio) << "" << text << setw(espacio-2) << "" << "*";
    cout << "\n";

    for(int i = 0; i < total_ancho; i++)
        cout << "*";
    cout << "\n";
}


string mensaje_excepcion(){
    string resultado = "Error: La cadena no es un numero valido o el numero no cumple con la condicion requerida\n\n";
    return resultado;
}

void leer_fichero(string nombre){
    try {
        ifstream archivo(nombre);
        if (!archivo.is_open()) {
            throw runtime_error("Error al abrir el archivo");
        }
        vector<Artista> artista;
        string linea;
        while (getline(archivo, linea)) {
            Artista* artista = new Artista();
            artista->setNombre(linea); //linea 1
            getline(archivo, linea); //linea 2
            artista->setPais(linea); //linea 2
            Album* album = new Album();
            artista->add_album(album);
            getline(archivo, linea); //linea 3
            album->setTitulo(linea); //linea 3
            album->setArtista(artista);
            getline(archivo, linea); //linea 4
            int anno = stoi(linea);
            album->setAnno(anno); //linea 4
            getline(archivo, linea); //linea 5
            unsigned int cantidad_canciones = stoul(linea);
            vector<Artista> lista_artista;
            lista_artista.push_back(*artista);
            for (unsigned int i = 0; i < cantidad_canciones; i++) {
                getline(archivo, linea);
                Cancion* cancion = new Cancion(linea, lista_artista);
                artista->getAlbumes()[0]->add_Cancion(cancion);
            }
            getline(archivo, linea);
            admin.add_artista(*artista);
        }
        archivo.close();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void menu_Cliente(){
    cout<<"1- Consultar las canciones en su biblioteca\n";
    cout<<"2- Puntuar una cancion\n";
    cout<<"3- Comprar cancion\n";
    cout<<"4- Recargar billetera\n";
    cout<<"0- Salir\n";
}

void menu_Admin(){
    cout<<"1- Registrar un nuevo artista\n";
    cout<<"2- Registrar un nuevo cliente\n";
    cout<<"0- Salir\n";
}

int convertir_a_int(const string& cadena, const function<bool(int)>& validar) {
    stringstream ss(cadena);
    int numero;
    if ((ss >> numero).fail() || !(ss >> ws).eof()) {
        throw invalid_argument("La cadena no es un numero valido");
    }
    if (!validar(numero)) {
        throw invalid_argument("El numero no cumple con la condicion requerida");
    }
    return numero;
}

double convertir_a_double(const string& cadena, const function<bool(double)>& validar) {
    stringstream ss(cadena);
    double numero;
    if ((ss >> numero).fail() || !(ss >> ws).eof()) {
        throw invalid_argument("La cadena no es un numero valido");
    }
    if (!validar(numero)) {
        throw invalid_argument("El numero no cumple con la condicion requerida");
    }
    return numero;
}
