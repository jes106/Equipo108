
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include "Funciones.h"
using namespace std;


void identificar_usuario(string *nick, string *password){
    cout << "/-----------------------------------------------/" << endl;
    cout << "/           IDENTIFICACION DE USUARIO           /" << endl;
    cout << "/-----------------------------------------------/" << endl;

    cout << "Nickname -> ";
    getline(cin, *nick);
    cout << "Password -> ";
    getline(cin, *password);

}

int comprueba_login(Usuario *usuario){
    Usuario aux;
    int encontrado = 0;                                                        //Variable que indica si el usuario esta o no en la base de datos.

    string filename = "BASE_DE_DATOS.txt";
    fstream fichero(filename, ios::in);                                         //Abrimos el fichero en modo entrada(lectura)
    if(!fichero){
        cout << "Error al abrir el fichero" << endl;
        exit(-1);
    }

    while(fichero >> aux.nick && encontrado == 0){
        fichero >> aux.password;
        fichero >> aux.tipo;
    }

    if(usuario->nick != aux.nick && usuario->password != aux.password){
            cout << "No se encuentra registrado en la Base de Datos. Debe comunicarse con un administrador para que lo registre." << endl;
            encontrado = 0;
    }
    else{ encontrado = 1; }

    *usuario = aux;
    return encontrado;   
}

void menuAdmin1(int *opcion){
    cout << "/------------------------------------------------/" << endl;
    cout << "/             MENU - ADMINISTRADOR 1             /" << endl;
    cout << "/------------------------------------------------/" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Crear Usurio." << endl;
    cout << "2. Actualizar Usuario." << endl;
    cout << "Selecciones una opcion:";
    cin >> *opcion;
    cin.ignore();                                  //Tenemos que limpiar el buffer despues de un cin para que no se quede almacenado un "\n"
}
void menuAdmin2(int *opcion){
    cout << "/------------------------------------------------/" << endl;
    cout << "/             MENU - ADMINISTRADOR 2             /" << endl;
    cout << "/------------------------------------------------/" << endl;
    cout << "0. Salir" << endl;
    cout << "3. Añadir Maquinas." << endl;
    cout << "4. Actualizar Maquinas." << endl;
    cout << "Selecciones una opcion:";
    cin >> *opcion;
    fflush(stdin);                                  //Tenemos que limpiar el buffer despues de un cin para que no se quede almacenado un "\n"
}
void menuUsuario(int *opcion){
    cout << "/------------------------------------------------/" << endl;
    cout << "/                 MENU - Usuario                 /" << endl;
    cout << "/------------------------------------------------/" << endl;
    cout << "0. Salir" << endl;
    cout << "5. Crear Reserva." << endl;
    cout << "6. Actualizar Reserva." << endl;
    cout << "Selecciones una opcion:";
    cin >> *opcion;
    fflush(stdin);                                  //Tenemos que limpiar el buffer despues de un cin para que no se quede almacenado un "\n"
    
}

void crearUsuario(){
    Usuario aux;

    //Pedimos al administrador que introduzca los datos del cliente.
    cout << "Introduce nick -> ";
    getline(cin, aux.nick);
    cout << "Introduce password -> ";
    getline(cin, aux.password);
    cout << "Tipos de Usuario:\n\tAdminitrador 1 = 1\n\tAdministrador 2 = 2\n\tUsuario = 3" << endl;
    cout <<  "Introduce el tipo de usuario -> ";
    cin >> aux.tipo;

    fstream fichero("BASE_DE_DATOS.txt", ios::app);
    if(!fichero){                                                        //Comprobamos que el fichero se ha abierto correctamente
        cout << "ERROR. Error al abrir el fichero." << endl;
        exit(-1);
    }

    fichero << aux.nick << "\t" << aux.password << "\t" << aux.tipo << endl;
    cout << "Usuario añadido con exito." << endl;
}

void actualizaUsuario(){
}











